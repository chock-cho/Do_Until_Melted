#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
string T; 
vector<string> candid;

bool cmp(string a, string b){ // 사전순 정렬
    return a < b;
}

int main() {
    cin >> n >> k >> T;
    int t = T.size();
    while(n--){
        string tmp;
        cin >> tmp;
        bool flag = true;
        for(int i = 0; i < t; i++){
            if(T[i]!=tmp[i]) flag=false;
        }
        if(flag) candid.push_back(tmp); 
    }
    sort(candid.begin(), candid.end(), cmp);
    cout << candid[k-1];
    return 0;
}