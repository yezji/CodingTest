#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1001;

int map[MAX][MAX] = {0, };
int visited[MAX] = {0, };
queue<int> q;
int n, m, v;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void dfs(int v) {
    visited[v] = 1;
    cout << v << " ";
    for (int i=1; i<=n; i++) {
        if (map[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int v) {
    visited[v] = 1;
    q.emplace(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();
        cout << v << " ";
        for (int i=1; i<=n; i++) {
            if (map[v][i] && !visited[i]) {
                visited[i] = 1;
                q.emplace(i);
            }
        }
    }
}

int main() {
    init();
    scanf("%d %d %d", &n, &m ,&v);

    for (int i=1; i<=m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }

    // cout << "DFS:\t";
    dfs(v);
    cout << endl;

    memset(visited, 0, sizeof(visited));
    
    // cout << "BFS:\t";
    bfs(v);
    cout << endl;

    return 0;
}