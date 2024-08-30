#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;

int main() {
    cin >> n;
    for(int i = 1; i <=n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        if(i%2==1) {
            sort(v.begin(), v.end());
            cout << v[v.size()/2] << " ";
        }
    }
    return 0;
}