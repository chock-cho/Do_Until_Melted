#include <string>
#include <vector>
using namespace std;
int n,m,x,y,r,c,k;
const int dx[]={1, 0, 0, -1}; //dlru
const int dy[]={0, -1, 1, 0};
const char ds[]={'d','l','r','u'};
string res=""; string answer="impossible";
int cnt=0;
bool flag=false;

int calcDist(int x, int y, int r, int c){
    return abs(r-x)+abs(c-y);
}

bool inGrid(int x, int y){
    return (x>=1)&&(x<=n)&&(y>=1)&&(y<=m);
}

void dfs(int cnt, int x, int y){   
    if(flag) return;
    int leftDist = calcDist(x,y,r,c);
    if(leftDist > k-cnt || (leftDist-(k-cnt))%2!=0) {
        return;
    }
    
    if(cnt==k){
        if(x==r && y==c){
            flag=true; 
            answer=res;
        }
        return;
    }
    
    for(int i =0; i < 4; i++){
        int nx=x+dx[i]; 
        int ny=y+dy[i];
        if(!inGrid(nx,ny)) continue;
        res+=ds[i];
        dfs(cnt+1,nx,ny);
        res.erase(res.begin()+cnt);
    }
}

string solution(int N, int M, int X, int Y, int R, int C, int K) {
    n=N; m=M; x=X; y=Y; r=R; c=C; k=K;
    dfs(0,x,y);
    if(!flag) return "impossible";
    return answer;
}