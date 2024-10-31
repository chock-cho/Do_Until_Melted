#include <iostream>
using namespace std;
#define MAX_INT 1001
#define DIV_INT 10007
int n;
int num[]={1,2,5};
int dp[MAX_INT];
//dp[i]= 합이 i일때, 나타낼 수 있는 경우의 수
// top-down+재귀 풀이
int sol(int n){
    if(dp[n]!=0) return dp[n]%DIV_INT;
    dp[n]+= sol(n-1);
    dp[n]+= sol(n-2);
    dp[n]+= sol(n-5);
    return dp[n]%DIV_INT;
}

int main() {
    dp[1]=1; dp[2]=2; dp[3]=3; dp[4]=5; dp[5]=9;
    cin >> n;
    cout << sol(n);
    return 0;
}