#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int,int> ump;
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        string cmd; cin >> cmd;
        if(cmd == "add"){
            int K, V; cin >> K >> V;
            ump[K]=V;
        }
        if(cmd == "find"){
            int K; cin >> K;
            if(ump.find(K) != ump.end()){
                cout << ump[K] << "\n";
            }
            else {
                cout << "None\n";
            }
        }
        if(cmd == "remove"){
            int K; cin >> K;
            ump.erase(K);
        }
    }
    return 0;
}