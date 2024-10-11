#include <iostream>
using namespace std;
int n;
int arr[1001];
int dp[1001];

void dp_init(){
    for(int i = 1; i <= n; i++){
        dp[i]=-987654321;
    }
}

int main() {
   //dp = i번째에서 가장 
   cin >> n;
   for(int i = 1; i <= n; i++){
        cin >> arr[i];
   }
   dp_init();
   dp[1]=1;
   for(int i = 2; i <= n; i++){
        if(arr[i-1]<arr[i]) dp[i]=dp[i-1]+1;
        else dp[i]=dp[i-1];
   }
   cout << dp[n];
    return 0;
}