#include <iostream>
using namespace std;
int ans = -987654321;
int main() {
    for(int i =0; i < 3; i++){
        int n;
        cin >> n;
        if(ans < n) ans =n;
    }
    cout << ans;
    return 0;
}