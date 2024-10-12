#include <iostream>
#include <vector>
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
int N, M;
int grid[101][101];
int K= -987654321;
int cnt=0;
int ans_cnt = -987654321;
int ans_st =0;

bool inRange(int x, int y){
    return (x>=1)&&(x<=N)&&(y>=1)&&(y<=M);
}

void findSafe(int x, int y, int t, vector<vector<bool>>&vis){
    for(int i = 0; i < 4; i++){
        int nx=x+dx[i]; int ny=y+dy[i];
        if(!inRange(nx,ny)) continue;
        if(vis[nx][ny]) continue;
        if(grid[nx][ny]<=t) continue;
        vis[nx][ny]=true; 
        findSafe(nx,ny, t, vis);
    }
    return;
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j =1; j <= M; j++) {
            cin >> grid[i][j];
            K = max(K, grid[i][j]);
        }
    }
    for(int t = 1; t <= K; t++){
        cnt=0;
        vector<vector<bool>> vis(N+1, vector<bool>(M+1, false));
        for(int i = 1; i <= N; i++){
            for(int j =1; j <= M; j++){
                if(!vis[i][j] && grid[i][j] > t) {
                    findSafe(i,j,t,vis); cnt+=1;
                }
            }
        }
        if(ans_cnt < cnt) { ans_cnt=cnt; ans_st =t; }
    }
    cout << ans_st << " " << ans_cnt;
    return 0;
}