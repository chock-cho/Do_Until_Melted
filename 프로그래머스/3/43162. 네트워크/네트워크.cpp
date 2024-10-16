#include <string>
#include <vector>

using namespace std;
int cnt = 0;

void dfs(int curNode, vector<vector<int>>& graph, vector<bool>& vis){
    vis[curNode]=true;
    for(int cur: graph[curNode]){
        if(!vis[cur]) {
            dfs(cur, graph, vis);
        }
    }
    return;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    vector<bool> vis(n+1, false);
    int row =computers.size(); int col= computers[0].size();
    for(int i =0; i < row; i++){
        for(int j =0; j < col; j++){
            if(i!=j && computers[i][j]==1) {
                graph[i+1].push_back(j+1);
                graph[j+1].push_back(i+1);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            answer+=1;
            vis[i]=true;
            dfs(i,graph,vis);
            vis[i]=false;
        }
    }
    return answer;
}