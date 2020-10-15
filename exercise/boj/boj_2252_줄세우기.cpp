#include <iostream>
#include <vector>
#include <string>
// #include <unordered_map>
// #include <unordered_set>
#include <queue>
// #include <stack>
// #include <cstdlib>
// #include <math.h>
// #include <algorithm>
using namespace std;

int indegree[32010] = {0, };
vector<int> connect[32010];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i=0; i<m; i++) {
        int first, second;
        scanf("%d %d", &first, &second);
        indegree[second]++;
        connect[first].emplace_back(second);
    }

    queue<int> now;
    for (int i=1; i<=n; i++) if (indegree[i] == 0) now.emplace(i);

    while (!now.empty()) {
        int i = now.front();
        now.pop();
        cout << i << " ";

        for (int j=0; j<connect[i].size(); j++) {
            if (--indegree[connect[i][j]] == 0) now.emplace(connect[i][j]);
        }
    }
    
    return 0;
}