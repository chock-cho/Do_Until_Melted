#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n,m;
vector<pair<int,int>> nums, v, points;
int ans=98765431;

int calcDist(int st_x, int st_y, int en_x, int en_y){   
    return ((en_x-st_x)*(en_x-st_x)+(en_y-st_y)*(en_y-st_y));
}

void choosePoint(int depth, int prev_idx){
    if(depth==2){
        // for(int i = 0; i < points.size(); i++){
        //     cout << points[i].first << " , " << points[i].second <<"\n";
        // }
       int cur = calcDist(points[0].first, points[0].second, points[1].first, points[1].second);
       if(cur < ans) ans=cur;
       return;
    }
    for(int i =prev_idx+1; i < v.size(); i++){
        points.push_back(make_pair(v[i].first, v[i].second));
        choosePoint(depth+1,i);
        points.pop_back();
    }
}
void dfs(int depth, int prev_idx){
    if(depth == m){
        choosePoint(0,-1);
        return;
    }
    for(int i = prev_idx+1; i < nums.size(); i++){
        v.push_back(make_pair(nums[i].first, nums[i].second));
        dfs(depth+1, i);
        v.pop_back();
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        nums.push_back(make_pair(x,y));
    }
    dfs(0, -1); cout << ans;
    return 0;
}