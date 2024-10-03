#include <iostream>
using namespace std;
#define MAX_N 100001
int n, m;
int arr[MAX_N];
int main() {
   cin >> n >> m;
   for(int i = 1; i <= n; i++){
        cin >> arr[i];
   }
   for(int i = 0; i < m; i++){
        int target; cin >> target;
        bool flag= false;
        int l = 1; int r= n;
        while(l <= r){
            int mid = (l+r)/2;
            if(arr[mid]==target) {
                flag = true;
                cout << mid <<"\n"; break;
            }
            if(arr[mid] > target) r= mid-1;
            if(arr[mid] < target) l= mid+1;
        }
        if(!flag) cout << "-1\n";
   }
    return 0;
}