#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> seoul = { "Jane", "Kim", "Hong" };
	string answer = "김서방은 ";
	int idx = 0;
	for (; idx < seoul.size(); idx++) {
		if (seoul[idx].find("Kim") != string::npos) answer.append(std::to_string(idx));
	}
	answer.append("에 있다");

	return 0;
}