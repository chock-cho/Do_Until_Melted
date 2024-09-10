#include <iostream>
using namespace std;
const int BLANK = 0;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n;
int grid[201][201];
int tmp[201][201];
int r, c;

bool inGrid(int x, int y){
    return (x>=1)&&(x<=n)&&(y>=1)&&(y<=n);
}

void bomb(int x, int y){
    int bomb_size = grid[x][y];
    int st_x = x; int st_y=y;
    grid[x][y] = BLANK;
    //cout << x << ", " << y <<'\n';
    for(int cnt = 0; cnt < bomb_size; cnt++){
        for(int dir = 0; dir < 4; dir++){
            int x_idx= st_x+(cnt*dx[dir]); 
            int y_idx= st_y+(cnt*dy[dir]);
            if(!inGrid(x_idx, y_idx)) continue;
            grid[x_idx][y_idx] = BLANK;
        }
    }
    return;
}

void gravity(){
    for(int c = 1; c <= n; c++){
        int tmp_row = n+1;
        for(int r = n; r >= 1; r--){
            if(grid[r][c] != BLANK){
                tmp_row--;
                tmp[tmp_row][c] = grid[r][c];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << tmp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> n;
    for(int i =1; i <= n; i++){
        for(int j =1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    cin >> r >> c;
    bomb(r, c); gravity();
    return 0;
}