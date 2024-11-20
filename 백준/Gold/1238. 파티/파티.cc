#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;
#define MAX_N 1001
const int INF = 1e9;

int N, M, X;
vector<pair<int,int>> graph[2][MAX_N];
vector<int> dist[2];
int answer = 0;

void djikstra(int st){
  dist[st][X]=0;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  pq.push(make_pair(0, X));

  while(!pq.empty()){
    int u = pq.top().second; //{dist[st][u], u}
    pq.pop();

    for(int i = 0; i < graph[st][u].size(); i++){
      int nu, w; tie(nu, w)=graph[st][u][i];

      if(dist[st][nu] > w + dist[st][u]){
        dist[st][nu] = w + dist[st][u];
        pq.push(make_pair(dist[st][nu], nu));
      }
    }
  }
}

int main(){
  cin >> N >> M >> X;
  for(int i = 0; i < M; i++){
    int x, y, w; cin >> x >> y >> w;
    graph[0][x].push_back(make_pair(y,w));
    graph[1][y].push_back(make_pair(x,w));
  }

  dist[0].resize(N+1, 1e9);
  dist[1].resize(N+1, 1e9);

  djikstra(1); djikstra(0);

  for(int i = 1; i <= N; i++)
    answer = max(answer, dist[0][i]+dist[1][i]);
  
  cout << answer;
  return 0;
}