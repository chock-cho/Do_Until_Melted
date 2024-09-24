#include <iostream>
#include <queue>
using namespace std;
const int dx[]={-1, 1, 0, 0};
const int dy[]={0, 0, -1, 1};
int n, m, t;
int grid[101][101];
int mark[101][101];
queue<pair<int,int>> q;
int answer = 0;

void mark_init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mark[i][j] = 0;
        }
    }
}

bool inGrid(int x, int y){
    return (x>=1)&&(x<=n)&&(y>=1)&&(y<=n);
}

void count_marble(){
    answer = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mark[i][j]==1) {
                answer++;
                q.push(make_pair(i,j));
            } 
        }
    }
}

void simul(){
    mark_init();
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int nx, ny = 0;
        int max_ans=-987654321;
        for(int i = 0; i < 4; i++){
            if(!inGrid(x+dx[i], y+dy[i])) continue;
            if(max_ans < grid[x+dx[i]][y+dy[i]]){
                nx = x+dx[i];
                ny = y+dy[i];
                max_ans = grid[x+dx[i]][y+dy[i]];
            }
        }
        mark[nx][ny]+=1;
    }
    count_marble();
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
        q.push({r,c});
    }
    while(t--){
        simul();
    }
    cout << answer << "\n";
    return 0;
}