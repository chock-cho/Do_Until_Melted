#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool op(vector<int>& A, vector<int>& B){
    return A[1] < B[1];
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cur=0;
    int cnt = jobs.size();
    sort(jobs.begin(), jobs.end(), op);
    while(!jobs.empty()){
        for(int i = 0; i < jobs.size(); i++){
            if(cur >= jobs[i][0]){
                cur += jobs[i][1];
                answer += (cur-jobs[i][0]);
                jobs.erase(jobs.begin()+i);
                break;
            }
            if(i == jobs.size()-1) cur+=1;
        }
    }
    return answer / cnt;
}