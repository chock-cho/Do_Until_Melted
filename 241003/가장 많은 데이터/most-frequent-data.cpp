#include <iostream>
#include <unordered_map>
using namespace std;
int n;
unordered_map<string,int> ump;
int cnt=0;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        string color; cin >> color;
        ump[color]+=1;
        if(cnt < ump[color]) cnt=ump[color];
    }
    cout << cnt;
    return 0;
}