#include <iostream>
#include <unordered_set>
using namespace std;
#define MAX_VAL 100001
int n,m;
int arr1[MAX_VAL], arr2[MAX_VAL];
unordered_set<int> s1;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
        s1.insert(arr1[i]);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
        if(s1.find(arr2[i])!=s1.end()) cout << "1\n";
        else cout << "0\n";
    }
    
    return 0;
}