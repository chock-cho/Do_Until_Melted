#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int maxDist = -987654321;
    int answer=0;
    vector<vector<int>> graph(n+1, vector<int>(0));
    for(int i = 0; i < edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    queue<int> q;
    vector<int> vis(n+1, -1);
    vis[1]=0; q.push(1);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int nxt: graph[cur]){
            if(vis[nxt]==-1) {
                vis[nxt]=vis[cur]+1;
                q.push(nxt);
            }
        }
    }
    for(int i = 0 ; i< vis.size(); i++){
        if(maxDist < vis[i]) maxDist= vis[i];
    }
    for(int i = 0; i < vis.size(); i++){
        if(maxDist==vis[i]) answer+=1;
    }
    return answer;
}