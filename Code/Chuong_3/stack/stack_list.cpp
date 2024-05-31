#include<iostream>
using namespace std;
typedef struct CELL* Stack;

struct CELL {
    int obj;
    Stack next;
};

Stack S;

void initializeStack(Stack &S) {
    S = NULL;
}

bool emptyStack(Stack S) {
    if(S == NULL) return true;
    else return false;
}

void push(Stack &S ,int x) {
    Stack temp = new (CELL);
    temp -> obj = x;
    temp -> next = S;
    S = temp;
}

int pop(Stack &S) {
    if(emptyStack(S)) {
        cout << "Empty stack";
        return -1;
    } else {
        Stack temp = S;
        int x = temp -> obj;
        S = temp -> next;
        delete temp;
        return x;
    }
}
int main() {
    initializeStack(S);
    push(S , 5);
    push(S , 2);
    push(S , 4);
    cout << pop(S) << " ";
    cout << pop(S);
    cout << pop(S);
    cout << pop(S);

    return 0;
}