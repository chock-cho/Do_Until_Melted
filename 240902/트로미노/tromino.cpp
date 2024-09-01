#include <iostream>
#include <algorithm>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;
int grid[201][201];
int ans = -987654321;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int tmp = 0;
            if(i+2 < n){
                tmp = grid[i][j] + grid[i+1][j] + grid[i+2][j];
                ans = max(tmp, ans);
            }

            if(j+2 < m){
                tmp = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                ans = max(tmp, ans);
            }

            for(int k = 0; k < 4; k++){
                int nx_1 = i + dx[k];
                int ny_1 = j + dy[k];

                int nx_2 = i + dx[(k+1)%4];
                int ny_2 = j + dy[(k+1)%4];

                if(nx_1 < 0 || nx_2 < 0 || nx_1 >= n || nx_2 >= m 
                || ny_1 < 0 || ny_2 < 0 || ny_1 >= n || ny_2 >= m) continue;

                tmp = grid[i][j] + grid[nx_1][ny_1] + grid[nx_2][ny_2];
                ans = max(tmp, ans);
            }
        }
    }
    cout << ans;
    return 0;
}