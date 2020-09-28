#include <iostream>
using namespace std;

int n;
// int answer;
int board[10];

int go(int )


int main() {
    int tc;
    cin >> tc;
    for (int t=1; t<=tc; t++) {
        memset(board, 0, sizeof(board));
        int answer = 0;
        cin >> n;
        cout << "#" << t << " ";
        for (int i=0; i<n; i++) {
            answer += go(0, i);
        }
        cout << answer << endl;
    }
    return 0;
}