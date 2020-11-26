#include <iostream>
using namespace std;

int num[100001];
int sum[100001];
int n, m;
int from, to;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;

    sum[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> num[i];
        sum[i] = sum[i-1] + num[i];
    }

    for (int i=0; i<m; i++) {
        cin >> from >> to;
        cout << sum[to] - sum[from-1] << "\n";
    }

    return 0;
}