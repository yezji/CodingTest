#include <iostream>
using namespace std;

enum FACE{U, D, F, B, L, R, SIZE};
char init[7] = "wyrogb";
char arr[55];
int cube[SIZE][3][3];
char tmp[3][3];

int sides[6][4*3] = {
    {36, 37, 38, 18, 19, 20, 45, 46, 47, 27, 28, 29}, //U
    {44, 43, 42, 35, 34, 33, 53, 52, 51, 26, 25, 24}, //D
    {38, 41, 44, 9, 10, 11, 51 ,48 ,45, 8, 7, 6}, //F
    {47, 50, 53, 17, 16, 15, 42, 39, 36, 0, 1, 2}, //B
    {29, 32, 35, 15, 12, 9, 243, 21, 18, 6, 3, 0}, //L
    {20, 23, 26, 11, 10, 9, 33, 30, 27, 8, 7, 6} //R
};

void rotate(FACE f, int cnt) {
    char queue[12];

    while (cnt--) {
        for (int i=0; i<4*3; i++) queue[i] = arr[sides[f][i]];
        for (int i=0; i<4*3; i++) arr[sides[f][i]] = queue[(i+3)%12];
        for (int i=0; i<3; i++) for (int j=0; j<3; j++) tmp[j][2-i] = arr[cube[f][i][j]];
        for (int i=0; i<3; i++) for (int j=0; j<3; j++) arr[cube[f][i][j]] = tmp[i][j];
    }
}

int conv[256];
int main() {
    conv['-'] = 3;
    conv['+'] = 1;
    conv['U'] = U;
    conv['D'] = D;
    conv['F'] = F;
    conv['B'] = B;
    conv['L'] = L;
    conv['R'] = R;

    for (int i=0; i<SIZE; i++) for (int j=0; j<3; j++) for (int k=0; k<3; k++) cube[i][j][k] = i*9 + j*3 + k;
    int testcase, input;
    char comm[3];

    while (testcase--) {
        for (int i=0; i<SIZE; i++) {
            for (int j=0; j<9; j++) {
                arr[i*9+j] = init[i];
            }
        }

        scanf("\n%d\n", &input);
        while (input--) {
            scanf("%s \n", comm);
            int face = conv[comm[0]];
            int cnt = conv[comm[1]];
            rotate((FACE)face, cnt);
        }

        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                printf("%c", arr[cube[U][i][j]]);
            }
            printf("\n");
        }
    }

    return 0;
}