#include <iostream>
#include <queue>
using namespace std;
const int dx[]={-2, -1, 2, -1, 2, -2, 1, 1};
const int dy[]={-1, -2, 1, 2, -1, 1, 2, -2};
queue<pair<int,int>> q;
int n;
int r1, c1, r2, c2;
int vis[101][101];

bool inGrid(int x, int y){
    return (x>=1)&&(x<=n)&&(y>=1)&&(y<=n);
}

void bfs(){
    vis[r1][c1]=0;
    q.push({r1,c1});
    while(!q.empty()){
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(!inGrid(nx,ny)) continue;
            if(vis[nx][ny] != -1) continue;
            vis[nx][ny] = vis[x][y]+1;
            q.push({nx,ny});
        }
    }
}
int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            vis[i][j] = -1;
        }
    }
    bfs();
    cout << vis[r2][c2];
    return 0;
}