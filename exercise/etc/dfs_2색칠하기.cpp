#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10010;
vector<int> graph[MAX];
bool visited[MAX];
bool colored[MAX];
int n, m;
bool answer = true;

void dfs(int x, bool color) {
  visited[x] = true; // 1. 방문처리, 컬러처리
  colored[x] = color;
  
  for (int i=0; i<graph[x].size(); i++) { // 2. 이웃 돌기
    int y = graph[x][i]; // 3. 이웃 노드 담고
    if (!visited[y]) dfs(y, !color); // 4. 이웃을 아직 방문 안했다면 dfs
    else if (colored[x] == colored[y]) { // 5. 이웃 방문 했었는데 나랑 컬러가 같다면
      answer = false;
      return;
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i=0; i<m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  
  dfs(0, true);
  cout << (answer?"YES":"NO") << endl;

  return 0;
}

/*
<testcase 1>
- input:
9 10
0 1
0 2
0 3
1 5
2 5
3 4
5 6
5 8
6 7
7 8
- output:
YES

<testcase 2>
- input:
9 11
0 1
0 2
0 3
1 5
2 5
3 4
4 5
5 6
5 8
6 7
7 8
- output:
NO
*/