#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<>> pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    while(pq.size()>=2){
        if(pq.top()>=K) return answer;
        int tmp1= pq.top(); pq.pop();
        int tmp2= pq.top(); pq.pop();
        int tmp = tmp1+(2*tmp2);
        pq.push(tmp);
        answer++;
    }
    if(pq.top()>=K) return answer;
    return -1;
}
