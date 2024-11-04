#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INT_MAX 101
int n;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
int grid[INT_MAX][INT_MAX];
bool vis[INT_MAX][INT_MAX];
int bombedCnt, answer=0;
int blockCnt=0;

bool inGrid(int x, int y){
    return (x>=0)&&(x<n)&&(y>=0)&&(y<n);
}

void dfs(int depth, int x, int y){
    for(int i = 0; i < 4; i++){
        int nx=x+dx[i]; int ny=y+dy[i];
        if(vis[nx][ny] || !inGrid(nx,ny)) continue;
        if(grid[x][y]!=grid[nx][ny]) continue;
        vis[nx][ny]=true; blockCnt+=1;
        dfs(depth+1, nx, ny); 
    }
    return;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    bool flag;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cur_block=0;
            if(!vis[i][j]) {
                blockCnt=1;
                vis[i][j]=true;
                dfs(1, i, j);
                (blockCnt>=4)? bombedCnt+=1 : bombedCnt;
                if(answer < blockCnt) answer=blockCnt;
            }
        }
    }
    cout << bombedCnt << " " << answer;
    return 0;
}