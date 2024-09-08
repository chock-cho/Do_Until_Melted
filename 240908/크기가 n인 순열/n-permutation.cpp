#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
bool vis[9];
int n;
void print(){
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
}

void sol(int cur){
    if(cur == n+1){
        print(); return;
    }
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        vis[i] = true;
        v.push_back(i);
        sol(cur+1);
        v.pop_back();
        vis[i] = false;
    }
}

int main() {
    cin >> n;
    sol(1);
    return 0;
}