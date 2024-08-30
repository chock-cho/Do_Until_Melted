#include <iostream>
#include <algorithm>
using namespace std;
string s1, s2;

string sol(){
    if(s1.size()!=s2.size()) return "No";
    else {
        sort(s1.begin(), s1.end()); sort(s2.begin(),s2.end());
        for(int i = 0; i < s1.size(); i++){
            if(s1[i]!=s2[i]) return "No";
        }
        return "Yes";
    }
}
int main() {
    cin >> s1 >> s2;
    cout << sol();
    return 0;
}