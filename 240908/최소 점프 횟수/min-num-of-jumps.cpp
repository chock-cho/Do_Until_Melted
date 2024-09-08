#include <iostream>
using namespace std;
int n;
int arr[11];
const int INF =987654321;
int dp[11];

// 1. dp 정의 --> dp[i]는 i번째 위치에서 jump하는지 안하는지
void sol(){
    dp[1] = 0;
    for(int i = 1; i < n; i++){
        int num = arr[i];
        for(int j = 1; j <= num; j++){
             if(i+j <= n){
                if(dp[i+j]== INF) dp[i+j]=dp[i]+1;
                else dp[i+j] = min(dp[i+j], dp[i]+1);
             }
        }
    }
    if(dp[n]!= INF) cout << dp[n];
    else cout << "-1";
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) dp[i] = INF;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sol();
    return 0;
}