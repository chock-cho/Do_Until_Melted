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
        int x,v; tie(x,v)=points[i]; // (3, +1) (5, -1)
        curCnt+=v;
        int prev_x = points[i-1].first;
        if(i>=1 && prev_x==x && v == +1) curCnt+=1;
        // (1, +1) (3, -1) --> (1, +1) (3, -1) (3, +1) (5, -1)
        //if(prev_x==x && curCnt==0) curCnt+=1;
        roomCnt=max(roomCnt, curCnt);
    }
    cout << roomCnt;
    return 0;
}