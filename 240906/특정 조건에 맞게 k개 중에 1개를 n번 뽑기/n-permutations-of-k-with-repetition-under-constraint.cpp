#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int K, N;
bool flag =true;

void print(){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void dfs(int cur, int prev){
    if(prev != cur) flag = false;
    if(cur == N+1 && !flag){
        print(); return;
    }
    if(cur == N+1 && flag) return;
    for(int i = 1; i <= K; i++){
        v.push_back(i);
        dfs(cur+1, i);
        v.pop_back();
    }
}

int main() {
    cin >> K >> N;
    dfs(1, 0);
    return 0;
}