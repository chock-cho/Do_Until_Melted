#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, k;
vector<int> v;
int main() {
    cin >> N >> k;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    cout << v[k-1];
    return 0;
}