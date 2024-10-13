#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int S, N;
int arr[101]; int sum=0;
vector<int> v;
int ans=987654321;

int main() {
    cin >> N >> S;
    for(int i = 0; i < N; i++){
        cin >> arr[i]; 
        sum+=arr[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(i!=j) ans=min(ans, abs(sum-arr[i]-arr[j]-S));
        }
    }
    cout <<ans;
    return 0;
}