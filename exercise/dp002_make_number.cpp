/* 숫자 만들기
문제 : 1,2,3을 이용하여 숫자 N을 만드는 경우의 수 구하기
입력1 : 4
출력1 : 7
입력2 : 200
출력2 : 290816
*/

#include <stdio.h>
using namespace std;

long long arr[100010];

int main() {
	long long n;
	int m = 3;
	scanf("%lld", &n);

	//T(1) = 1  
	//T(2) = T(1)+1
	//T(3) = T(2)+T(1)+1
	//T(4) = T(3)+T(2)+T(1)
	//T(5) = T(4)+T(3)+T(2)
	arr[1] = 1;
	long long sum = 0;
	for (int i = 2; i <= m; i++) {
		sum += arr[i - 1];
		arr[i] = sum + 1;
	}
	for (int i = m + 1; i <= n; i++) {
		arr[i] = 0;
		for (int j = i - m; j <= i - 1; j++) {
			arr[i] += arr[j] % 1000007; //�������� mod�� ����x!!
		}
	}

	long long answer = arr[n] % 1000007;
	printf("%lld\n", answer);

	return 0;
}