#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAX_S 2e9+1
ll s;
ll ans =0;

int main(){
    cin >> s;
    ll lo = 1; ll hi = MAX_S; ll mid;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(mid*(mid+1)/2 > s){
            hi = mid-1;
        }
        else {
            lo = mid+1;
            ans = max(ans, mid);
        }
    }
    cout <<ans;
}