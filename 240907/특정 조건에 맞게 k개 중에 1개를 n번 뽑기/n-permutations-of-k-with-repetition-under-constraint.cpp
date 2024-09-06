#include <iostream>
#include <vector>
using namespace std;
int K, N;
vector<int> v;
bool chk(){
    for(int i = 1; i < v.size()-1; i++){
        if(v[i]==v[i-1]&&v[i]==v[i+1]) return false;
    }
    return true;
}

void print(){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void dfs(int cur){
    if(cur == N+1) {
        if(chk()) {
            print(); return;
        }
        else if(N<3) {
           print(); return;
        } 
        return;
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