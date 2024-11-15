#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> points;
int n;
int roomCnt = 0;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int s,e; cin >> s>> e;
        points.push_back(make_pair(s, +1));
        points.push_back(make_pair(e, -1));
    }
    int curCnt=0;
    sort(points.begin(), points.end());
    for(int i = 0; i < points.size(); i++){
        int x,v; tie(x,v)=points[i]; 
        curCnt+=v;
        roomCnt=max(roomCnt, curCnt);
    }
    cout << roomCnt;
    return 0;
}