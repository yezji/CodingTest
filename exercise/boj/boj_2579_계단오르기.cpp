#include <iostream>
#include <algorithm>
using namespace std;

int n;
int steps[310];
int dp[310];

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> steps[i];

    dp[1] = steps[1];
    dp[2] = max(steps[2]+steps[1], steps[2]); //max(n-1 밟O, n-1 밟X)
    dp[3] = max(steps[3]+steps[2], steps[3]+steps[1]);

    for (int i=4; i<=n; i++) {
        dp[i] = max(steps[i]+steps[i-1]+dp[i-3], steps[i]+dp[i-2]);
    }
    
    cout << dp[n] << endl;
    
    return 0;
}