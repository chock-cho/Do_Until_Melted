#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int>nums;
vector<int>v;
int ans=0;

int calcXor(){
    int sum=v[0];
    for(int i = 1; i < v.size(); i++) {
        sum^=v[i];
    }
    return sum;
}

void dfs(int cnt, int prev, vector<bool>&vis){
    if(cnt==m) {
        ans=max(ans,calcXor());
        return;
    }
    for(int i = 0; i < n; i++){
        if(prev >= nums[i]) continue;
        if(vis[nums[i]]) continue;
        vis[nums[i]]=true;
        v.push_back(nums[i]);
        dfs(cnt+1, nums[i], vis);
        vis[nums[i]]=false;
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int num; cin >> num; nums.push_back(num);
    }
    vector<bool> vis(n+1, false);
    dfs(0,-1,vis);
    cout << ans;
    return 0;
}