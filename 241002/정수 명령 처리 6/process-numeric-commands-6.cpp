#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;
int N;
int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        string cmd; cin >> cmd;
        if(cmd == "push"){
            int n; cin >> n;
            pq.push(n);
        }
        if(cmd == "size"){
            cout << pq.size() << "\n";
        }
        if(cmd == "empty"){
            (pq.empty()==true)? cout << "1\n" : cout << "0\n";
        }
        if(cmd == "top"){
            cout << pq.top() << "\n";
        }
        if(cmd == "pop"){
            int t= pq.top();
            cout << t <<"\n";
            pq.pop();
        }
    }
    return 0;
}