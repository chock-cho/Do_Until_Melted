#include <bits/stdc++.h>
using namespace std;

const int dc[]={-1, 0, 1, 0};
const int dr[]={0, 1, 0, -1};

int C, R;
int answer = -1e9;
int vis[51][51];
char grid[51][51];

bool inGrid(int c, int r){
    return (0<=c && c<C && 0<=r && r<R);
}

void bfs(int st_c, int st_r){
    memset(vis, 0, sizeof(vis));
    queue<pair<int,int>> q;
    vis[st_c][st_r]=1; 
    q.push(make_pair(st_c,st_r));
    
    while(!q.empty()){
        int c,r;
        tie(c,r)=q.front(); q.pop();
        answer= max(answer, vis[c][r]);
        for(int i = 0; i < 4; i++){
            int nc= c+dc[i]; int nr=r+dr[i];
            if(inGrid(nc,nr) && vis[nc][nr] ==0 && grid[nc][nr] == 'L') {
                vis[nc][nr]=vis[c][r]+1;
                q.push(make_pair(nc,nr));
            }
        }
    }
}

int main(){
    cin >> C >> R;
    for(int c = 0; c < C; c++){
        for(int r= 0; r < R; r++){
            cin >> grid[c][r];
        }
    }
    for(int c= 0; c < C; c++){
        for(int r = 0; r <R; r++){
            if(grid[c][r] == 'L') bfs(c,r);
        }
    }
    cout << answer-1;
    return 0;
}