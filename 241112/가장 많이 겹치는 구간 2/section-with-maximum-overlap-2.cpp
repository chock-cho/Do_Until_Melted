#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int n;
#define INT_MAX 100001
#define BOUND_MAX 1e+9
int maxCnt=-INT_MAX;
vector<pair<int,int>> points;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int s,e; cin >> s>> e;
        points.push_back(make_pair(s,+1));
        points.push_back(make_pair(e,-1));
    }
    int curCnt=0;
    sort(points.begin(), points.end());
    for(int i = 0; i < points.size(); i++){
        int x, v; tie(x,v)=points[i];
        curCnt += v;
        if(maxCnt < curCnt) maxCnt=curCnt;
    }
    cout << maxCnt;
    return 0;
}