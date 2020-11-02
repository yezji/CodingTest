#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    sort(d.begin(), d.end());
    for (int i=0; i<d.size(); i++) {
        if (sum+d[i] > budget) break;
        sum += d[i];
        answer++;
    }
    return answer;
}

int main() {
    vector<int> d;
    int budget;
    d = {1, 3, 2, 5, 4};
    budget = 9;
    cout << solution(d, budget) << endl;
    d = {2, 2, 3, 3};
    budget = 10;
    cout << solution(d, budget) << endl;
    return 0;
}