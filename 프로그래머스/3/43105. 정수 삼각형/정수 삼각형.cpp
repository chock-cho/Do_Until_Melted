#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n =triangle.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    dp[0][0]=triangle[0][0];
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j==0) dp[i][j]=triangle[i][j]+dp[i-1][j];
            else if(j==i) dp[i][j]=triangle[i][j]+dp[i-1][j-1];
            else dp[i][j]=triangle[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
        }
    }
    for(int c= 0; c <n; c++){
        answer = max(answer, dp[n-1][c]);
    }
    return answer;
}