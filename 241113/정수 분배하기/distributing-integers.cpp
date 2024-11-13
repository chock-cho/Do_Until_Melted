#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> nums;
int answer = 0;

bool isPossible(int mid){
    int sum=0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i]/mid;
    }
    if(sum >= m) return true;
    else return false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        nums.push_back(num);
    }
    int lo = 1; int hi = *min_element(nums.begin(), nums.end()); int mid;
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