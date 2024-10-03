#include <iostream>
#include <cctype>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string,int> ump1;
unordered_map<int,string> ump2;
int n, m;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string str; cin >> str;
        ump1[str]=i; ump2[i]=str;
    }
    for(int i = 0; i < m; i++){
        string tmp; cin>> tmp;
         if(isdigit(tmp[0])){
            int idx = stoi(tmp);
            cout << ump2[idx] <<"\n";
        }
        else {
           cout << ump1[tmp] << "\n";
        }
    }
    return 0;
}