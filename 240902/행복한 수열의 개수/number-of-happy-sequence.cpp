#include <iostream>
using namespace std;
int n, m;
int grid[101][101];
int ans1, ans2=0;
int sol(){
    int cnt1; // 열 비교
    for(int r = 0; r < n; r++){
       cnt1 =1; bool flag = false; // 해당 열에서 이미 겹치는 수가 나왔나
        for(int c = 1; c < n; c++){
            if(grid[r][c-1]==grid[r][c]){ 
                cnt1+=1; flag=true;
                if(cnt1 >= m) {
                    ans1++; break;
                }
            }
            else if(flag) cnt1= 1;
        }
    }
    int cnt2; // 행 비교
    for(int c = 0; c < n; c++){
        cnt2= 1; bool flag = false;
        for(int r =1; r <n; r++){
            if(grid[r-1][c]==grid[r][c]) {
                cnt2+=1; flag = true;
                if(cnt2 >= m) {
                    ans2++; break;
                }
            }
            else if(flag) cnt2=1;
        }
    }
    return ans1+ans2;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    if(m==1) {
        cout << n+n; return 0;
    }
    cout << sol();
    return 0;
}