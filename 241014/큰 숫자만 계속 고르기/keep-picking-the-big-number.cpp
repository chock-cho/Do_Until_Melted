#include <iostream>
#include <queue>
using namespace std;
#define INT_MAX 100001
priority_queue<int> pq;
int arr[INT_MAX];
int n,m;
int main() {
    cin>> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pq.push(arr[i]);

        int t = pq.top(); pq.pop();
        pq.push(t-1);
    }
    cout << pq.top();
    return 0;
}