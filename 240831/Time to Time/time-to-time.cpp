#include <iostream>
using namespace std;
int a,b,c,d;
int ans=0;
int main() {
    cin >> a >> b >> c >> d;
    int init_hour = a, init_min = b;
    if(c<d){
        ans = (60*(c-a))+(d-b);
    }
    else {
        ans= (60*(c-a-1))+(60-(b-d));
    }
    cout << ans;
    return 0;
}