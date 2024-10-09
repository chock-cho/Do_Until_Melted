#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
int n,m;
vector<pair<int,int>> points;
vector<pair<int,int>> v;
vector<pair<int,int>> tmp;
int ans = 987654321;
int farthestDist=-987654321;
int FPF_x, FPF_y;
int FPS_x, FPS_y;

int calcDist(int x1, int y1, int x2, int y2){
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

void chooseFarthestTwoPoints(int cur, int prev_idx){
    if(cur== 2){
        int curDist = calcDist(tmp[0].first, tmp[0].second, tmp[1].first, tmp[1].second);
        if(farthestDist < curDist) {
            farthestDist=curDist;
            FPF_x=tmp[0].first; FPF_y=tmp[0].second;
            FPS_x=tmp[1].first; FPS_y=tmp[1].second;
        }
        return;
    }
    for(int i = prev_idx+1; i < v.size(); i++){
        tmp.push_back(make_pair(v[i].first, v[i].second));
        chooseFarthestTwoPoints(cur+1, i);
        tmp.pop_back();
    }
}

void sol(int cur, int prev_idx){
    if(cur == m){
        farthestDist=-987654321;
        chooseFarthestTwoPoints(0, -1);
        //cout << FPF_x << ", " << FPF_y << "and " << FPS_x << ", "<< FPS_y << "\n";
        ans=min(ans, calcDist(FPF_x, FPF_y, FPS_x, FPS_y));
    }
    for(int i = prev_idx+1; i < points.size(); i++){
        v.push_back(make_pair(points[i].first, points[i].second));
        sol(cur+1, i);
        v.pop_back();
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        points.push_back(make_pair(x,y));
    }
    sol(0, -1); 
    cout << ans;
    return 0;
}