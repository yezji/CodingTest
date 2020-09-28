#include <cstdio>
#include <vector>
using namespace std;

int solution(int n, vector<int> money) {
	int arr[100010];
	for (int i = 1; i <= n; i++) { //1가지 화폐일 때 1~n원 처리
		if (i % money[0] == 0) arr[i] = 1;
		else arr[i] = 0;
	}
	for (int i = 1; i < money.size(); i++) {
		for (int j = money[i]; j <= n; j++) {
			if (j == money[i]) arr[j] = (arr[j] + 1) % 1000000007;
			else arr[j] = (arr[j] + arr[j - money[i]]) % 1000000007;
		}
	}
	return arr[n];
}

int main() {
	int n = 5;
	vector<int> money = { 1,2,5 };

	//int answer = solution_disabled(n, money); //효율성 통과X
	int answer = solution(n, money); //효율성 통과O
	printf_s("answer: %d\n", answer);

	return 0;
}