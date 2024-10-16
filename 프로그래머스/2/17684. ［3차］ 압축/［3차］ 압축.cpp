#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<int> answer;
map<string,int> mp;

vector<int> solution(string msg) {
    int len = msg.size();
    int num=1;
    for(char ch = 'A'; ch <= 'Z'; ch++){
        string st = ""; st+=ch;
        mp.insert({st,num++});
    }
    string w=""; string c="";
    int vocSize=27; int idx=0;
    while(idx<= len){
        c= msg[idx];
        if(mp.find(w+c)!=mp.end()){
            w+=c; 
        }
        else {
            answer.push_back(mp.find(w)->second);
            mp.insert({w+c, vocSize++});
            w=c;
        }
        idx++;
    }
    return answer;
}