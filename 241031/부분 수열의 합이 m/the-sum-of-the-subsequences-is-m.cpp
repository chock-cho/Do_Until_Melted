#include <iostream>
#include <vector>
#include <algorithm> 
#define INT_MAX 10001
using namespace std;
int n,m;
int A[INT_MAX];
int sol(){
    // dp[i]=합이 i가 되는 부분 수열 중 최소 길이
    // i>=A[j]일 때, dp[i-A[j]]+1 
    // for(i = 1 to n) for(j = n to 0) dp[i]=min(dp[i], dp[i-coin[j]])
    int dp[INT_MAX];
    for(int i = 0; i <= m; i++) dp[i]=INT_MAX;

    dp[0]=0;
    for(int i = 0; i <= n; i++){
        for(int j = m; j >= 1; j--){
            if(i >= A[j]) {
                dp[j]=min(dp[j], dp[j-A[i]]+1);
            }
        }
    }
    if(dp[m]!= INT_MAX) return dp[m];
    return -1;
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << sol();
    return 0;
}