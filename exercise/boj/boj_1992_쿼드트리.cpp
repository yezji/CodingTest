#include <iostream>
#include <vector>
using namespace std;

int arr[70][70];

bool is_available(int i, int j, int size) {
    int cmp = arr[i][j];
    for (int y=i; y<i+size; y++) {
        for (int x=j; x<j+size; x++) {
            if (arr[y][x] != cmp) return false;
        }
    }
    return true;
}

void compress(int i, int j, int size) {
    if (size == 1) { //base condition
        cout << arr[i][j];
        return ;
    }
    
    if (is_available(i, j, size)) {
        cout << arr[i][j];
        return ;
    }
    else {
        cout << "(";
        compress(i, j, size/2);
        compress(i, j+(size/2), size/2);
        compress(i+(size/2), j, size/2);
        compress(i+(size/2), j+(size/2), size/2);
        cout << ")";
    }

}

int main() {
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    compress(0, 0, n);
    
    return 0;
}