/* 숫자 만들기
문제 : 1~M까지의 숫자를 더하여 N을 만드는 경우의 수 구하기
입력 : 5 3
출력 : 13
*/

/* 풀이
1. 부분정의 : T(i) = 1~M으로 i를 만드는 경우의 수, ex) M=3, T(4) = 7
2. 점화식   : T(i) = T(i-1) + T(i-2) + ... + T(i-M)
*/
#include <iostream>
using namespace std;

const int MAX = 100;

int answer[MAX];
int n, m;

int main() {
	//scanf_s("%d %d", &n, &m);
	n = 5, m = 3;
	//ex M=3, T(5)=13
	//T(1) = 1
	//T(2) = T(1) + 1
	//T(3) = T(2) + T(1) + 1
	//T(4) = T(3) + T(2) + T(1)
	//T(5) = T(4) + T(3) + T(2)

	answer[1] = 1;
	int sum = 0;
	for (int i = 2; i <= m; i++) {
		//answer[i] = answer[1] + answer[2] + ... + answer[i-1] + 1
		sum += answer[i - 1];
		answer[i] = sum + 1;
	}
	for (int i = m + 1; i <= n; i++) {
		for (int j = i - m; j <= i - 1; j++) {
			answer[i] += answer[j];
		}
	}

	printf("%d\n", answer[n]);
	
	return 0;
}