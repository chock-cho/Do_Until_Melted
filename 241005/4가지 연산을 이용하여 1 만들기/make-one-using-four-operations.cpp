#include <iostream>
#include <queue>
using namespace std;
#define INT_MAX 1000001
int N;
bool vis[INT_MAX];
int arr[INT_MAX];
queue<int> q;
bool isPossible(int x){
    if(1<=x) return true;
    else return false;
}
int main() {
    cin >> N;
    vis[N]=1; q.push(N);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == 1) {
            cout << arr[1]; break;
        }
        // case1: -1
        if(isPossible(cur-1) && !vis[cur-1]){
            vis[cur-1]=true;
            q.push(cur-1);
            arr[cur-1]=arr[cur]+1;
        }
        // case2: +1
        if(!vis[cur+1]){
            vis[cur+1]=true;
            q.push(cur+1);
            arr[cur+1]=arr[cur]+1;
        }
        // case3: /3
        if(cur%3==0 && !vis[cur/3]){
            vis[cur/3]=true;
            q.push(cur/3);
            arr[cur/3]=arr[cur]+1;
        }
        if(cur%2==0 && !vis[cur/2]){
            vis[cur/2]=true;
            q.push(cur/2);
            arr[cur/2]=arr[cur]+1;
        }
    }
    return 0;
}