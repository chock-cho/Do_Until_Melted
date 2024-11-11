#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_S 2e+1
int s;
int ans =0;

int main(){
    cin >> s;
    int lo = 1; int hi = MAX_S; int mid;
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