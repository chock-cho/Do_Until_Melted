#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int n, q;
map<int, set<int>> pointsByXCoord; // X 좌표 별 Y 좌표 저장 
map<int, unordered_map<int,int>> yCoordIndexMap; // X 좌표 별 Y 좌표의 인덱스 저장

int sol(int x1, int y1, int x2, int y2){
    int cnt = 0;
    // X범위 : x1 이상 x2 이하의 X 좌표 반복
    auto xStartIter = pointsByXCoord.lower_bound(x1);
    auto xEndIter = pointsByXCoord.upper_bound(x2);
    for(auto it = xStartIter; it != xEndIter; ++it){
        int x = it->first;
        const auto& ySet = it->second;

        // Y범위: y1 이상 y2 이하의 Y 좌표 반복
        auto yStartIter= ySet.lower_bound(y1);
        auto yEndIter = ySet.upper_bound(y2);

        // 유효한 Y좌표가 있는 경우에만 개수 세기
        if(yStartIter != ySet.end() && yEndIter != ySet.begin()) {
            cnt += distance(yStartIter, yEndIter);
        }
    }
    return cnt;
}

int main() {
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x, y; cin >>  x >> y;
        pointsByXCoord[x].insert(y); // X 좌표 별 Y 좌표 저장
    }

    // 각 X 좌표 별 Y 좌표의 인덱스 생성
    for(auto& [x, ySet] : pointsByXCoord) {
        int idx = 1;
        for(int y : ySet) {
            yCoordIndexMap[x][y] = idx++;
        }
    }
    
    for(int i = 0; i < q; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int ans = sol(x1, y1, x2, y2);
        cout << ans << endl;
    }
    return 0;
}