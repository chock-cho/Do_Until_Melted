#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pi;
const int dr[]={-1, 0, 1, 0};
const int dc[]={0, 1, 0, -1};
int n,k;
int grid[101][101];
bool vis[101][101];
queue<pi> q;
int cnt= 0;

bool inGrid(int x, int y){
    return (x>=1)&&(x<=n)&&(y>=1)&&(y<=n);
}

bool canGo(int x, int y){
    if(!inGrid(x,y)) return false;
    if(vis[x][y]) return false;
    if(grid[x][y]==1) return false;
    return true;
}

int main() {
    cin >>n>> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    int r, c;
    while(k--){
        cin >> r >> c;
        if(canGo(r,c)) cnt+=1;

        vis[r][c]= true;
        q.push(make_pair(r,c));
        while(!q.empty()){
            int r = q.front().first;
            int c= q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r +dr[i];
                int nc = c +dc[i];

                if(!canGo(nr,nc)) continue;
                cnt+=1;
                vis[nr][nc] =true;
                q.push(make_pair(nr,nc));
            }
        }
    }
    cout << cnt;
    return 0;
}