#include <iostream>
using namespace std;
int n, m;
int grid[101][101];
int ans=0;
int sol(){
    int cnt1; // 열 비교
    for(int r = 0; r < n; r++){
       cnt1 =1;
        for(int c = 1; c < n; c++){
            if(grid[r][c-1]==grid[r][c]) cnt1+=1;
        }
        //cout << cnt1 << " \n";
        if(cnt1 >= m) ans++;
    }
    int cnt2; // 행 비교
    for(int c = 0; c < n; c++){
        cnt2= 1;
        for(int r =1; r <n; r++){
            if(grid[r-1][c]==grid[r][c]) cnt2+=1;
        }
        //cout << cnt2 << "\n";
        if(cnt2 >= m) ans++;
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    cout << sol();
    return 0;
}