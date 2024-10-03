#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int,int> ump; //K,V
int n, k;
unordered_map<int, bool> vis;
vector<int> v;
int ans = 0;
void dfs(int cnt){
    if(cnt == 2){
        if(v[0]+v[1]==k) {
            //cout << v[0] << " " << v[1] << "\n";
            ans+=1;
        }
        return; 
    }
    for(int i = 0; i < ump.size(); i++){
        if(vis[i]) continue;
        vis[i]=true;
        v.push_back(ump[i]);
        dfs(cnt+1);
        vis[i]=false;
        v.pop_back();
    }
}
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        ump[i]=tmp;
    }
    dfs(0);
    cout << ans/2;
    return 0;
}