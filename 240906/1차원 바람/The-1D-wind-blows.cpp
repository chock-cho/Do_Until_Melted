#include <iostream>
using namespace std;
int N, M, Q;
int grid[104][104];
string priorDir;
void leftPush(int r){
    priorDir = "L";
    int tmp = grid[r][M]; 
    for(int col = M; col >= 2; col--){
        grid[r][col]= grid[r][col-1];
    }
    grid[r][1]= tmp;
}

void rightPush(int r){
    priorDir = "R";
    int tmp = grid[r][1];
    for(int col = 1; col < M; col++){
        grid[r][col] = grid[r][col+1];
    }
    grid[r][M] = tmp;
}

bool blowChk(int K, int r){
    for(int i = 1; i <= M; i++){
        if(grid[K][i]==grid[r][i]) return true;
    }
    return false;
}

void upBlow(int r){
    if(r <= 1) return;
    if(!blowChk(r-1, r)) return;
    if(r >= 2 && blowChk(r-1, r)){
        (priorDir == "L")? rightPush(r-1) : leftPush(r-1);
        upBlow(r-1);
        return;
    }
    return;
}

void downBlow(int r, string originDir, int cnt){  
    if(r >= N) return;
   if(cnt==0) priorDir = originDir; 
    if(!blowChk(r+1, r)) return;
    if(r <= N-1 && blowChk(r+1, r)){
        (priorDir == "L")? rightPush(r+1) : leftPush(r+1);
       downBlow(r+1, priorDir, cnt);
       return;
    }
    return;
}

void windBlow(int r, string originDir){
    int r1 = r;
    int r2 = r;
    upBlow(r1);
    downBlow(r2, originDir, 0); 
}

int main() {
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> grid[i][j];
        }
    }
    while(Q--){
        priorDir = "";
        string cmd="";
        string originDir="";
        int row;
        cin >> row >> cmd;
        (cmd == "L")? leftPush(row) : rightPush(row);
        originDir = priorDir; 
        windBlow(row, originDir); 
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}