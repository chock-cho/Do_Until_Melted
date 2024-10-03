#include <iostream>
using namespace std;
#define MAX_VAL 100001
int n, m;
int arr[MAX_VAL];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        arr[val]+=1;
    }
    for(int i = 0; i < m; i++){
        int query; cin >> query;
        cout << arr[query] << " ";
    }
    return 0;
}