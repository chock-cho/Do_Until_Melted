#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define INT_MAX 987654321
int answer = INT_MAX;
int depth=0;
vector<bool> vis(51, false);
int solution(string begin, string target, vector<string> words) {
    if(begin == target){
        answer = min(answer, depth);
        return answer;
    }
    int i;
    for(i = 0; i < words.size(); i++){
        int nonMatched = 0;
        if(vis[i]) continue; // i번째 인덱스에 있는 words
        for(int j = 0; j < words[i].size(); j++){
            if(words[i][j]!=begin[j]) nonMatched+=1;
        }
        if(nonMatched==1) {
            depth+=1;
            vis[i]=true;
            solution(words[i], target, words);
            vis[i]=false;
            depth-=1;
        }
    }
    if(answer == INT_MAX) return 0;
    return answer;
}