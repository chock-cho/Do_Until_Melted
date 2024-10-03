#include <iostream>
#include <unordered_map>
using namespace std;
#define MAX_VAL 100001
int n, m;
unordered_map<int,int> ump;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        ump[val]+=1;
    }
    for(int i = 0; i < m; i++){
        int query; cin >> query;
        cout << ump[query] << " ";
    }
    return 0;
}