#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

struct Trie {
    int count = 0; // 학습된 문자가 몇개인지
    bool finish = false; // 문자의 끝
    Trie* next[26] = {NULL,};

    Trie() {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for (int i=0; i<26; i++) if (next[i]) delete next[i];
    }

    void insert(const char* key) {
        // cout << *key << endl;
        if (*key == '\0') finish = true;
        else {
            int idx = *key - 'a'; //not 'A'
            if (next[idx] == NULL) next[idx] = new Trie();
            next[idx]->count++;
            next[idx]->insert(key+1);
        }
    }

    int find(const char* key, int cnt) {
        int idx = *key - 'a';
        if (*key == '\0' || next[idx] == NULL) return cnt-1;
        if (next[idx]->count == 1) return cnt;
        return next[idx]->find(key+1, cnt+1);
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie* root = new Trie();

    for (int i=0; i<words.size(); i++) root->insert(words[i].c_str());
    for (int i=0; i<words.size(); i++) answer += root->find(words[i].c_str(), 1);

    delete root;
    return answer;
}

int main() {
    vector<string> words;
    // words.push_back("go");
    // words.push_back("gone");
    // words.push_back("guild");

    // words.push_back("abc");
    // words.push_back("def");
    // words.push_back("ghi");
    // words.push_back("jklm");

    words.push_back("word");
    words.push_back("war");
    words.push_back("warrior");
    words.push_back("world");
    
    cout << solution(words) << endl;

    return 0;
}