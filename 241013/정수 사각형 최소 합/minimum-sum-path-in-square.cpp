#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX 987654321
int N;
int grid[101][101];
int main() {
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(N+1, vector<int>(N+1, INT_MAX));
    dp[1][N]=grid[1][N];
    for(int c = N-1; c>= 1; c--){
        dp[1][c]= grid[1][c]+dp[1][c+1];
    }
    for(int r= 2; r <= N; r++){
        dp[r][1]= grid[r][1]+dp[r-1][1];
        dp[r][N]= grid[r][N]+dp[r-1][N];
    }
    for(int r= 2; r <= N; r++){
        for(int c= N-1; c >= 1; c--){
            dp[r][c]= grid[r][c]+min(dp[r-1][c], dp[r][c+1]);
        }
    }
    cout << dp[N][1];
    return 0;
}