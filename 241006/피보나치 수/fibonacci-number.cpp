#include <iostream>
using namespace std;
int N;
int memo[50]={-1};
int main() {
    cin >> N;
    memo[1]=1;
    memo[2]=1;
    for(int i = 3; i <= N; i++){
        memo[i]=memo[i-1]+memo[i-2];
    }
    cout << memo[N];
    return 0;
}