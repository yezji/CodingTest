#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<bool> broken(10);
int n, m;
int answer;

int countPress(int channel) {
    if (channel == 0) return broken[0]? 0: 1;

    int digit = 0; // 숫자버튼 누른 횟수
    while (channel > 0) {
        if (broken[channel%10]) return 0; // 고장난 버튼이면 이동으로만 눌러야 함
        channel/=10;
        digit++;
    }
    return digit;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int input;
        cin >> input;
        broken[input] = true;
    }

    // #1 숫자버튼 없이 이동버튼만 누른 횟수 
    answer = abs(n-100);

    // #2 숫자버튼+이동버튼 누른 횟수
    for (int channel=0; channel<=1000000; channel++) {
        int digit = countPress(channel);
        int press = abs(channel-n);
        if (digit > 0 && press+digit < answer) answer = press+digit;
    }

    cout << answer << "\n";

    return 0;
}