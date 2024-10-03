#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX_VAL 100001
int n;
pair<int,int> sectors[MAX_VAL];
int ans = -987654321;

int main() {
    cin >> n;
    for(int i = 0; i <n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        sectors[i].first=x1; sectors[i].second=x2;
    }
    vector<pair<int,int>> points;
    for(int i = 0; i < n; i++){
        points.push_back({sectors[i].first,1});
        points.push_back({sectors[i].second,-1});
    }
    sort(points.begin(), points.end());
    int sum =0;
    for(int i = 0; i < 2*n; i++){
        int x,v; tie(x,v)=points[i];
        sum +=v;
        if(ans < sum) ans=sum;
    }
    cout <<ans;
    return 0;
}