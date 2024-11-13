#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 100000
typedef long long ll;
ll n,m;
vector<ll> nums;
ll answer = 0;

bool isPossible(ll mid){
    ll sum=0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i]/mid;
        if(sum >= m) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        nums.push_back(num);
    }
    ll lo = 1; ll hi = MAX_NUM; ll mid;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(isPossible(mid)) {
            lo = mid+1;
            answer = max(answer, mid);
        }
        else {
            hi = mid-1;
        }
    }
    cout <<answer;
    return 0;
}