#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
string str;
int ans = 987654321;
int main() {
    cin >> str;
    int N = str.size();
    for(int cnt = 0; cnt < N; cnt++){
        int temp;

        for(int i = 0; i < cnt; i++){

            char tmp = str[str.size()-1];
            for(int i = str.size()-1; i >= 1; i--){
                str[i]= str[i-1];
            }
            str[0]= tmp;
        }
        temp = 2; int count =1;
        for(int i = 1; i < str.size(); i++){
                if(str[i]==str[i-1]) count++;
                else {
                    count = 1; temp+=2;
                }
                if(count == 10) temp+=1;
            }
            ans = min(ans, temp);
        }
    cout << ans;
    return 0;
}