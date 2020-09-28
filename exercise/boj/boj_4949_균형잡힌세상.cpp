#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    bool check = true;

    stack<char> medium;
    stack<char> large;

    char data;
    while (scanf("%c", &data) != EOF || data != NULL) {
        if (data == '.') {
            if (check) cout << "yes" << endl;
            else cout << "no" << endl;
            check = true;
            continue;
            // break;
        }

        if (data == '(') {
            medium.push(data);
        }
        else if (data == '[') {
            large.push(data);
        }
        else if (data == ')') {
            if (!medium.empty()) {
                medium.pop();
            }
            else {
                check = false;
                continue;
            }
        }
        else if (data == ']') {
            if (!large.empty()) {
                large.pop();
            }
            else {
                check = false;
                continue;
            }
        }
    }


    return 0;
}