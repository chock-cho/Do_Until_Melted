#include <iostream>
using namespace std;
int N, M, Q;
int grid[104][104];
string priorDir;
int cnt = 0;
void leftPush(int r){
    priorDir = "L";
    int tmp = grid[r][M]; //cout << tmp << "\n";
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

bool upChk(int r){
    for(int i = 1; i <= M; i++){
        if(grid[r-1][i]==grid[r][i]) return true;
    }
    return false;
}

bool blowChk(int K, int r){
    for(int i = 1; i <= M; i++){
        if(grid[K][i]==grid[r][i]) return true;
    }
    return false;
}

void upBlow(int r){
    if(r >= 2 && blowChk(r-1, r)){
        if(priorDir == "L") rightPush(r-1);
        else leftPush(r-1);
        upBlow(r-1);
    }
    return;
}

void downBlow(int r, string originDir){  
    if(cnt==0) priorDir = originDir;
    if(r <= M && blowChk(r+1, r)){
        //cout << blowChk << "\n";
        if(priorDir == "L") rightPush(r+1);
        else leftPush(r+1);
        downBlow(r+1, priorDir);
    }
    return;
}

void windBlow(int r, string originDir){
    upBlow(r); downBlow(r, originDir);
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
        int r; string cmd="";
        string originDir="";
        cin >> r >> cmd;
        if(cmd == "L"){
            leftPush(r);
        }
        else if(cmd == "R"){
            rightPush(r);
        }
        originDir = priorDir;
        windBlow(r, originDir);
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}