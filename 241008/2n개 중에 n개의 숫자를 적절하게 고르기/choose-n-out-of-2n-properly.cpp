#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<int> arr;
vector<int> v;
int ans=987654321;
int sum=0;

int calc(){
    int selected_sum=0;
    for(int i = 0; i < v.size(); i++){
        selected_sum+=v[i];
    }
    int unselected_sum=sum-selected_sum;
    return abs(selected_sum-unselected_sum);
}

void dfs(int depth, int prev_idx){
    if(depth == n){
        ans = min(ans, calc());
        return;
    }
    for(int i = prev_idx+1; i < arr.size(); i++){
        v.push_back(arr[i]);
        dfs(depth+1, i);
        v.pop_back();
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < 2*n; i++){
        int x; cin >> x; sum+=x;
        arr.push_back(x);
    }
    dfs(0, -1);
    cout << ans;
    return 0;
}