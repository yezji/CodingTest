# Kruskal's Algorithm
- 최소신장트리(MST)를 구하는 대표 알고리즘
    - 최소신장트리 : 그래프의 모든 노드를 포함하는 사이클 없는 그래프 + 간선들의 가중치 합이 최소인 경로
- Disjoint set 자료구조 사용
    - 1차원 벡터로 구현
    - union, find 연산 구현
- 구현
    1. 각 노드를 하나의 MST로 보고 시작
    2. 간선을 가중치 순으로 정렬
    3. 사이클 체크 후 사이클 생긴다면 간선 잇지 않음


``` cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
(1) 그래프 입력 받기
(2) 간선 가중치 작은 순으로 정렬
(3) 간선이 같은 트리 내에 있는지(사이클 유무) 확인
  (3-1) 시작점과 끝점이 같은 트리에 속한다면 그냥 넘어간다
  (3-2) 그게 아니라면, 이 간선을 선택하여 가중치를 더한다
        시작점과 끝점을 같은 그룹으로 만들어준다
*/
struct edge {
  int from;
  int to;
  int weight;
};

int n, m, answer=0;
vector<edge> edges;
vector<int> djset(1); // disjoint set: store vertex(1~N)'s root idx

edge makeEdge(int f, int t, int w) {
  edge e;
  e.from = f;
  e.to = t;
  e.weight = w;
  return e;
}

bool compare(edge e1, edge e2) {
  return e1.weight < e2.weight;
}

int find(int x) {
  if (x == djset[x]) return x; // return root
  else return djset[x] = find(djset[x]); // replace my root to parent's root
}

void unite(int x, int y) {
  int root_x = find(x);
  int root_y = find(y);
  djset[root_y] = root_x;
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> m;
  
  int f, t, w;
  for (int i=0; i<m; i++) {
   cin >> f >> t >> w;
   edges.emplace_back(makeEdge(f, t, w));
  }
  
  sort(edges.begin(), edges.end(), compare); // weight ascending
  
  for (int i=1; i<=n; i++) djset.emplace_back(i); // init djset
  
  for (int i=0; i<m; i++) {
   if (find(edges[i].from) != find(edges[i].to)) { // has not cycle
     answer += edges[i].weight;
     unite(edges[i].from, edges[i].to);
   }
  }
  cout << answer << "\n";
  
  return 0;
}
```


###### input
```
8 10
1 2 1
1 3 2
2 3 3
2 4 4
4 5 1
4 6 2
5 6 2
5 8 2
6 7 3
7 8 4
```
###### result
```
15
```