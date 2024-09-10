#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define BLANK 0 
int bomb_size, M;
int bomb[101];
int tmp[101];
int cnt = 0;

bool havetoBomb(int bomb_size){
    int cnt = 1; bool flag= false;
    int st_idx, en_idx;
    for(int i = 2; i <= bomb_size; i++){
        if(bomb[i-1]==bomb[i]) {
            cnt++; 
            if(cnt==2) st_idx= i-1;
            en_idx=i;
            flag = true;
        }
        else {
            if(cnt >= M){
                for(int i = st_idx; i <= en_idx; i++) bomb[i] = BLANK;
                cnt=1;
            }
            cnt = 1;
        }
    }
    if(cnt >= M){
         for(int i = st_idx; i <= en_idx; i++) bomb[i] = BLANK;
    }
    return flag;
}

int main() {
    cin >> bomb_size >> M;
    for(int i = 1; i <= bomb_size; i++){
        cin >> bomb[i];
    }
    while(true){
        if(bomb_size == 1 && M == 1) {
            cout << "0"; return 0;
        }
        bool flag = havetoBomb(bomb_size);
        if(!flag) break;
        int tmp_row =0;
        for(int i = 1; i <= bomb_size; i++){
            if(bomb[i] != BLANK) {
             tmp_row++;
             tmp[tmp_row] = bomb[i];
            }
        }
        bomb_size= tmp_row;
        for(int i = 1; i <= bomb_size; i++){
            bomb[i] = BLANK; 
        }
        for(int i = 1; i <= bomb_size; i++){
            bomb[i] = tmp[i];
        }
        for(int i = 1; i <= bomb_size; i++){
            tmp[i] = BLANK;
        }        
    }
    cout << bomb_size << "\n";
    for(int i = 1; i <= bomb_size; i++)
        cout << bomb[i] << "\n";
    return 0;
}