#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define INT_MAX 1001

int n,m;

vector<tuple<int,int,int>> edges;
int graph[INT_MAX][INT_MAX];
bool vis[INT_MAX];
int dist[INT_MAX]={-1};

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        edges.push_back(make_tuple(x,y,w));
    }
    for(int i = 0; i < edges.size(); i++){
        int x, y, w; tie(x,y,w) = edges[i];
        graph[x][y]=w;
    }
    for(int i = 1; i <= n; i++) 
        dist[i]= (int)1e9;
    dist[1]= 0;

    for(int i = 1; i <= n; i++){
        int minIdx= -1;
        for(int j = 1; j <= n; j++) {
            if(vis[j]) continue;

            if(minIdx == -1 || dist[minIdx] > dist[j])
                minIdx = j;
        }
        vis[minIdx]=true;

        for(int j =1; j <= n; j++){
            if(graph[minIdx][j] ==0) continue;
            dist[j] = min(dist[j] , dist[minIdx]+graph[minIdx][j]);
        }
    }

    for(int i = 2; i <= n; i++){
        if(dist[i] == 1e9) dist[i]=-1;
        cout << dist[i] << endl;
    }
    return 0;
}