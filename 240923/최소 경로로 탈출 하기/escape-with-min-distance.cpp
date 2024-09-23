#include <iostream>
#include <queue>
using namespace std;
const int dx[]= {-1, 0, 1, 0};
const int dy[]= {0, 1, 0, -1};
int n, m;
int grid[101][101];
int vis[101][101]={-1,};
queue<pair<int,int>> q;

bool inGrid(int x, int y){
    return (x>=0)&&(x<n)&&(y>=0)&&(y<m);
}

void bfs(){
    while(!q.empty()){
        int x= q.front().first; 
        int y= q.front().second;
        q.pop();
        int nx, ny;
        for(int i = 0; i < 4; i++){
            nx = x+dx[i];
            ny = y+dy[i];
            if(!inGrid(nx,ny)) continue;
            if(vis[nx][ny]!= -1 || grid[nx][ny]!=1) continue;
            vis[nx][ny] = vis[x][y] +1;
            //cout << nx << " , " << ny << " : " << vis[nx][ny] << "\n"; 
            q.push(make_pair(nx,ny));
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j =0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vis[i][j] = -1;
        }
    }
    vis[0][0] = 0;
    q.push(make_pair(0,0));
    bfs();

    cout << vis[n-1][m-1];
    return 0;
}