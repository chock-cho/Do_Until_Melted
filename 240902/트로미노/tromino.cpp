#include <iostream>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int grid[201][201];
int n, m;
int ans = -987654321;

bool isValid(int x, int y){
    return (x>=0)&&(y>=0)&&(x<n)&&(y<m);
}

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

            if(i+2 < n) {
                tmp = grid[i][j]+grid[i+1][j]+grid[i+2][j];
                ans = max(tmp, ans);
            }

            if(j+2 < m){
                tmp = grid[i][j]+grid[i][j+1]+grid[i][j+2];
                ans = max(tmp, ans);
            }

            for(int k = 0; k < 4; k++){
                int nx1= i + dx[k];
                int ny1= j + dy[k];

                int nx2= i+ dx[(k+1)%4];
                int ny2= j+ dy[(k+1)%4];

                if(!isValid(nx1, ny1) || !isValid(nx2, ny2)) continue;
                tmp = grid[i][j]+grid[nx1][ny1]+grid[nx2][ny2];
                ans = max(tmp, ans);  
            }

        }
    }
    cout << ans;
    return 0;
}