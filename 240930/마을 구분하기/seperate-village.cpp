#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int dx[]={-1, 0, 1, 0};
const int dy[]={0, 1, 0, -1};
int n;
int grid[101][101];
int village[101][101]={0};
bool vis[101][101];
vector<int> v;
int ans=0;

bool inRange(int x, int y){
    return (x>=0)&&(x<n)&&(y>=0)&&(y<n);
}

void findClose(int i, int j){
   for(int k = 0; k < 4; k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(!inRange(nx,ny) || vis[nx][ny] || grid[nx][ny]==0) continue;
        vis[nx][ny]=true;
        village[nx][ny] = ans++;
        //cout << nx << ", " << ny << ": " <<village[nx][ny] << "\n";
        findClose(nx,ny);
    }
    return;
}

void makeVillage(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]==0 || vis[i][j]) continue;
            vis[i][j]=true; ans=1;
            findClose(i, j);
            v.push_back(ans); //cout << ans <<"\n";
            ans = 0;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    makeVillage();
    cout << v.size() <<"\n";
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<"\n";
    }
    return 0;
}