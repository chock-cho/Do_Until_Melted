#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int A, B, x, y;
int ans = 987654321;
int main() {
    cin >> A >> B >> x >> y;
    // x-> y || y-> x
    // case 1: A-> B
    int ans1 = abs(A-B);
    // case 2: A->X->Y->B
    int ans2= abs(x-A)+abs(B-y);
    // case 3: A->Y->X->B
    int ans3=abs(y-A)+abs(B-x);
    ans = min(min(ans1, ans2), ans3);
    cout <<ans;
    return 0;
}