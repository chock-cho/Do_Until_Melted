#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
int n,q;
int main() {
    set<int> s;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x; cin >> x; s.insert(x);
    }
    unordered_map<int,int> ump;
    int cnt = 0;
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        ump[*it]=cnt;
        cnt+=1;
    }
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        cout << ump[b]-ump[a]+1 << endl;
    }
    return 0;
}