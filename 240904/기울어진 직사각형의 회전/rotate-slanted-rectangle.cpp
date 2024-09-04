#include <iostream>
#include <vector>
using namespace std;
const int dx1[]= {-1, -1, 1, 1};
const int dy1[]= {1, -1, -1, 1};

const int dx2[]= {-1, -1, 1, 1};
const int dy2[]= {-1, 1, 1, -1};
 
int n;
int grid[101][101];
int tmp[101][101];
int r, c, m1, m2, m3, m4, dir;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++){
            tmp[i][j] = grid[i][j];
        }
    }
    // 3 2 4        
    // 1   3   = >
    // 3 3 3
    cin >> r >> c >> m1 >> m2 >> m3 >> m4>> dir;
    int move_dir[]={m1, m2, m3, m4};
    if(dir==0){ // 반시계
        for(int i = 0; i < 4; i++){

            for(int j =0 ; j< move_dir[i]; j++){
                int nr, nc=0;
                nr = r+ dx1[i]; nc = c+dy1[i];
                tmp[nr][nc]= grid[r][c];
                r= nr; c= nc;
            }
        }
    }
    if(dir==1){ // 시계
        for(int i =0; i < 4; i++){
            for(int j =0 ; j< move_dir[3-i]; j++){
                int nr, nc=0;
                nr = r+ dx2[i]; nc = c+dy2[i];
                tmp[nr][nc]= grid[r][c];
                r= nr; c= nc;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << tmp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}