#include <iostream>
#include <vector>
using namespace std;

vector<int> disjoint_set(1); // 정점 1부터 시작

int find(int x) { // root node 찾기
    if (x == disjoint_set[x]) return x;
    else return disjoint_set[x] = find(disjoint_set[x]);
}

void unite(int x, int y) {
    x = find(x); // x가 속한 그룹의 root node 찾고
    y = find(y); // y가 속한 그룹의 root node 찾고
    disjoint_set[y] = x; // 한쪽의 root node 아래에 다른 한쪽의 root node 넣음
}

bool solution(vector<pair<int, int>> input, vector<int> can_cycle, int n) {
    // 각 정점을 root node로 만들기
    for (int node = 1; node <= n; node++) disjoint_set.emplace_back(node); // 1~n번까지
    
    // 트리 붙여나가기 (union find)
    for (int i = 0; i < input.size(); i++) unite(input[i].first, input[i].second);
    
    // disjoint_set 출력
    cout << "disjoint_set: ";
    for (int node = 1; node < disjoint_set.size(); node++) cout << disjoint_set[node] << " ";
    cout << "\n";
    // cycle 안에 있는지 찾기
    int y = find(can_cycle[0]);
    for (int i=1; i<can_cycle.size(); i++) {
        if (y != find(can_cycle[i])) return false; // 루트노드가 같지 않다면
    }
    return true;

}

int main() {
    vector<pair<int, int>> input = {{1, 2}, {3, 4}, {1, 4}}; // 정점 1부터 시작
    vector<int> can_cycle = {1, 2, 3, 4};
    cout << (solution(input, can_cycle, 8)?"cycle\n":"not cycle\n");

    return 0;
}