#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v1;
vector<int> v2;

string sol(){
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i = 0; i < n; i++){
        if(v1[i]!=v2[i]) return "No";
    }
    return "Yes";
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v2.push_back(tmp);
    }
    cout << sol();
    return 0;
}