#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

void dfs(int idx, int sum, int target, vector<int>& numbers) {
    if (idx >= numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    dfs(idx+1, sum+numbers[idx], target, numbers);
    dfs(idx+1, sum-numbers[idx], target, numbers);
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, target, numbers);
    return answer;
}

int main() {
    answer = 0;
    cout << solution({1, 1, 1, 1, 1}, 3) << "\n";

    answer = 0;
    cout << solution({4, 2, 5}, 11) << "\n";
    return 0;
}