#include <iostream>
using namespace std;
int N; int arr[1001]; int dp[1001]={1};
int cur_max=-987654321;
int main() {
    cin >> N;
    for(int i =1; i <= N; i++){
        cin >>arr[i];
    }
    dp[0]=0;
    for(int i = 1; i <= N; i++){
        dp[i]=1;
        for(int j = 0; j<= N; j++) {
            if(arr[j]<arr[i] && dp[j]+1 >dp[i]) dp[i]=dp[j]+1;
        }
        if(dp[i] > cur_max) cur_max=dp[i];
    }
    cout << cur_max;
    return 0;
}