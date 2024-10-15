#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_INT 10001
bool flag= false;
vector<string> answer;
vector<bool> vis(MAX_INT, false);
void dfs(int cnt, string src, vector<vector<string>>&tickets){
    answer.push_back(src);
    if(cnt == tickets.size()) flag=true;
    for(int i = 0; i < tickets.size(); i++){
        if(tickets[i][0]==src && !vis[i]) {
            string dst = tickets[i][1];
            vis[i]=true;
            dfs(cnt+1, dst, tickets);
            
            if(!flag){ //backtrack
                vis[i]=false;
                answer.pop_back();
            }
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end());
    dfs(0, "ICN", tickets);
    return answer;
}