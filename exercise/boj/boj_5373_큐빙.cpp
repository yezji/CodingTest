#include <iostream>
#include <string>
#include <vector>
using namespace std;
char cube[6][3][3]; //whole face:6, each faces:3
/*			U0	1	2						
			3	4	5						
			6	7	8						
L36	37	38	F18	19	20	R45	46	47	B27	28	29
39	40	41	21	22	23	48	49	50	30	31	32
42	43	44	24	25	26	51	52	53	33	34	35
			D9	10	11						
			12	13	14						
			15	16	17						
*/

void fill_adjoin() {
    int side;
    int face;
    int up_face, up_idx;
    int right_face, right_idx;
    int down_face, down_idx;
    int left_face, left_idx;
    //U
    face = 0;
    up_face = 3, up_idx = 29; //-=1
    right_face = 5, right_idx = 47; //-=1
    down_face = 2, down_idx = 20; //-=1
    left_face = 4, left_idx = 38; //+=3
    
    side = 0; //up
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = up_face;
        adjoin[face][side][idx][1] = up_idx--;
    }
    side = 1; //right
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = right_face;
        adjoin[face][side][idx][1] = right_idx--;
    }
    side = 2; //down
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = down_face;
        adjoin[face][side][idx][1] = down_idx--;
    }
    side = 3; //left
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = left_face;
        adjoin[face][side][idx][1] = left_idx++;
    }
    
    //D
    face = 1;
    up_face = 2, up_idx = 24; //+=1
    right_face = 5, right_idx = 51; //+=1
    down_face = 3, down_idx = 33; //+=1
    left_face = 4, left_idx = 42; //+=1
    
    side = 0; //up
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = up_face;
        adjoin[face][side][idx][1] = up_idx++;
    }
    side = 1; //right
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = right_face;
        adjoin[face][side][idx][1] = right_idx++;
    }
    side = 2; //down
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = down_face;
        adjoin[face][side][idx][1] = down_idx++;
    }
    side = 3; //left
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = left_face;
        adjoin[face][side][idx][1] = left_idx++;
    }

    //F
    face = 2;
    up_face = 0, up_idx = 6; //+=1
    right_face = 5, right_idx = 45; //+=3
    down_face = 1, down_idx = 11; //-=1
    left_face = 4, left_idx = 44; //-=3
    
    side = 0; //up
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = up_face;
        adjoin[face][side][idx][1] = up_idx++;
    }
    side = 1; //right
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = right_face;
        adjoin[face][side][idx][1] = right_idx+=3;
    }
    side = 2; //down
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = down_face;
        adjoin[face][side][idx][1] = down_idx--;
    }
    side = 3; //left
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = left_face;
        adjoin[face][side][idx][1] = left_idx-=3;
    }

    //B
    face = 3;
    up_face = 0, up_idx = 2; //-=1
    right_face = 4, right_idx = 36; //+=3
    down_face = 1, down_idx = 15; //+=1
    left_face = 5, left_idx = 53; //-=3
    
    side = 0; //up
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = up_face;
        adjoin[face][side][idx][1] = up_idx--;
    }
    side = 1; //right
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = right_face;
        adjoin[face][side][idx][1] = right_idx+=3;
    }
    side = 2; //down
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = down_face;
        adjoin[face][side][idx][1] = down_idx++;
    }
    side = 3; //left
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = left_face;
        adjoin[face][side][idx][1] = left_idx-=3;
    }

    //L
    face = 4;
    up_face = 0, up_idx = 0; //+=3
    right_face = 2, right_idx = 18; //+=3
    down_face = 1, down_idx = 9; //+=3
    left_face = 3, left_idx = 35; //-=3
    
    side = 0; //up
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = up_face;
        adjoin[face][side][idx][1] = up_idx+=3;
    }
    side = 1; //right
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = right_face;
        adjoin[face][side][idx][1] = right_idx+=3;
    }
    side = 2; //down
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = down_face;
        adjoin[face][side][idx][1] = down_idx+=3;
    }
    side = 3; //left
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = left_face;
        adjoin[face][side][idx][1] = left_idx-=3;
    }

    //R
    face = 5;
    up_face = 0, up_idx = 8; //-=3
    right_face = 3, right_idx = 27; //+=3
    down_face = 1, down_idx = 17; //-=3
    left_face = 2, left_idx = 26; //-=3
    
    side = 0; //up
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = up_face;
        adjoin[face][side][idx][1] = up_idx-=3;
    }
    side = 1; //right
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = right_face;
        adjoin[face][side][idx][1] = right_idx+=3;
    }
    side = 2; //down
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = down_face;
        adjoin[face][side][idx][1] = down_idx-=3;
    }
    side = 3; //left
    for (int idx=0; idx<3; idx++) {
        adjoin[face][side][idx][0] = left_face;
        adjoin[face][side][idx][1] = left_idx-=3;
    }
}

