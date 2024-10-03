#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_VAL 100001
int n;
int arr[MAX_VAL];
unordered_set<int> s;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s.insert(arr[i]);
    }
    cout << s.size();
    return 0;
}