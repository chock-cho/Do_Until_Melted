#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
#define MAX_NUM 1e9+1
vector<pair<ll,ll>> segs;
ll ans=0;

bool isPossbile(ll mid){
    ll cur_x=segs[0].first;
    for(int i = 0; i < segs.size()-1; i++){
        if(cur_x + mid > segs[i+1].second)
            return false;
        cur_x= max(cur_x+mid, segs[i+1].first);
    }
    return true;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        ll s,e; cin >> s >> e;
        segs.push_back(make_pair(s,e));
    }
    sort(segs.begin(), segs.end());
    // for(int i = 0; i < segs.size(); i++){
    //     int s,e; tie(s,e)=segs[i];
    //     cout << "(" << s << "," << e << ")\n";
    // }
    ll lo = 1; ll hi = MAX_NUM; ll mid;
    while(lo <= hi){
        mid = (lo + hi)/2;
        if(isPossbile(mid)){
            lo = mid+1;
            ans = max(ans, mid);
        }
        else {
            hi = mid-1;
        }
    }
    cout << ans;
    return 0;
}