void make_faces() {
    char color;
    char n = '0';
    for (int i=0; i<6; i++) { //U D F B L R
        if (i == 0) color = 'w';
        else if (i == 1) color ='y';
        else if (i == 2) color ='r';
        else if (i == 3) color ='o';
        else if (i == 4) color ='g';
        else if (i == 5) color ='b';
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                cube[i][j][k] = color;
                if (i==1) cube[i][j][k] = n++;
            }
        }
    }
}

void rotateU() {
    int tmp = cube[3][0][2];
    //left
    cube[3][0][2] = cube[4][0][0];
    cube[4][0][0] = cube[4][0][1];
    cube[4][0][1] = cube[4][0][2];
    //down
    cube[4][0][2] = cube[2][0][1];
    cube[2][0][1] = cube[2][0][2];
    cube[2][0][2] = cube[5][0][0];
    //right
    cube[5][0][0] = cube[5][0][1];
    cube[5][0][1] = cube[5][0][2];
    cube[5][0][2] = cube[3][0][0];
    //up
    cube[3][0][0] = cube[3][0][1];
    cube[3][0][1] = tmp;
}

void rotateD() {
    int tmp = cube[2][0][];
    //left
    cube[3][0][2] = cube[4][0][0];
    cube[4][0][0] = cube[4][0][1];
    cube[4][0][1] = cube[4][0][2];
    //down
    cube[4][0][2] = cube[2][0][1];
    cube[2][0][1] = cube[2][0][2];
    cube[2][0][2] = cube[5][0][0];
    //right
    cube[5][0][0] = cube[5][0][1];
    cube[5][0][1] = cube[5][0][2];
    cube[5][0][2] = cube[3][0][0];
    //up
    cube[3][0][0] = cube[3][0][1];
    cube[3][0][1] = tmp;
}

void rotate(int face, bool clock) {
    int n=1;
    if (!clock) n=3;
    for (int i=0; i<n; i++) {
        for (int i=0; i<2; i++) {
            int idx = 0;
            int tmp = cube[face][0][0];
            cube[face][0][0] = cube[face][1][0];
            cube[face][1][0] = cube[face][2][0];

            cube[face][2][0] = cube[face][2][1];
            cube[face][2][1] = cube[face][2][2];
            cube[face][2][2] = cube[face][1][2];
            
            cube[face][1][2] = cube[face][0][2];
            cube[face][0][2] = cube[face][0][1];
            cube[face][0][1] = tmp;

            if (face == 0) rotateU();
            else if (face == 1) rotateD();
            else if (face == 2) rotateF();
            else if (face == 3) rotateB();
            else if (face == 4) rotateL();
            else if (face == 5) rotateR();
        }
    }
}

void print_faces() {
    for (int i=0; i<6; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                cout << cube[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    make_faces();
    print_faces();
    rotate(1, false);
    print_faces();
    // int testcase;
    // scanf("%d", &testcase);
    // for (int t=0; t<testcase; t++) {
    //     vector<vector<vector<char>>> cube;
    //     cube.clear();
    //     int ro;
    //     scanf("%d", &ro);
    //     for (int r=0; r<ro; r++) {
    //         string str;
    //         getline(cin, str);
    //     }
    // }
    
    return 0;
}