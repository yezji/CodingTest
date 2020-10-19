#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
// #1 O(n log n), Using quick sort
string solution(vector<string> participant, vector<string> completion) {
    string answer;
    sort(completion.begin(), completion.end());
    sort(participant.begin(), participant.end());
    for (int i=0; i<participant.size(); i++) {
        if (participant[i] != completion[i]) return participant[i];
        else answer = participant[i];
    }
    return answer;
}
*/

//#2 O(n), Using hash
string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> passed;
    for (auto data : completion) {
        if (passed.find(data) == passed.end()) passed.emplace(data, 1);
        else passed[data]++;
    }
    for (auto data : participant) {
        if (passed.find(data) == passed.end()) return data;
        if (--passed[data] < 0) return data;
    }
}

int main() {
    vector<string> participant;
    vector<string> completion;
    
    participant = {"leo", "kiki", "eden"};
    completion = {"eden", "kiki"};
    cout << solution(participant, completion) << endl;

    participant = {"marina", "josipa", "nikola", "vinko", "filipa"};
    completion = {"josipa", "filipa", "marina", "nikola"};
    cout << solution(participant, completion) << endl;

    participant = {"mislav", "stanko", "mislav", "ana"};
    completion = {"stanko", "ana", "mislav"};
    cout << solution(participant, completion) << endl;
    
    return 0;
}