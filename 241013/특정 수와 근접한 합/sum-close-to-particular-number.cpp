#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int S, N;
int arr[101]; int sum=0;
vector<int> v;
int ans=987654321;

void dfs(int cnt, int prev_idx){
    if(cnt==2){
        int cur_sum=sum;
        cur_sum= sum-arr[v[0]]-arr[v[1]];
        ans=min(abs(cur_sum-S), ans);
    }
    for(int i = prev_idx+1; i < N; i++){
        v.push_back(i);
        dfs(cnt+1,i);
        v.pop_back();
    }
}

int main() {
    cin >> N >> S;
    for(int i = 0; i < N; i++){
        cin >> arr[i]; 
        sum+=arr[i];
    }
    dfs(0,-1);
    cout <<ans;
    return 0;
}