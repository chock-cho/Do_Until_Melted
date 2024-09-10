#include <iostream>
using namespace std;
#define BLANK 0
int n;
int block[101];
int tmp[101];
int s1, e1, s2, e2;

int playJenga(int block_size, int s, int e){
    for(int i = s; i <= e; i++){
        block[i] = BLANK;
    }
    int tmp_row = 0;
    for(int i = 1; i <= block_size; i++){
        if(block[i] != BLANK){
            tmp_row+=1;
            tmp[tmp_row] = block[i];
        }
    }
    for(int i = 1; i <= block_size; i++){
        block[i] = 0;
    }
    for(int i = 1; i <= tmp_row; i++){
        block[i] = tmp[i];
    }
    return tmp_row;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> block[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;
    int sz = playJenga(n, s1, e1);
    int block_size = playJenga(sz, s2, e2);
    if(block_size == 0) cout << "0\n"; 
    else {
        cout << block_size <<"\n";
        for(int i = 1; i <= block_size; i++){
            cout << block[i] << "\n";
        }
    }
    return 0;
}