#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<>> pq;
int main() {
    cin >>n;
    while(n--){
        int x; cin >> x;
        if(x>0) pq.push(x);
        else if(x==0) {
            if(pq.size()==0) cout << "0\n";
            else {
             int t= pq.top(); pq.pop();
            cout << t << "\n";
            }
        }
    }
    return 0;
}