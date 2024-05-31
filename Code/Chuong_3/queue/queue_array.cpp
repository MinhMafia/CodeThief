#include<iostream>
using namespace std;
#define MAXN 200

struct Queue {
    int a[MAXN];
    int head , tail;
    int N;
};
Queue Q;

void initializeQueue(Queue &Q) {
    Q.N = 10;
    Q.head = Q.tail = 1;
}

bool isEmpty(Queue Q) {
    if(Q.head == Q.tail == 1) return  true;
    else return false;
}

bool isFull(Queue Q) {
    if((Q.head == 1 && Q.head == Q.N) || (Q.head == Q.tail + 1)) return true;
    return false;
}

void push(Queue &Q, int x) {
    if(isFull(Q)) 
        cout <<  "Full queue";
    else {
        Q.a[Q.tail] = x;
        if(Q.tail == Q.N) Q.tail = 1;
        else Q.tail += 1;
    }
}
int pop(Queue &Q) {
    if(isEmpty(Q)) {
        cout <<  "Empty queue";
        return -1;
    } else {
        int x = Q.a[Q.head];
        if(Q.head == Q.N) Q.head = 1;
        else Q.head += 1;
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