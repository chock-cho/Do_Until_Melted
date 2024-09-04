#include <iostream>
using namespace std;
int n, t;
int grid[3][202];

int main() {
    cin >> n >> t;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    while(t--){
        int tmp1, tmp2, tmp3=0;
        tmp1= grid[0][n-1]; 
        tmp2= grid[1][n-1]; 
        tmp3= grid[2][n-1];
        for(int i = 0; i < 3; i++){
            for(int j = n-1; j>=1; j--){
                grid[i][j] = grid[i][j-1];
            }
        }
        grid[0][0]= tmp3;
        grid[1][0]= tmp1;
        grid[2][0]= tmp2;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}