#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> emp;
int n;
string name, work;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> name >> work;
        if (!emp.count(name) && work=="enter") emp.emplace(name);
        else if (emp.count(name) && work=="leave") emp.erase(name);
    }

    for (auto rit = emp.rbegin(); rit != emp.rend(); rit++) cout << *rit << "\n";
    
    return 0;
}