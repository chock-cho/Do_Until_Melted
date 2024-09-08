#include <iostream>
using namespace std;
int N, m, k;
int grid[101][101];

void print(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

void blockDrop(){
    int i;
    for(i = 2; i <= N; i++){
        bool flag = true;
        for(int j = k; j <= m; j++){
            if(j+k <= N && grid[i][j]==0) {
                continue;
            }
            else {
                flag = false;
            }
        }
        if(flag) {
            for(int j = 0; j < m; j++){
                grid[i-1][k+j] = 0;
                grid[i][k+j] = 1;
                //cout << grid[i][k+j];
            }
        }
        else {
            print(); return;
        }
    }
    print(); return;
}

int main() {
    cin >> N >> m >> k;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = k; i <= m; i++){
        grid[1][i] = 1;
    }
    blockDrop();
    return 0;
}