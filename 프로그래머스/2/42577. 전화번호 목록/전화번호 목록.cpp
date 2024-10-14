#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    // sol1. sort를 이용
    // bool answer = true;
    // sort(phone_book.begin(), phone_book.end());
    // for(int i = 0; i < phone_book.size()-1; i++){
    //     if(phone_book[i+1].find(phone_book[i])==0) return false;
    // }
    // return true;

    //sol2. hashMap(unordered_map STL 이용)
    for(int i = 0; i < phone_book.size(); i++) {
        for(int j = 0; j < phone_book[i].size(); j++) {
            string s= phone_book[i].substr(0,j);
            if(ump.find(s)!=ump.end()) return false;
        }
    }
    return true;
}
