#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int K, N;
void print(){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout <<"\n";
}

void dfs(int cur){
    if(cur == N+1) {
        print(); return;
    }
    for(int i = 1; i <= K; i++){
        v.push_back(i);
        dfs(cur+1);
        v.pop_back();
    }
}

int main() {
    cin >> K >> N;
    dfs(1);
    return 0;
}