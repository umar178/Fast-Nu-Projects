#include <iostream>
#include <vector>
using namespace std;

struct Folder {
    vector<int> files;
    vector<Folder> subfolders; 
};

int getFolderSize(const Folder& folder) {
    int total_size = 0;

    for (int size : folder.files) {
        total_size += size;
    }

    for (const auto& subfolder : folder.subfolders) {
        total_size += getFolderSize(subfolder);
    }

    return total_size;
}

int main() {
    Folder root;
    root.files = {10, 20, 5};

    Folder sub1;
    sub1.files = {5, 5};

    Folder sub2;
    sub2.files = {100};

    Folder sub2_1;
    sub2_1.files = {50};
    sub2.subfolders.push_back(sub2_1);

    root.subfolders.push_back(sub1);
    root.subfolders.push_back(sub2);

    cout << "Total Folder Size: " << getFolderSize(root) << " KB" << endl;

    return 0;
}

