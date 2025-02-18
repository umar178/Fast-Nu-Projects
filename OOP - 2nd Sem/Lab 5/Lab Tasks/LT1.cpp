#include <iostream>
#include <string>
using namespace std;

class MusicSession {
private:
    string title;
    string artist;
    int duration;
    static int totalSongsPlayed;

public:
    MusicSession(string t, string a, int d) : title(t), artist(a), duration(d) {}

    void playSong() {
        totalSongsPlayed++;
        cout << "Playing: " << title << " by " << artist << " [" << duration << " sec]" << endl;
    }

    static void displayTotalSongs() {
        cout << "Total Songs Played: " << totalSongsPlayed << endl;
    }
};

int MusicSession::totalSongsPlayed = 0;

int main() {
    MusicSession song1("Shape of You", "Ed Sheeran", 210);
    MusicSession song2("Blinding Lights", "The Weeknd", 200);
    MusicSession song3("Shape of You", "Ed Sheeran", 210);

    song1.playSong();
    song2.playSong();
    song3.playSong();

    MusicSession::displayTotalSongs();

    return 0;
}
