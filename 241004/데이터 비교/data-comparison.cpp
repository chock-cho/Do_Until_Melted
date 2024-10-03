#include <iostream>
#include <unordered_set>
using namespace std;
#define MAX_VAL 100001
int n, m;
unordered_set<int> set1, set2;
int arr1[MAX_VAL], arr2[MAX_VAL];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
        set1.insert(arr1[i]);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
        set2.insert(arr2[i]);
    }
    for(int i = 0; i < m; i++){
        if(set1.find(arr2[i])!=set1.end()) cout << "1 ";
        else cout << "0 ";
    }
    return 0;
}