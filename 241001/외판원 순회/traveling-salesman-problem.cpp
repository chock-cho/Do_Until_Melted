#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int cost[11][11]; // cost[i][j] = i->j 방문하는데 드는 비용
bool vis[11];
int answer = 987654321;
vector<int> v;
int calc(vector<int> &v){
    int ans = 0;
    int prev = 1;
    for(int i = 0; i < v.size(); i++){
        if(cost[prev][v[i]]==0){
            return -1;
        }
        ans+=cost[prev][v[i]];
        prev = v[i];
    }
    ans+= cost[prev][1];
    return ans;
}

void permutation(int cnt){
    if(cnt == n){
        if(calc(v)!= -1){
            answer = min(answer, calc(v));
            return;
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i]=true;
            v.push_back(i);
            permutation(cnt+1);
            vis[i]=false;
            v.pop_back();
        } 
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> cost[i][j];
        }
    }
    vis[1]=true;
    permutation(1);
    cout << answer;
    return 0;
}