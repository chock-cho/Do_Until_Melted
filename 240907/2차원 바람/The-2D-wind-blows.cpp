#include <iostream>
using namespace std;
int N, M, Q;
int grid[104][104];
int res[104][104]={0};
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void rotate(int r1, int c1, int r2, int c2){
    int tmp1, tmp2, tmp3, tmp4;

    tmp1 = grid[r1][c2]; 
    for(int i = c2; i > c1; i--){
        grid[r1][i] = grid[r1][i-1];
    }

    
    tmp2 = grid[r2][c2];
    for(int i = r2; i > r1; i--){
        grid[i][c2] = grid[i-1][c2];
    }

    tmp3 = grid[r2][c1];
    for(int i = c1; i <= c2-1; i++){
        grid[r2][i] = grid[r2][i+1];
    }

    tmp4= grid[r1][c1];
    for(int i = r1; i <= r2-1; i++){
        grid[i][c1] = grid[i+1][c1];
    }

    grid[r1+1][c2] = tmp1;
    grid[r2][c2-1]= tmp2;
    grid[r2-1][c1] = tmp3;
    grid[r1][c1+1]= tmp4;
}

bool inGrid(int x, int y){
    return (x >= 1 && x <= N) && (y >= 1 && y <= M);
}

void copyArray(int dst[][104],int src[][104]){
    for(int i = 1; i <= N+1; i++){
        for(int j = 1; j <= M+1; j++){
            if(src[i][j] != 0)
                dst[i][j] = src[i][j];
        }
    }
}

int calc(int x, int y){
    int sum, cnt=0;
    sum = grid[x][y]; 
    cnt = 1;
    for(int k = 0; k < 4; k++){
        int nx = x +dx[k];
        int ny = y +dy[k];
        if(!inGrid(nx, ny)) continue;
        sum += grid[nx][ny]; cnt+=1;
    }
    return (int)(sum / cnt); 
}

int main() {
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> grid[i][j];
        }
    }
    int r1, r2, c1, c2;
    while(Q--){
        cin >> r1 >> c1 >> r2 >> c2;
        rotate(r1, c1, r2, c2); copyArray(res, grid); 
        for(int i = r1; i <= r2; i++){
            for(int j = c1; j <= c2; j++){
                res[i][j] = calc(i, j);
            }
        } 
        copyArray(grid, res);
    }
   
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}