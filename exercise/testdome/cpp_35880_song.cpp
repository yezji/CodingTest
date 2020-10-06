#include <stdexcept>
#include <iostream>
#include <unordered_set>
using namespace std;

class Song {
public:
    Song(string name): name(name), nextSong(NULL) {}
    
    void next(Song* song) {
        this->nextSong = song;
    }

    bool isRepeatingPlaylist() {
        unordered_set<string> slist;
        // unordered_set<string>::iterator it;
        Song* tmp = this;
        while (tmp != NULL) {
            bool is_in = slist.find(tmp->name) != slist.end();
            if (is_in) return true;
            else slist.emplace(tmp->name);
            tmp = tmp->nextSong;
        }
        return false;
    }

private:
    const string name;
    Song* nextSong;
};

#ifndef RunTests
int main() {
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");
    Song* third = new Song("Eye");
    Song* fourth = new Song("Tiger");
    
    first->next(second);
    second->next(third);
    third->next(second);
    fourth->next(NULL);

    cout << std::boolalpha << first->isRepeatingPlaylist();
}
#endif