#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 2501
#define MAX_Q 300001
#define MAX_M 5001

int n,q;
pair<int,int> points[MAX_N];
tuple<int,int,int,int> queries[MAX_Q];

set<int> nums;
unordered_map<int,int> ump;

int psum[MAX_M][MAX_M];

// x보다 같거나 큰 최초의 숫자를 구해
// 좌표압축했을 때의 결과를 반환한다.
int GetLowerBoundary(int x){
    set<int>::iterator it = nums.lower_bound(x);

    if(it == nums.end())
        return (int) nums.size()+1;
    
    return ump[*it];
}

// x보다 같거나 작은 최초의 숫자를 구해
// 좌표압축했을 때의 결과를 반환한다.
int GetUpperBoundary(int x){
    set<int>::iterator it= nums.upper_bound(x);

    if(it == nums.begin()) 
        return 0;
    
    it--;
    return ump[*it];
}

// (x1, y1), (x2, y2) 직사각형 내의 점의 개수를 반환한다.
int GetSum(int x1, int y1, int x2, int y2){
    return psum[x2][y2]-psum[x1-1][y2]-psum[x2][y1-1]+psum[x1-1][y1-1];
}

int main() {
    cin >> n>>q;
    for(int i = 0; i < n; i++){
        int x,y; cin >> x>>y;
        points[i]=make_pair(x,y);
        nums.insert(x); nums.insert(y);
    }

    for(int i = 0; i < q; i++){
        int x1, y1, x2, y2; cin >> x1>>y1>>x2>>y2;
        queries[i]=make_tuple(x1,y1,x2,y2);
    }

    int cnt = 1;
    for(set<int>:: iterator it = nums.begin(); it != nums.end(); it++){
        ump[*it]=cnt++;
    }

    for(int i = 0; i < n; i++){
        int x, y; tie(x,y)=points[i];
        int n_x = ump[x]; int n_y= ump[y];
        psum[n_x][n_y]++;
    }
    
    for(int i = 1; i <= cnt; i++){
        for(int j = 1; j <= cnt; j++){
            psum[i][j] += psum[i-1][j] + psum[i][j-1]- psum[i-1][j-1];
        }
    }

    for(int i = 0; i < q; i++){
        int x1, y1, x2, y2; tie(x1, y1, x2, y2)=queries[i];
        int n_x1= GetLowerBoundary(x1); int n_y1= GetLowerBoundary(y1);
        int n_x2= GetUpperBoundary(x2); int n_y2= GetUpperBoundary(y2);

        int answer = GetSum(n_x1, n_y1, n_x2, n_y2);
        cout << answer << endl;
    }
    return 0;
}