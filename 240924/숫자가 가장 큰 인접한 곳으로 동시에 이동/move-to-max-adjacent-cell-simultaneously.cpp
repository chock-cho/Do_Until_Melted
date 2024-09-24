#include <iostream>
#include <queue>
using namespace std;
const int dx[]={-1, 1, 0, 0}; //상하좌우
const int dy[]={0, 0, -1, 1};
int grid[101][101];
int nxt_grid[101][101];
int n, m, t;
queue<pair<int,int>> cq, nq;

bool inGrid(int x, int y){
    return (x>=1)&&(x<=n)&&(y>=1)&&(y<=n);
}

void init_nxt(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            nxt_grid[i][j]=0;
        }
    }
}

void decide_cq(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(nxt_grid[i][j]==1) cq.push({i,j});
        }
    }
}

void simul(){
    init_nxt();
    while(!cq.empty()){
        int x= cq.front().first; 
        int y= cq.front().second;
        cq.pop();
        int nx, ny=0;
        int nxt_val=-987654321;
        for(int k = 0; k < 4; k++){
            if(!inGrid(x+dx[k], y+dy[k])) continue;
            if(grid[x+dx[k]][y+dy[k]] < nxt_val) continue;
            nx = x+dx[k]; ny = y+dy[k];
        }
       // cout << nx << ", " << ny <<"\n";
        nxt_grid[nx][ny]+=1;
    }
    cout << "\n";
   //return nq.size();
}

int main() {
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    while(m--){
        int r, c;
        cin >> r >> c;
        nxt_grid[r][c]=1;
    }
    queue<pair<int,int>> q;
    for(int i = 0; i < t; i++){
        decide_cq();
        simul();
        cq = nq;
        nq = q;
    }
    decide_cq();
    cout << cq.size();
    return 0;
}