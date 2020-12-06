#include <iostream>
#include <vector>
using namespace std;

// DP
/*
T(i) = T(i-1) + T(i-2)
T(1) = 1                {1}
T(2) = 2                {1+2}, {+2}
T(3) = T(2) + T(1) = 3  {12+3, 2+3}, {1+3}
T(4) = T(3) + T(2) = 5  {123+4, 23+4, 13+4}, {12+4, 2+4}
T(5) = T(4) + T(3) = 8  {1234+5, 234+5, 134+5, 124+5, 24+5}, {123+5, 23+5, 13+5}
*/
vector<long long> dp(1); //start from 1

long long solution(int n) {
    for (int i=1; i<=n; i++) {
        if (i<=2) dp.emplace_back(i);
        else dp.emplace_back((dp[i-1] + dp[i-2]) % 1234567);
    }
    return dp.back();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << solution(4) << "\n";
    cout << solution(3) << "\n";
    cout << solution(2000) << "\n";

    return 0;
}