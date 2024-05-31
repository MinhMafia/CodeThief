#include<iostream>
using namespace std;
#define MAXN 500
struct Stack {
    int a[MAXN];
    int top; // độ cao hiện tai = vt phần tử mới thêm vào
    int N; //kích thước giới hạn cảu satack
};

Stack S;

void initializeStack(Stack &S) {
    S.top = 0;
    S.N = 30;
}

bool fullStack(Stack S) {
    if(S.top == S.N) 
        return true;
    return false; 
}

bool emptyStack(Stack S) {
    if(S.top == 0) return true;
    return false;
}

void pushStack(Stack &S, int x) {
    if(fullStack(S)) {
        cout  << "Stack full";
        return;
    }
    S.top+=1;
    S.a[S.top] = x;
}

int popStack(Stack &S) {
    if(emptyStack(S)) {
        cout << "Stack empty";
        return -1;
    }
    S.top -= 1;
    return S.a[S.top + 1];
}

int main() {
    initializeStack(S);
    pushStack(S , 5);
    pushStack(S , 2);
    pushStack(S , 4);
    cout << popStack(S);
    cout << popStack(S);

    return 0;
}