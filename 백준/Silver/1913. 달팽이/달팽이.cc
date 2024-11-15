#include <iostream>
#include <vector>
using namespace std;

const int dc[]={-1, 0, 1, 0};
const int dr[]={0, 1, 0, -1};
int N, target;

bool inGrid(int c, int r){
  return (c>=0)&&(c<N)&&(r>=0)&&(r<N);
}

int main() {
    cin >> N >> target;

    vector<vector<int>> grid(N, vector<int>(N, 0));
  // 출발점 초기화
    int c =N/2; int r= N/2;
    int cnt =1, n =1;
    grid[c][r] =cnt;

    // 달팽이 배열 생성
    while (cnt < N*N) {
        for (int d = 0; d < 4; ++d) { // 방향 반복
            for (int step = 0; step < n; ++step) {
                if (cnt >= N*N) break; 
                c += dc[d]; r += dr[d];
                if (inGrid(c,r)) {
                    grid[c][r] = ++cnt;
                }
            }
            if (d%2==1) n++; 
        }
    }

    int targetX = 0, targetY = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
            if (grid[i][j] == target) {
                targetX = i+1;
                targetY = j+1;
            }
        }
      cout << endl;
    }

    cout << targetX << " " << targetY << endl;

    return 0;
}