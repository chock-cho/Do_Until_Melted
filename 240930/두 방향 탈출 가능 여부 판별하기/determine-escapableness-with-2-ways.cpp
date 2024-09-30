#include <iostream>
using namespace std;
const int dx[]= {1, 0};
const int dy[]={0, 1};
int grid[101][101];
int vis[101][101]={0};
int n, m;

bool inRange(int x, int y){
    return (x>=0)&&(x<n)&&(y>=0)&&(y<m);
}

bool canGo(int x, int y){
    return (inRange(x,y)) && (vis[x][y]==0) && (grid[x][y]!=0);
}

void dfs(int x, int y){
    for(int i = 0; i < 2; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(!canGo(nx,ny)) continue;
        vis[nx][ny]+=1;
        dfs(nx,ny);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    dfs(0,0);
    if(vis[n-1][m-1]>0) {
        cout << "1\n"; return 0;
    }
    else cout << vis[n-1][m-1];
    return 0;
}