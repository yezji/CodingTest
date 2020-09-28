#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// struct compare {
//     bool operator()(string a, string b) const {
//         return strcmpi(a.c_str(), b.c_str()) < 0;
//     }
// };
bool compare(string a, string b) {
    return strcmpi(a.c_str(), b.c_str()) < 0;
}

int main() {
    while (1) {
        int testcase;
        scanf("%d", &testcase);
        if (testcase == 0) break;

        vector<string> answer;
        for (int t=0; t<testcase; t++) {
            string input;
            cin >> input;
            answer.push_back(input);
        }
        sort(answer.begin(), answer.end(), compare);
        cout << answer[0] << endl;
        answer.clear();
    }
    
    return 0;
}