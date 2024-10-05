#include <iostream>
#include <algorithm>
using namespace std;
#define INT_MAX 987654321
int N, M;
// 지금까지 선택한 동전의 합 && 지금까지 사용한 동전의 개수 ==> 동일한 상황
// 지금까지 선택한 동전의 합이 같다면, 지금까지 사용한 동전의 개수가 많을 수록 좋음
// dp[i] = 지금까지 선택한 동전의 합이 i일때, 최대 동전의 개수
// 초기화: dp[0]=0;
// 문제 정의: coin[j] = i를 만들기 위해 마지막으로 사용한 j번째 동전 
// i-coin[j] => dp[i-coin[j]]+1 
// i>=coin[j]일 때, dp[i]=dp[i-coin[j]]+1; 
// dp[0]=0;
int coin[101];
int dp[10001];
void init_dp(){
    for(int i = 1; i <= M; i++){
        dp[i]=INT_MAX;
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> coin[i];
    }
    init_dp();
    dp[0]=0;
    for(int i = 1; i <= M; i++){
        for(int j = 0; j < N; j++){
            if(i >= coin[j]){
                if(dp[i-coin[j]]==INT_MAX) continue;
                dp[i]=min(dp[i], dp[i-coin[j]]+1);
            }
        }
    }
    if(dp[M]==INT_MAX) cout << "-1";
    else cout << dp[M];
    return 0;
}