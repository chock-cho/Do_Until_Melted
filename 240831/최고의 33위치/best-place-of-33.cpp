#include <iostream>
using namespace std;
int N;
int grid[21][21];
int ans = -987654321;
void sol(int st_x, int st_y, int en_x, int en_y){
    int sum = 0;
    for(int i = st_x; i <= en_x; i++){
        for(int j = st_y; j <= en_y; j++){
            //cout << grid[i][j] << " ";
            sum += grid[i][j];
        }
        //cout << "\n";
    }
    if(ans < sum) ans = sum;
}
int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i+2 >= N || j+2 >= N) continue;
            sol(i, j, i+2, j+2);
        }
    }
    cout << ans;
    return 0;
}