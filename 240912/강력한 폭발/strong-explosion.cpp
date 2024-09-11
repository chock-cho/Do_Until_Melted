#include <iostream>
#include <vector>
using namespace std;
int n;
typedef pair<int,int> pi;
int grid[21][21];
int isBomb[21][21];
vector<pi> bombLoc;
int ans=0;

bool inGrid(int x, int y){
    return (x>=1)&&(x<=n)&&(y>=1)&&(y<=n);
}

void bomb1(int x, int y){
    for(int i = 1; i <= 2; i++){
        if(inGrid(x-i, y)) isBomb[x-i][y]++;
        if(inGrid(x+i, y)) isBomb[x+i][y]++;
    }
   
}
void bomb1_rollback(int x, int y){
    for(int i = 1; i <= 2; i++){
        if(inGrid(x-i, y)) isBomb[x-i][y]--;
        if(inGrid(x+i, y)) isBomb[x+i][y]--;
    }
}

void bomb2(int x, int y){
    int dx[]={-1, 0, 1, 0};
    int dy[]={0, 1, 0, -1};
    for(int i= 0; i < 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(inGrid(nx,ny)) isBomb[nx][ny]++;
    }
}

void bomb2_rollback(int x, int y){
    int dx[]={-1, 0, 1, 0};
    int dy[]={0, 1, 0, -1};
    for(int i= 0; i < 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(inGrid(nx,ny)) isBomb[nx][ny]--;
    }
}

void bomb3(int x, int y){
    int dx[]= {-1, -1, 1, 1};
    int dy[]= {1, -1, 1, -1};
    for(int i =0; i < 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(inGrid(nx,ny)) isBomb[nx][ny]++;
    }
}

void bomb3_rollback(int x, int y){
    int dx[]= {-1, -1, 1, 1};
    int dy[]= {1, -1, 1, -1};
    for(int i =0; i < 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(inGrid(nx,ny)) isBomb[nx][ny]--;
    }
}

void sol(int cur){
    if(cur == bombLoc.size()){
        int cur_cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(isBomb[i][j]>0) cur_cnt++;
            }
        }
        ans = max(ans, cur_cnt);
        return;
    }

    for(int i = 0; i < bombLoc.size(); i++){
        int cur_x = bombLoc[i].first;
        int cur_y = bombLoc[i].second;

        for(int type = 1; type <= 3; type++){
            if(type == 1){
                bomb1(cur_x,cur_y);
                sol(cur+1);
                bomb1_rollback(cur_x, cur_y);
            }
            else if(type == 2){
                bomb2(cur_x,cur_y);
                sol(cur+1);
                bomb2_rollback(cur_x, cur_y);
            }
            else if(type == 3){
                bomb3(cur_x, cur_y);
                sol(cur+1);
                bomb3_rollback(cur_x,cur_y);
            }
        }
    }

}

int main() {
    cin>> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
            if(grid[i][j]==1) {
                bombLoc.push_back({i,j});
                isBomb[i][j]++;
            }
        }
    }
    sol(0);
    cout << ans;
    return 0;
}