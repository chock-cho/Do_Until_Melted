#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;
#define MAX_N 20001
int n,m,k;
vector<pair<int,int>> graph[MAX_N];
int dist[MAX_N];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

int main() {
    cin >> n >> m;
    cin >> k;
    for(int i = 0; i < m; i++){
        int x,y,w; cin >> x >> y >> w;
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }

    for(int i = 0; i <= n; i++){
        dist[i]=1e9;
    }
    dist[k]=0;

    pq.push(make_pair(dist[k], k));
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(int i = 0; i < graph[u].size(); i++){
            int nu,w; tie(nu,w)=graph[u][i];
            if(dist[nu] > dist[u]+w){
                dist[nu]= dist[u]+w;
                pq.push(make_pair(dist[nu], nu));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i]!= 1e9) cout << dist[i] << endl;
        else cout << -1 << endl;
    }
    return 0;
}