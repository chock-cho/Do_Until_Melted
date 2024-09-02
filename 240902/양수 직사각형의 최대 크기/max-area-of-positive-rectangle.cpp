#include <iostream>
using namespace std;
int n, m;
int grid[21][21];
int w, h; // 너비:w, 높이:h
int ans = -987654321;

bool chk(int x, int y, int w, int h){
    for(int i = x; i < x+w; i++){
        for(int j = y; j < y+h; j++){
            if(grid[i][j]<=0) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            for(int w = 1; w <= n; w++){
                for(int h = 1; h <= m; h++){
                    if(i+w <= n && j+h <= m && chk(i, j, w, h)) {
                        flag = true;
                        ans = max(ans, w*h);
                    }
                }
            }
        }
    }
    if(!flag) {
        cout << -1 << "\n"; return 0;
    }
    cout << ans;
    return 0;
}