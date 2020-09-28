#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum diretion {LEFT, RIGHT, UP, DOWN};
int origin[20][20] = {0, };
int map[20][20] = {0, };
int n;

struct Core {
    int x, y;
    int sum[4] = {0, }; // LEFT, RIGHT, UP, DOWN

    Core() {
        this->x = x;
        this->y = y;
    }

    void sumLeft() {
        for (int j=this->y-1; j>=0; j--) {
            if (map[this->x][j] == 0) {
                sum[LEFT]++;
                map[this->x][j]++;
            }
        }
    }

    void sumRight() {
        for (int j=this->y+1; j<n; j++) {
            if (map[this->x][j] == 0) {
                sum[RIGHT]++;
                map[this->x][j]++;
            }
        }
    }

    void sumUp() {
        for (int i=this->x-1; i>=0; i--) {
            if (map[i][this->y] == 0) {
                sum[UP]++;
                map[i][this->y]++;
            }
        }
    }

    void sumDown() {
        for (int i=this->x+1; i<n; i++) {
            if (map[i][this->y] == 0) {
                sum[DOWN]++;
                map[i][this->y]++;
            }
        }
    }
    
    int minIndex() {
        int min_value = -1;
        int min_idx = -1;
        for (int i=0; i<4; i++) {
            if (this->sum[i] != INT32_MAX 
            && this->sum[i] < min_value) {
                min_value = this->sum[i];
                min_idx = i;
            }
        }
        return min_idx;
    }
};

void initMap() {
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) map[i][j] = origin[i][j];
}

int main() {
    int testcase;
    scanf("%d", &testcase);

    while (testcase--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int input;
                scanf("%d", &input);

                origin[i][j] = input;
                map[i][j] = input;
            }
        }

        //재귀함수 구현하고, 여기에서 재귀함수 사용하기

    }
    return 0;
}