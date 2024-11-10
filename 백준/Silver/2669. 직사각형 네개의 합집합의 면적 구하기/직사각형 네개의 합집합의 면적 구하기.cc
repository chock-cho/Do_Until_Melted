#include <iostream>
using namespace std;
#define INT_MAX 101
bool vis[INT_MAX][INT_MAX];
int ans = 0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int cnt=0; cnt<4; cnt++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int r= x1; r<x2; r++){
            for(int c= y1; c<y2; c++){
                if(vis[r][c]) continue;
                vis[r][c]=true;
                ans++;
            }
        }
    }
    cout <<ans;
}