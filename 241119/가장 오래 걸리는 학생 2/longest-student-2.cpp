#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

#define MAX_N 100001

int N, M;
vector<pair<int,int>> graph[MAX_N];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
int dist[MAX_N];
int answer = 0;

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int y, x, w; cin >> y >> x >> w;
        graph[x].push_back(make_pair(y,w));
    }
    
    for(int i = 1; i <= N; i++)
        dist[i]= 1e9;

    dist[N]=0;
    pq.push(make_pair(dist[N], N));

    while(!pq.empty()){
        int u = pq.top().second; 
        pq.pop();
        
        for(int i = 0; i < graph[u].size(); i++){
            int nu, w; tie(nu, w) = graph[u][i];
            if(dist[nu] > dist[u]+w){
                dist[nu] = dist[u]+w;
                pq.push(make_pair(dist[nu], nu));
            }
        }
    }

    for(int i = 1; i <= N; i++){
        answer = max(answer, dist[i]);
    }
    cout << answer;
    return 0;
}