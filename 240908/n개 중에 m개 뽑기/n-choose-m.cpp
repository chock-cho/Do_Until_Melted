#include <iostream>
#include <vector>
using namespace std;
int N, M;
bool vis[11];
vector<int> v;

void print(){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void dfs(int cur, int prev){
    if(cur == M+1) {
        print(); return;
    }
    for(int i = 1; i <= N; i++){
        if(prev > i) continue;
        if(vis[i]) continue;
        vis[i] = true;
        v.push_back(i);
        dfs(cur+1, i);
        v.pop_back();
        vis[i] = false;
    }
}

int main() {
    cin >> N >> M;
    dfs(1, 0);
    return 0;
}