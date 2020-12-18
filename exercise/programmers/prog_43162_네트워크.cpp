#include <iostream>
#include <vector>
#define MAX 200
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (int adj=0; adj<graph.size(); adj++) {
        if (graph[node][adj] && !visited[adj]) dfs(adj);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph = computers;
    visited = vector<bool>(MAX);

    for (int node=0; node<n; node++) {
        if (!visited[node]) {
            dfs(node);
            answer++;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << "\n";
    cout << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << "\n";
    cout << solution(3, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}) << "\n";
    return 0;
}