#include <iostream>
using namespace std;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};
int n, r, c;
int grid[101][101];

bool insideGrid(int x, int y){
    return (1 <= x && x <= n) && (1 <= y && y <= n); 
}

void move(int r, int c){
    cout << grid[r][c] << " ";
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(grid[nr][nc] > grid[r][c] && insideGrid(nr, nc)){
            move(nr,nc); return;
        }
    }
    return;
}

int main() {
    cin >> n >> r >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    move(r,c);
    return 0;
}