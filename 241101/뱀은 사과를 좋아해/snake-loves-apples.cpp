#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INT_MAX 101
#define HEAD 1
#define BODY 2
#define TAIL 3
int grid[INT_MAX][INT_MAX];
int vis[INT_MAX][INT_MAX];
bool apples[INT_MAX][INT_MAX];
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
        apples[x][y]=true;
    }
    queue<pair<char,int>> moves;
    for(int i = 0; i < K; i++){
        char d; int p; // d = U,D,R,L p= 얼마나 움직일지
        cin >> d >> p;
        moves.push({d,p});
    }
    int head_x=1; int head_y=1;
    vector<pair<int,int>> snake;
    bool flag =true;
    snake.push_back({head_x,head_y});
    vis[head_x][head_y]=HEAD;
    while(flag && !moves.empty()){
        char cur_d=moves.front().first; int cur_p=moves.front().second;
        moves.pop();
        int n_dir= chooseNxtDir(cur_d); 
        for(int i = 0; i < cur_p; i++){
            T+=1;
            int nx=head_x+dx[n_dir]; int ny=head_y+dy[n_dir];
            if(!inGrid(nx,ny) || vis[nx][ny]==BODY) {
                flag=false; break;
            }
            vis[nx][ny]=HEAD; vis[head_x][head_y]=BODY;
            snake.push_back({nx,ny}); 
            if(!apples[nx][ny]) {
                int tail_x= snake[0].first; int tail_y=snake[0].second;
                snake.erase(snake.begin());
                vis[tail_x][tail_y]=0;
            }
            else apples[nx][ny]=false;
            vis[snake[0].first][snake[0].second]=TAIL; 
            head_x=snake.back().first;
            head_y=snake.back().second;
        }
    }
    cout << T;
    return 0;
}