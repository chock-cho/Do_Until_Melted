#include <iostream>
using namespace std;
int N, M, Q;
int grid[104][104];
string priorDir;

void leftPush(int r){
    int tmp = grid[r][M]; //cout << tmp << "\n";
    for(int col = M; col >= 2; col--){
        grid[r][col]= grid[r][col-1];
    }
    grid[r][1]= tmp;
    priorDir = "L";
}

void rightPush(int r){
    int tmp = grid[r][1];
    for(int col = 1; col < M; col++){
        grid[r][col] = grid[r][col+1];
    }
    grid[r][M] = tmp;
    priorDir = "R";
}

void downsidePropagate(int r, string originDir){
    bool downsideFlag = false;
    // r행 기준으로 아래쪽
    if(originDir == "L") priorDir= "L";
    else priorDir = "R";
    for(int row = r+1; row <= N; row++){
        for(int col = 1; col <= M; col++){
            if(grid[row][col] == grid[r][col]){
                downsideFlag = true; 
                if(priorDir == "L") {
                    rightPush(row); r = row; continue;
                }
                if(priorDir == "R"){
                    leftPush(row); r = row; continue;
                }
            }
            if(!downsideFlag) return;
        }
    }
    return;
}

void upsidePropagate(int r){
    bool upsideFlag= false; int originRow= r;
    string originDir = priorDir;
    // r행 기준으로 위쪽
    for(int row = r-1; row >= 1; row--){
        for(int col = 1; col <= M; col++){
            if(grid[row][col] == grid[r][col]){
                upsideFlag = true;
                if(priorDir == "L") {
                    rightPush(row);  r= row; continue;
                }
                if(priorDir == "R"){
                    leftPush(row); r= row; continue;
                }
            }
            if(!upsideFlag) downsidePropagate(originRow, originDir);
        }
    }
    downsidePropagate(originRow, originDir);
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
        cin >> r >> cmd;
        if(cmd == "L"){
            leftPush(r);
            upsidePropagate(r);
        }
        else if(cmd == "R"){
            rightPush(r);
            upsidePropagate(r);
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}