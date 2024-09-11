#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pi;
const int dx[]= {-1, 0, 1, 0};
const int dy[]={0, 1, 0, -1};
queue<pi> q;
int n, m;
int grid[101][101];
bool vis[101][101];

bool inGrid(int x, int y){
    return (x>=0)&&(x<n)&&(y>=0)&&(y<m);
}


int bfs(){
    q.push(make_pair(0,0));
    vis[0][0] = true;
    while(!q.empty()){
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        if(x==n-1 && y==m-1) return 1;

        for(int i = 0; i < 4; i++){
            int nx= x+dx[i];
            int ny= y+dy[i];
            if(!inGrid(nx,ny)) continue;
            if(vis[nx][ny]) continue;
            if(grid[nx][ny]==0) continue;

            vis[nx][ny] = true;
            q.push(make_pair(nx,ny));
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    cout << bfs();
    return 0;
}