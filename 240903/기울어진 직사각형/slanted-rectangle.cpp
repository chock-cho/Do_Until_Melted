#include <iostream>
using namespace std;
const int dx[] = {-1, -1, 1, 1};
const int dy[] = {1, -1, -1 ,1};
int grid[21][21];
int n;
int answer = 0;
int w, h;
bool inSideGrid(int x, int y){
    return (x>=0)&&(y>=0)&&(x<n)&&(y<n);
}

int sol(int x, int y, int w, int h){
    int ans = 0;
    for(int i = 0; i < 4; i++){ //4번 탐색

        if(i==0 || i==2) { //w만큼 이동
            for(int j = 0; j < w; j++){
                x +=dx[i];
                y +=dy[i];
                if(!inSideGrid(x,y)) return -1;
                ans += grid[x][y];
            }
        }
        else {
            for(int j = 0; j < h; j++){
                x +=dx[i];
                y +=dy[i];
                if(!inSideGrid(x,y)) return -1;
                ans += grid[x][y];
            }
        }
    }
    return ans;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            for(int w=1; w <n; w++){
                for(int h=1; h <n; h++){
                    if(answer < sol(i, j, w, h)){
                        answer = sol(i, j, w, h);
                    }
                }
            }

        }
    }
    cout << answer;
    return 0;
}