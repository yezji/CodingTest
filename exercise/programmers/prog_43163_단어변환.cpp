#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> visited;
int answer = 55;

void dfs(int now, string& begin, string& target, vector<string>& words) {
    for (int word=0; word<words.size(); word++) {
        int diff = 0;
        for (int ch=0; ch<words[word].size(); ch++) {
            if (!visited[word] && begin[ch] != words[word][ch]) diff++;
        }
        if (diff == 1) {
            if (words[word] == target && now+1 < answer) {
                answer = now+1;
                return;
            }

            visited[word] = true;
            dfs(now+1, words[word], target, words);
            visited[word] = false;
        }
    }

}

int solution(string begin, string target, vector<string> words) {
    visited = vector<bool>(words.size(), false);
    answer = 55;
    
    dfs(0, begin, target, words);
    return answer == 55 ? 0 : answer;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << "\n";
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << "\n";
    return 0;
}