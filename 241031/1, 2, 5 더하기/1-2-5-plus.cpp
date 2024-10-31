#include <iostream>
using namespace std;
#define MAX_INT 1001
#define DIV_INT 10007
int n;
int num[]={1,2,5};
int dp[MAX_INT];
//dp[i]= 합이 i일때, 나타낼 수 있는 경우의 수
// top-down방식 for(j=n to 1) for(i=0 to 3) dp[j]=dp[j-num[i]]+1
void init_dp(){
    for(int i = 0; i < n; i++) dp[i]=0;
}

int sol(){
    dp[0]=1;
    for(int j = 1; j <= n; j++){
        for(int i = 0; i < 3; i++){
            if(j >= num[i]) dp[j]+=dp[j-num[i]];
        }
    }
    return dp[n]%DIV_INT;
}

int main() {
    cin >> n;
    init_dp();
    cout << sol();
    return 0;
}