#include <iostream>
using namespace std;
int N;
int grid[101][101];
int dp[101][101];

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin>> grid[i][j];
        }
    }
    dp[0][0]=grid[0][0];
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j]=max(dp[i-1][j], dp[i][j-1])+grid[i][j];
        }
    }
    cout <<dp[N][N];
    return 0;
}