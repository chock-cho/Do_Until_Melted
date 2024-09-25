#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int dr[]={-1, 0, 1, 0, 1, 1, -1, -1};
const int dc[]={0, 1, 0, -1, 1, -1, 1, -1};
int n, m;
int grid[101][101];


bool inGrid(int x, int y){
    return (1<=x)&&(x<=n)&&(1<=y)&&(y<=n);
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

pair<int,int> find_target(int target){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j] == target){
                return make_pair(i,j);
            }
        }
    }
}

void simul(int r, int c){
    int nr,nc = 0;
    int cur_max=-987654321;
    for(int i = 0; i < 8; i++){
        if(!inGrid(r+dr[i],c+dc[i])) continue;
        if(cur_max >= grid[r+dr[i]][c+dc[i]]) continue;
        nr = r +dr[i];
        nc = c +dc[i];
        cur_max = grid[nr][nc];
    }
    swap(grid[r][c], grid[nr][nc]);
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    for(int turn = 0; turn < m; turn++){
        for(int i = 1; i <= n*n; i++){
            int x = find_target(i).first;
            int y = find_target(i).second;
            simul(x, y);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}