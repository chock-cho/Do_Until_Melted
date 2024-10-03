#include <iostream>
#include <unordered_set>
using namespace std;
int n;
unordered_set<int> s;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        string cmd; int k; cin >> cmd >> k;
        if(cmd == "find"){
            if(s.find(k) != s.end()) cout << "true\n";
            else cout << "false\n";
        }
        if(cmd == "add"){
            s.insert(k);
        }
        if(cmd == "remove"){
            s.erase(k);
        }
    }
    return 0;
}