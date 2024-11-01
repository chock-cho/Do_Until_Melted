#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INT_MAX 101
int grid[INT_MAX][INT_MAX];
bool vis[INT_MAX][INT_MAX];
int apples[INT_MAX][INT_MAX]={0};
int N, M, K;
const int dx[]={-1, 1, 0, 0}; // UDRL
const int dy[]={0, 0, 1, -1};
const char dir[]={'U', 'D', 'R', 'L'};
int T = 0;

int chooseNxtDir(char ch){
    if(ch=='U') return 0;
    if(ch=='D') return 1;
    if(ch=='R') return 2;
    if(ch=='L') return 3;
}

bool inGrid(int x, int y){
    return (x>=1)&&(x<=N)&&(y>=1)&&(y<=N);
}

int main() {
    cin >> N >> M >> K;
    while(M--){
        int x, y;
        cin >> x >> y;
        apples[x][y]=1;
    }
    queue<pair<char,int>> moves;
    for(int i = 0; i < K; i++){
        char d; int p; // d = U,D,R,L p= 얼마나 움직일지
        cin >> d >> p;
        moves.push({d,p});
    }
    int cur_x=1; int cur_y=1;
    vector<pair<int,int>> snake;
    bool flag =true;
    snake.push_back({1,1});
    vis[1][1]=true;
    while(flag && !moves.empty()){
        char cur_d=moves.front().first; int cur_p=moves.front().second;
        moves.pop();
        int n_dir= chooseNxtDir(cur_d); 
        for(int i = 0; i < cur_p; i++){
            T+=1;
            int nx=cur_x+dx[n_dir]; int ny=cur_y+dy[n_dir];
            if(!inGrid(nx,ny) || vis[nx][ny]) {
                flag=false; 
                break;
            }
            vis[nx][ny]=true;
            snake.push_back({nx,ny}); // snake 벡터의 맨 뒤에 있는 친구가 snake의 head가 된다.
            if(apples[nx][ny]!=1) {
                snake.erase(snake.begin()); // snake의 tail은 snake의 처음
                int r= snake.front().first; int c=snake.front().second;
                vis[r][c]=false;
            }
            cur_x=snake.back().first; cur_y=snake.back().second;
        }
    }

    cout << T;
    return 0;
}