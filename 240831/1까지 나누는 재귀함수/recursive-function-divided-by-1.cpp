#include <iostream>
using namespace std;
int n;
int main() {
    cin >> n;
    while(n>=1){
        cout << n << " ";
        (n%2==0)? n/=2 : n/=3;
    }
    return 0;
}