#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;
#define MAX_INT 20001
vector<pi> st_s[MAX_INT];
vector<pi> en_s[MAX_INT];
int masks[MAX_INT];

int main(){
  int N; cin >> N;
  for(int i = 0; i < N; i++){
    double x, y, w, h;
    cin >> x >> y >> w >> h;
    x*=10; y*=10; w*=10; h*=10;
    int x1, y1, x2, y2;
    x1=x; y1=y; x2=x+w; y2=y+h;
    st_s[y1].push_back({x1,x2});
    en_s[y2].push_back({x1,x2});
  }

  ll ans = 0;
  for(int i = 0; i < MAX_INT; i++){
    
    for(pi b: st_s[i])
      for(int j = b.first; j < b.second; j++)
        masks[j]++;
    
    for(pi b: en_s[i])
      for(int j =b.first; j < b.second; j++)
        masks[j]--;

    int width=0;
    for(int j = 0; j < MAX_INT; j++)
      if(masks[j]) width++;

    ans+=width;
  }

  double tmp, res = (double)ans*0.01;
  modf(res, &tmp) ? cout.precision(2) : cout.precision(0);
  cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  cout << res;
}