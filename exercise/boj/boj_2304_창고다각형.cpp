#include <iostream>
#include <algorithm>
using namespace std;

int warehouse[1010];
int n;
int start_idx=1010, end_idx=-1, max_height_idx=0;

int sum_from_left() {
    int sum = 0;
    int height = 0;
    for (int i=start_idx; i<max_height_idx; i++) {
        height = max(height, warehouse[i]);
        sum += height;
    }
    return sum;
}

int sum_from_right() {
    int sum = 0;
    int height = 0;
    for (int i=end_idx; i>max_height_idx; i--) {
        height = max(height, warehouse[i]);
        sum += height;
    }
    return sum;
}

int main() {
    int answer = 0;
    scanf("%d", &n);

    while (n--) {
        int idx;
        scanf("%d", &idx);
        scanf("%d", &warehouse[idx]);

        if (start_idx > idx) start_idx = idx;
        if (end_idx < idx) end_idx = idx;
        if (warehouse[max_height_idx] < warehouse[idx]) max_height_idx = idx;
    }
    answer = warehouse[max_height_idx];
    answer += sum_from_left();
    answer += sum_from_right();

    cout << answer << endl;
    
    return 0;
}