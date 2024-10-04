#include <iostream>
#include <algorithm>
using namespace std;
int n;
int grid[301][301];
int psum[301][301];
//x, y, w, h
int ans = -98754321;

bool inGrid(int x, int y){
    return (x>=1)&&(x<=n)&&(y>=1)&&(y<=n);
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    psum[0][0]=0; psum[1][1]=grid[1][1];
    for(int i = 2; i <= n; i++){
        psum[1][i]=psum[1][i-1]+grid[1][i];
        psum[i][1]=psum[i-1][1]+grid[i][1];
    }

    for(int x = 2; x <= n; x++){
        for(int y = 2; y <=n; y++){
            psum[x][y]=grid[x][y]+psum[x-1][y]+psum[x][y-1]-psum[x-1][y-1];
        }
    }
    // for(int x= 0; x <= n; x++){
    //     for(int y= 0; y <= n; y++){
    //         // st좌표: (x,y)
    //         for(int w = 1; w <=n-x; w++){
    //             for(int h = 1; h <=n-y; h++){
    //                 if(!inGrid(x+w, y+h)) continue;
    //                 int cur = psum[x+w][y+h]-(psum[x+w][y]+psum[x][y+h])+psum[x][y];
    //                 if(ans < cur){
    //                     ans= cur;
    //                 }
                    
    //             }
    //         }
    //     }
    // }
    // (x1, x2) 고정 시에 열 
   for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(j-k >= 0){
                    ans = max(ans, psum[i][j]-psum[i][j-k]);
                }
                if(i-k >= 0){
                    ans = max(ans, psum[i][j]-psum[i-k][j]);
                }
                if(j-k >= 0 && i-k >= 0){
                    ans = max(ans, psum[i][j]-(psum[i-k][j]+psum[i][j-k])+psum[i-k][j-k]);
                }
            }
        }
   }
    cout << ans;
    return 0;
}