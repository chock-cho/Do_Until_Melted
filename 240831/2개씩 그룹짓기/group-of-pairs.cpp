#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> v;
int ans = -987654321;
int main() {
    cin >> N;
    for(int i = 0; i < 2*N; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    //for(int i =0 ; i <v.size(); i++) cout << v[i] << " ";
    //cout << "\n";
    for(int i = 0; i < v.size()/2; i++){
        //cout << v[i] << " + " << v[v.size()-1-i] << " = " << v[i]+v[v.size()-1-i] << "\n";
        if(ans < v[i]+v[v.size()-1-i]) ans = v[i]+v[v.size()-1-i];
    }
    cout << ans;
    return 0;
}