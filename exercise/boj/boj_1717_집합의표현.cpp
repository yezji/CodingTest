#include <iostream>
#include <vector>
using namespace std;

vector<int> djset(1); // disjoint set
int n, m;

int find(int x) {
    if (djset[x] == x) return x; // return root node
    else return djset[x] = find(djset[x]); // is not root node, find root node
}
void unite(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    djset[root_x] = root_y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int com, a, b;
    cin >> n >> m;

    for (int i=0; i<n; i++) djset.emplace_back(i+1); // make each group

    for (int i=0; i<m; i++) {
        cin >> com >> a >> b;
        if (!com) unite(a, b);
        else cout << (find(a) == find(b)? "YES\n": "NO\n");
    }
    return 0;
}