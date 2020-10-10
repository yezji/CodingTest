#include <iostream>
using namespace std;

int solution(int arr[], int &n, int &m) {
    int answer = 0;
    int i=0, j=0;
    int sum = 0;

    for (; i<n; i++) {
        while (sum<m && j<n) {
            sum += arr[j];
            j++;
        }
        if (sum==m) answer++;
        sum -= arr[i];
    }
    return answer;
}

int main() {
    int arr[10010];
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i=0; i<n; i++) scanf("%d", &arr[i]);
    cout << solution(arr, n, m) << endl;

    return 0;
}