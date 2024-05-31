#include<iostream>
using namespace std;
typedef struct CELL* LIST;

struct CELL {
    int obj;
    LIST next;
};

struct Queue {
    LIST head , tail;
};
Queue Q;

void initializeQueue(Queue& Q) {
    Q.head = Q.tail = NULL;
}

bool isEmpty(Queue Q) {
    if(Q.head == NULL) return true;
    else return false;
}

void push(Queue &Q ,int x) {
    LIST p;
    p = new (CELL);
    p -> obj = x;
    p -> next = NULL;
    if(Q.head == NULL) Q.head = p;
    else Q.tail -> next = p;
    Q.tail = p;
}

int pop(Queue &Q) {
    if(isEmpty(Q)) return -1;
    else {
        LIST p = Q.head;
        int x = p -> obj;
        if(Q.head == Q.tail) Q.head = Q.tail = NULL;
        else Q.head = p -> next;
        delete p;
        return x;
    }
}

int main() {
    initializeQueue(Q);
    push(Q,5);
    push(Q,1);
    push(Q,2);
    push(Q,8);
    push(Q,7);
    cout << pop(Q);
    cout << " " << pop(Q);
    return 0;

}