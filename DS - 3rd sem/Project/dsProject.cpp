#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <cstdio>
#include <iomanip> // Added for table formatting
#include <limits>  // Added for input buffer clearing

using namespace std;

const int inf = 1000000;

// --- UI Helper Section ---
namespace UI {
    // ANSI Color Codes
    const string RESET = "\033[0m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string BLUE = "\033[34m";
    const string MAGENTA = "\033[35m";
    const string CYAN = "\033[36m";
    const string BOLD = "\033[1m";

    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    void printHeader(string title) {
        cout << "\n" << CYAN << BOLD << "========================================" << RESET << endl;
        cout << "  " << title << endl;
        cout << CYAN << BOLD << "========================================" << RESET << endl;
    }

    void printError(string msg) {
        cout << RED << "[!] Error: " << msg << RESET << endl;
    }

    void printSuccess(string msg) {
        cout << GREEN << "[*] Success: " << msg << RESET << endl;
    }

    void printWarning(string msg) {
        cout << YELLOW << "[?] Warning: " << msg << RESET << endl;
    }

    void pressEnterToContinue() {
        cout << "\n" << MAGENTA << "Press Enter to continue..." << RESET;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}

class course;

template <typename key, typename value>
class hashmap {
private:
    class entry {
    public: 
        key key_val;
        value value_val;
    };

    vector<vector<entry>> buckets;
    size_t size_count = 0;
    
    static const size_t bucket_count = 10; 

    size_t hash(const key& k) const {
        size_t hash_val = 0;
        for (char c : k) hash_val = hash_val * 31 + c;
        return hash_val % bucket_count;
    }

public:
    hashmap() : buckets(bucket_count) {}

    void insert(const key& k, const value& v) {
        size_t index = hash(k);
        for (size_t i = 0; i < buckets[index].size(); i++) {
            if (buckets[index][i].key_val == k) {
                buckets[index][i].value_val = v; 
                return;
            }
        }
        buckets[index].push_back({k, v});
        size_count++;
    }

    value& operator[](const key& k) {
        size_t index = hash(k);
        for (size_t i = 0; i < buckets[index].size(); i++) {
            if (buckets[index][i].key_val == k) return buckets[index][i].value_val;
        }
        buckets[index].push_back({k, value{}}); 
        size_count++;
        return buckets[index].back().value_val;
    }

    size_t count(const key& k) const {
        size_t index = hash(k);
        for (size_t i = 0; i < buckets[index].size(); i++) {
            if (buckets[index][i].key_val == k) return 1;
        }
        return 0;
    }
    
    size_t size() const { return size_count; }

    class iterator {
    public:
        typename vector<vector<entry>>::iterator bucket_it;
        typename vector<entry>::iterator entry_it; 
        typename vector<vector<entry>>::iterator bucket_end;

        iterator(typename vector<vector<entry>>::iterator b_it, typename vector<vector<entry>>::iterator b_end)
            : bucket_it(b_it), bucket_end(b_end) 
        {
            while (bucket_it != bucket_end && bucket_it->empty()) ++bucket_it;
            if (bucket_it != bucket_end) entry_it = bucket_it->begin();
        }

        iterator(typename vector<vector<entry>>::iterator b_end) : bucket_it(b_end), bucket_end(b_end) {}
        
        pair<const key, value&> operator*() { return {entry_it->key_val, entry_it->value_val}; }

        iterator& operator++() {
            ++entry_it;
            if (entry_it == bucket_it->end()) {
                do { ++bucket_it; } while (bucket_it != bucket_end && bucket_it->empty());
                if (bucket_it != bucket_end) entry_it = bucket_it->begin();
            }
            return *this;
        }
        bool operator!=(const iterator& other) const { return bucket_it != other.bucket_it; }
    };

    iterator begin() { return iterator(buckets.begin(), buckets.end()); }
    iterator end() { return iterator(buckets.end()); }
};

template <typename key, typename value>
const size_t hashmap<key, value>::bucket_count; 

using coursedb = hashmap<string, course>;
using grademap = hashmap<string, double>;

class course {
public:
    string id, name;
    int difficulty, credits;
    vector<pair<string, int>> adjacentcourses; 

    course(string i, string n, int d, int c) : id(i), name(n), difficulty(d), credits(c) {}
    course() {}
};

class student {
public:
    string name, semester;
    grademap completedcourses; 

    student() { name = "Guest"; semester = "1st"; }

    double calculatecgpa(coursedb& coursedb_ref) {
        double totalpoints = 0;
        int totalcredits = 0;
        for (auto const& p : completedcourses) { 
            if (coursedb_ref.count(p.first)) {
                int creds = coursedb_ref[p.first].credits;
                totalpoints += (p.second * creds);
                totalcredits += creds;
            }
        }
        return (totalcredits == 0) ? 0.0 : totalpoints / totalcredits;
    }
    
    void displaytranscript(coursedb& coursedb_ref) {
        UI::printHeader("Transcript: " + name);
        
        cout << left << setw(10) << "ID" 
             << setw(30) << "Course Name" 
             << setw(10) << "Credits" 
             << setw(10) << "Grade" << endl;
        cout << UI::CYAN << "------------------------------------------------------------" << UI::RESET << endl;

        for (auto const& p : completedcourses) {
            if (coursedb_ref.count(p.first)) {
                cout << left << setw(10) << p.first 
                     << setw(30) << coursedb_ref[p.first].name 
                     << setw(10) << coursedb_ref[p.first].credits 
                     << setw(10) << fixed << setprecision(2) << p.second << endl;
            }
        }
        cout << UI::CYAN << "------------------------------------------------------------" << UI::RESET << endl;
        cout << UI::BOLD << "Cumulative GPA (CGPA): " << UI::GREEN << calculatecgpa(coursedb_ref) << UI::RESET << endl;
        cout << UI::CYAN << "------------------------------------------------------------" << UI::RESET << endl;
    }

    void setnextsemester() {
        if (semester == "1st") semester = "2nd";
        else if (semester == "2nd") semester = "3rd";
        else if (semester == "3rd") semester = "4th";
        else if (semester == "4th") semester = "5th";
        else if (semester == "5th") semester = "6th";
        else if (semester == "6th") semester = "7th";
        else if (semester == "7th") semester = "8th";
        else semester = "Graduate";
    }

    int getsemesterint() {
        if (semester == "1st") return 1;
        if (semester == "2nd") return 2;
        if (semester == "3rd") return 3;
        if (semester == "4th") return 4;
        if (semester == "5th") return 5;
        if (semester == "6th") return 6;
        if (semester == "7th") return 7;
        if (semester == "8th") return 8;
        return 9; 
    }
};

class courseadvisor {
private:
    coursedb courses;
    student currentuser;

    void reversevector(vector<string>& v) {
        int n = v.size();
        for (int i = 0; i < n / 2; i++) {
            string temp = v[i];
            v[i] = v[n - 1 - i];
            v[n - 1 - i] = temp;
        }
    }

    class minheapcompare {
    public:
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first; 
        }
    };

public:
    void saveprogress() {
        ofstream outfile("student_data.txt");
        if (!outfile) return;
        
        outfile << currentuser.name << endl << currentuser.semester << endl;
        outfile << currentuser.completedcourses.size() << endl;

        for (auto const& p : currentuser.completedcourses) outfile << p.first << " " << p.second << endl; 
        UI::printSuccess("Data saved successfully.");
        outfile.close();
    }

    void loadprogress() {
        ifstream infile("student_data.txt");
        if (!infile) return;
        string tid; double tg; int count;
        
        if (!(infile >> currentuser.name)) { infile.close(); return; }
        if (!(infile >> currentuser.semester)) { infile.close(); return; }
        if (!(infile >> count)) { infile.close(); return; }

        currentuser.completedcourses = grademap();
        for (int i = 0; i < count; i++) {
            if (!(infile >> tid >> tg)) break;
            if (courses.count(tid)) currentuser.completedcourses.insert(tid, tg);
        }
        cout << UI::GREEN << "\n[LOADED] " << currentuser.name << " (CGPA: " << fixed << setprecision(2) << currentuser.calculatecgpa(courses) << ")" << UI::RESET << endl;
        infile.close();
    }

    void addcourse(string id, string name, int d, int c) {
        if (!courses.count(id)) courses[id] = course(id, name, d, c);
    }

    void addprerequisite(string from, string to) {
        if (courses.count(from) && courses.count(to)) 
            courses[from].adjacentcourses.push_back({to, courses[to].difficulty});
    }

    bool checkprereqs(const string& cid) {
        bool all_met = true;
        for (auto const& p : courses) {
            for (auto edge : p.second.adjacentcourses) {
                if (edge.first == cid) {
                    if (!currentuser.completedcourses.count(p.first)) {
                        cout << UI::YELLOW << "  [!] Missing Prereq: " << p.first << " (" << p.second.name << ")\n" << UI::RESET;
                        all_met = false;
                    }
                }
            }
        }
        return all_met;
    }

    void markcompleted(string id) {
        if (!courses.count(id)) { UI::printError("Invalid Course ID."); return; }
        
        if (currentuser.completedcourses.count(id)) {
            UI::printWarning("Course already recorded. Overwrite? (y/n): ");
            char c; cout << ">> "; cin >> c;
            if (c != 'y' && c != 'Y') return;
        }
        
        if (!checkprereqs(id)) {
             UI::printWarning("Missing prerequisites. Proceed anyway? (y/n): ");
             char c; cout << ">> "; cin >> c;
             if (c != 'y' && c != 'Y') return; 
        }
        cout << "Enter Grade (0.0 to 4.0): "; double g; 
        cout << ">> ";
        if (!(cin >> g)) { cin.clear(); cin.ignore(1000, '\n'); UI::printError("Invalid Input."); return; }
        
        currentuser.completedcourses.insert(id, g);
        UI::printSuccess("Course recorded.");
    }
    
    void addnewcourse_user() {
        string id, name, prereq_id;
        int difficulty, credits;

        UI::printHeader("Add New Course");
        cout << "Enter New Course ID (e.g., span101): "; cout << ">> "; cin >> id;
        if (courses.count(id)) { UI::printError("Course ID already exists."); return; }
        
        cout << "Enter Course Name: "; cout << ">> "; cin.ignore(); getline(cin, name);
        cout << "Enter Difficulty (1-10): "; cout << ">> ";
        if (!(cin >> difficulty) || difficulty < 1 || difficulty > 10) { 
            UI::printError("Invalid difficulty (must be 1-10)."); cin.clear(); cin.ignore(1000, '\n'); return; 
        }
        cout << "Enter Credits: "; cout << ">> ";
        if (!(cin >> credits) || credits < 1) { 
            UI::printError("Invalid credits (must be >= 1)."); cin.clear(); cin.ignore(1000, '\n'); return; 
        }

        addcourse(id, name, difficulty, credits);
        UI::printSuccess("Course " + id + " added to catalog.");

        cout << "\n--- Set Prerequisites ---\n";
        cout << "Enter Prerequisites by ID. Type 'done' to finish.\n";
        while (true) {
            cout << "Prerequisite ID: "; cout << ">> "; cin >> prereq_id;
            if (prereq_id == "done") break;

            if (courses.count(prereq_id)) {
                addprerequisite(prereq_id, id);
                cout << UI::GREEN << "  + " << prereq_id << " set as prerequisite for " << id << "." << UI::RESET << endl;
            } else {
                UI::printError("Prerequisite course ID '" + prereq_id + "' does not exist. Try again.");
            }
        }
        UI::printSuccess("Prerequisite setup complete.");
    }

    bool dfs_cycle(string u, hashmap<string, int>& visited) {
        visited[u] = 1; 
        for (auto edge : courses[u].adjacentcourses) {
            string v = edge.first;
            if (visited.count(v) && visited[v] == 1) return true;
            if (!visited.count(v) || visited[v] == 0) {
                if (dfs_cycle(v, visited)) return true;
            }
        }
        visited[u] = 2; return false;
    }

    bool detectcycles() {
        hashmap<string, int> visited;
        for (auto const& p : courses) visited.insert(p.first, 0); 
        for (auto const& p : courses) {
            if (visited[p.first] == 0) if (dfs_cycle(p.first, visited)) {
                UI::printError("Cycle detected! Roadmap generation aborted."); 
                return true;
            }
        }
        return false;
    }

    void bfs_reachable() {
        string start; cout << "Start Course ID: "; cout << ">> "; cin >> start;
        if (!courses.count(start)) { UI::printError("Invalid ID."); return; }
        queue<string> q; q.push(start);
        hashmap<string, bool> visited; visited.insert(start, true);
        
        UI::printHeader("Courses Reachable from " + start);
        
        bool found = false;
        while(!q.empty()){
            string u = q.front(); q.pop();
            
            if(!currentuser.completedcourses.count(u) && u != start) { 
                cout << UI::GREEN << "  -> [" << u << "] " << courses[u].name << UI::RESET << "\n";
                found = true;
            }
            
            for(auto e : courses[u].adjacentcourses) {
                if(!visited.count(e.first)) { visited.insert(e.first, true); q.push(e.first); }
            }
        }
        if (!found) cout << UI::YELLOW << "No further uncompleted courses reachable." << UI::RESET << endl;
    }

    void generateroadmap() {
        if (detectcycles()) return;
        
        hashmap<string, int> indeg;
        for (auto p : courses) indeg.insert(p.first, 0);
        for (auto p : courses) for (auto e : p.second.adjacentcourses) indeg[e.first]++;

        auto comp = [this](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first; 
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);

        for (auto p : courses) {
            if (indeg[p.first] == 0 && !currentuser.completedcourses.count(p.first))
                pq.push({courses[p.first].difficulty, p.first});
        }
        
        if (pq.empty()) { UI::printSuccess("All prerequisite-free courses are completed!"); return; }

        int sem = currentuser.getsemesterint();
        int credits = 0;
        const int max_credits_per_sem = 12;
        
        UI::printHeader("Recommended Roadmap");
        cout << UI::BOLD << "--- Semester " << sem << " (Max " << max_credits_per_sem << " credits) ---" << UI::RESET << endl;
        
        while (!pq.empty()) {
            string u = pq.top().second; 
            int u_credits = courses[u].credits;
            pq.pop();
            
            if (credits + u_credits > max_credits_per_sem) {
                cout << UI::BOLD << "\n--- Semester " << ++sem << " (Max " << max_credits_per_sem << " credits) ---" << UI::RESET << endl; 
                credits = 0;
            }
            
            cout << "  [" << u << "] " << left << setw(25) << courses[u].name 
                 << " (Diff: " << courses[u].difficulty << ", Cr: " << u_credits << ")\n";
            
            credits += u_credits;
            
            for (auto e : courses[u].adjacentcourses) {
                indeg[e.first]--;
                if (indeg[e.first] == 0 && !currentuser.completedcourses.count(e.first))
                    pq.push({courses[e.first].difficulty, e.first});
            }
        }
    }

    void findpath(string target) {
        string start; cout << "Start Course ID: "; cout << ">> "; cin >> start;
        if (!courses.count(start) || !courses.count(target)) { UI::printError("Invalid Start/Target ID."); return; }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, minheapcompare> pq;
        hashmap<string, int> dist; 
        hashmap<string, string> parent;
        for (auto p : courses) dist.insert(p.first, inf);

        dist[start] = 0; pq.push({0, start});

        while (!pq.empty()) {
            int d = pq.top().first; string u = pq.top().second; pq.pop();
            if (d > dist[u]) continue;
            if (u == target) break;
            
            for (auto e : courses[u].adjacentcourses) {
                if (dist[u] + e.second < dist[e.first]) {
                    dist[e.first] = dist[u] + e.second;
                    parent[e.first] = u;
                    pq.push({dist[e.first], e.first});
                }
            }
        }

        if (dist[target] == inf) { UI::printError("No path exists from " + start + " to " + target + "."); return; }
        
        vector<string> path;
        string at = target;
        while (parent.count(at)) { path.push_back(at); at = parent[at]; } 
        path.push_back(start);
        
        reversevector(path);

        UI::printHeader("Shortest Path (By Difficulty)");
        cout << "Total Difficulty: " << UI::YELLOW << dist[target] << UI::RESET << "\n";
        cout << "Path Sequence: \n";
        for (size_t i = 0; i < path.size(); i++) {
            cout << UI::CYAN << path[i] << UI::RESET << " (" << courses[path[i]].name << ")";
            if (i < path.size()-1) cout << UI::BOLD << " -> " << UI::RESET;
        }
        cout << "\n";
    }

    void display() {
        UI::printHeader("Course Catalog");
        cout << left << setw(10) << "ID" 
             << setw(35) << "Course Name" 
             << setw(10) << "Credits" 
             << setw(10) << "Diff" << endl;
        cout << UI::BLUE << "------------------------------------------------------------------" << UI::RESET << endl;

        for (auto p : courses) {
            cout << left << setw(10) << p.first 
                 << setw(35) << p.second.name 
                 << setw(10) << p.second.credits 
                 << setw(10) << p.second.difficulty << endl;
        }
        cout << UI::BLUE << "------------------------------------------------------------------" << UI::RESET << endl;
    }
    
    void displaytranscript() {
        currentuser.displaytranscript(courses);
    }

    void advancesemester() {
        cout << "\nCurrent Semester: " << currentuser.semester << endl;
        currentuser.setnextsemester();
        cout << UI::GREEN << "Semester Advanced to: " << currentuser.semester << UI::RESET << endl;
    }
};

int main() {
    courseadvisor ca;
    
    // Initial Setup
    ca.addcourse("cs101", "Intro to Prog", 3, 4); 
    ca.addcourse("cs102", "OOP Concepts", 5, 4);
    ca.addcourse("cs201", "Data Struct & Algo", 8, 3); 
    
    ca.addcourse("math1", "Calculus I", 6, 3);
    ca.addcourse("math102", "Calculus II", 7, 3);
    ca.addcourse("phys101", "University Physics I", 6, 4);
    ca.addcourse("cs202", "Discrete Math", 5, 3);
    ca.addcourse("engl101", "College Writing", 2, 3); 
    ca.addcourse("hist101", "World History", 3, 3); 
    
    ca.addcourse("se101", "Software Eng", 4, 3);
    ca.addcourse("cs401", "Senior Project", 10, 6);
    ca.addcourse("cs301", "Database Sys", 7, 3);

    ca.addprerequisite("cs101", "cs102"); 
    ca.addprerequisite("cs102", "cs201");
    
    ca.addprerequisite("math1", "math102");
    ca.addprerequisite("math1", "phys101");
    ca.addprerequisite("math1", "cs202");
    ca.addprerequisite("cs202", "cs201"); 
    
    ca.addprerequisite("cs201", "cs301");
    ca.addprerequisite("cs201", "se101");
    ca.addprerequisite("se101", "cs401");
    ca.addprerequisite("cs301", "cs401");

    UI::clearScreen();
    ca.loadprogress();

    int ch; string id;
    while (true) {
        cout << "\n" << UI::CYAN << UI::BOLD << "--- ACADEMIC ADVISOR MENU ---" << UI::RESET << endl;
        cout << "1. " << UI::BOLD << "View Catalog" << UI::RESET << endl;
        cout << "2. " << UI::BOLD << "Mark Course Completed" << UI::RESET << " (with grade)" << endl;
        cout << "3. " << UI::BOLD << "View Transcript" << UI::RESET << endl;
        cout << "4. " << UI::BOLD << "Generate Roadmap" << UI::RESET << endl;
        cout << "5. " << UI::BOLD << "Find Shortest Path" << UI::RESET << " (by difficulty)" << endl;
        cout << "6. " << UI::BOLD << "Reachable Courses" << UI::RESET << endl;
        cout << "7. " << UI::BOLD << "Save & Exit" << UI::RESET << endl;
        cout << "8. " << UI::BOLD << "Advance Semester" << UI::RESET << endl;
        cout << "9. " << UI::BOLD << "Add New Course to Catalog" << UI::RESET << endl;
        cout << UI::CYAN << "-----------------------------" << UI::RESET << endl;
        cout << "Choice: "; cout << ">> ";
        
        if (!(cin >> ch)) { 
            UI::printError("Invalid choice. Please enter a number.");
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            continue; 
        }
        
        UI::clearScreen(); 

        switch(ch) {
            case 1: ca.display(); break;
            case 2: 
                UI::printHeader("Mark Completion");
                cout << "Enter Course ID: "; cout << ">> "; cin >> id; 
                ca.markcompleted(id); 
                break;
            case 3: ca.displaytranscript(); break; 
            case 4: ca.generateroadmap(); break;
            case 5: 
                UI::printHeader("Path Finder");
                cout << "Enter Target Course ID: "; cout << ">> "; cin >> id; 
                ca.findpath(id); 
                break;
            case 6: ca.bfs_reachable(); break;
            case 7: ca.saveprogress(); return 0;
            case 8: ca.advancesemester(); break;
            case 9: ca.addnewcourse_user(); break;
            default: UI::printError("Invalid option. Try again.");
        }

        if (ch != 7) UI::pressEnterToContinue();
        UI::clearScreen();
    }
}
