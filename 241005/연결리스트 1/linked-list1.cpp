#include <iostream>
using namespace std;
int N;
struct Node {
    string val;
    Node*prev;
    Node*next;
    Node(string val): val(val), prev(nullptr), next(nullptr) {}
};

void print(Node *cur){
    if(cur->prev!=nullptr) cout<< cur->prev->val << " "; 
    else cout << "(Null) ";

    cout << cur->val << " ";

    if(cur->next!=nullptr) cout<< cur->next->val << " ";
    else cout << "(Null) ";
    cout <<"\n";
}

void insertPrev(string val, Node *cur){
    Node *newNode = new Node(val);
    newNode->prev = cur->prev;
    newNode->next = cur;

    if(newNode->prev!=nullptr){
        newNode->prev->next= newNode;
    }
    if(newNode->next!=nullptr){
        newNode->next->prev= newNode;
    }
    print(cur);
}

void insertNext(string val, Node *cur){
    Node *newNode = new Node(val);
    newNode->prev = cur;
    newNode->next = cur->next;

    if(newNode->prev!=nullptr){
        newNode->prev->next= newNode;
    }
    if(newNode->next!=nullptr){
        newNode->next->prev= newNode;
    }
    print(cur);
}

void changeCurPrev(Node *cur){
    if(cur->prev != nullptr) cur=cur->prev;
    print(cur);
}

void changeCurNext(Node *cur){
    if(cur->next != nullptr) cur=cur->next;
    print(cur);
}

int main() {
    string S_init; cin >> S_init;
    Node *cur = new Node(S_init);
    cin >> N;
    for(int i = 0; i < N; i++){
        int tmp; cin >> tmp;
        if(tmp == 1) {
            string str; cin >> str; insertPrev(str, cur);
        }
        if(tmp == 2){
            string str; cin >> str; insertNext(str, cur);
        }
        if(tmp == 3) {
            changeCurPrev(cur);
        }
        if(tmp == 4){
            changeCurNext(cur);
        }
    }
    return 0;
}