#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr(10010);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    int answer = 0;
    int i = 0, j = 0;
    int sum = arr[0];
    while (j<n) {
        if (sum<m) {
            j++;
            sum += arr[j];
        }
        else {
            if (sum==m) answer++;
            sum -= arr[i];
            i++;
        }
    }
    cout << answer << endl;

    return 0;
}