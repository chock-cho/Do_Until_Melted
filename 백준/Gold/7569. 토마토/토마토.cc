#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define INT_MAX 101

const int dh[]={-1, 1, 0, 0, 0, 0};
const int dc[]={0, 0, 1, -1, 0, 0};
const int dr[]={0, 0, 0, 0, 1, -1};

int box[INT_MAX][INT_MAX][INT_MAX];
int vis[INT_MAX][INT_MAX][INT_MAX];
int H, R, C;
queue<tuple<int,int,int>> q;
int answer = 0;
int tomato = 0;

bool inBox(int h, int c, int r){
  return (h>=0)&&(h<H)&&(c>=0)&&(c<C)&&(r>=0)&&(r<R);
}

int main(){
  cin >> R >> C >> H;
  // 가로 :R, 세로 :C, 층수: H

  for(int k = 0; k < H; k++){
    for(int i = 0; i < C; i++){
      for(int j = 0; j < R; j++){
        cin >> box[k][i][j];
        if(box[k][i][j]==1) {
          vis[k][i][j]=1; // 방문 표시
          q.push(make_tuple(k,i,j));
        }
        if(box[k][i][j]==0) tomato+=1;
      }
    }
  }
  if(tomato == 0) {
    cout<<"0"; return 0;
  }
  
  while(!q.empty()){
    int curTurn = q.size();
    ++answer;
    
    for(int turn = 0; turn < curTurn; turn++){
      tuple<int,int,int> t= q.front(); q.pop();
      int h, c, r; tie(h, c, r)=t;

      for(int i =0; i< 6; i++){
        int nh = h+dh[i]; int nc = c+dc[i]; int nr = r+dr[i];
        if(inBox(nh,nc,nr) && !vis[nh][nc][nr] && box[nh][nc][nr]==0) {
          vis[nh][nc][nr]=vis[h][c][r]+1;
          q.push(make_tuple(nh,nc,nr));
          tomato--;

        }
      }
    }
  }
  
  if(tomato > 0){
    cout << "-1"; 
  }
  else {
    cout << answer-1;
  }
  return 0;
}