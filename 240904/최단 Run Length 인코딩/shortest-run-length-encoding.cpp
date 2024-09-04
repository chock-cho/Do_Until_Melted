#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
string str;
map<char, int> mp;
int ans = 987654321;
int main() {
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        string temp ="";
        //while(i--){ //i: 특정 횟수
            char tmp = str[str.size()-1];
            for(int i = str.size()-1; i >= 1; i--){
                str[i]= str[i-1];
            }
            str[0]= tmp;
        //}
        // aaaaabbbbc
        for(int i = 0; i < str.size(); i++){
            mp[str[i]]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            temp += (it->first);
            temp += to_string(it->second);
        }
        int t= temp.size(); //cout << temp;
        ans = min(ans, t);
    }
    cout << ans;
    return 0;
}