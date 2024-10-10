#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
int n,k;
queue<pair<int,int>> q;
int grid[101][101];

bool inGrid(int x, int y){
    return (x>=1)&&(x<=n)&&(y>=1)&&(y<=n);
}

int main() {
    cin >> n >>k;
    vector<vector<int>> vis(n+1, vector<int>(n+1, -1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
            if(grid[i][j]==2) {
                q.push(make_pair(i,j)); vis[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first; int y= q.front().second;
        //cout << "queue: (" << x << ", " << y << ")\n";
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx=x+dx[i]; int ny=y+dy[i];
            //cout << "nx,ny : " << nx << " , " << ny << "\n";
            if(!inGrid(nx, ny)) continue;
            //cout << "nx,ny : " << nx << " , " << ny << "\n";
            if(vis[nx][ny]!=-1) continue;
            //cout << "nx,ny : " << nx << " , " << ny << "\n";
            if(grid[nx][ny]!=1) continue;
            vis[nx][ny]=vis[x][y]+1;
            q.push(make_pair(nx,ny));
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j =1; j <= n; j++){
            if(vis[i][j]==-1 && grid[i][j]==1) vis[i][j]=-2;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j =1; j <= n; j++){
            cout << vis[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}