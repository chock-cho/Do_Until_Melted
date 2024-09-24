#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int answer = -987654321;
int ans = 0;

int dfs(int cur, vector<vector<int>> &adj, vector<bool> &vis){
    for(auto nxt: adj[cur]){
        if(vis[nxt]) continue;
        vis[nxt]=true;
        ans+=1;
        dfs(nxt, adj, vis);    
    }
    return ans;
}
int main() {
    cin >> N >> M;
    vector<vector<int>> adj(N+1, vector<int>(0));
    vector<bool> vis(N+1, false);
    while(M--){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    answer = max(answer, dfs(1, adj, vis));
    cout << answer-1;
    return 0;
}