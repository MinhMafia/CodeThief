#include<iostream>
using namespace std;

#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX 100 
struct Stack {
	int a[MAX];
	int top ;
	int N ;
};

Stack s;

void initializeStack(Stack& s) {
	s.top = 0;
	s.N = 30;
}

bool EmptyStack(Stack s) {
	if(s.top == 0) return true;
	return false;
}

bool FullStack(Stack s) {
	if(s.N == s.top) return true;
	return false;
}

void push(Stack &s , int k) {
	if(FullStack(s)) cout << "Full roi ! CUT";
	else {
		s.top ++ ;
		s.a[s.top] = k;
	}
}

int pop(Stack &s ) {
	if(EmptyStack(s)) {
		cout << "Stack trong ma ku";
		return -1;
	}	
	else {
		s.top --;
		return s.a[s.top+1];
	}
}

int main() {
	Stack s;
	initializeStack(s);
	push(s , 5);
	push(s , 1);
	push(s , 3);
	cout << pop(s) <<endl;
	push(s , 7);
	push(s , 2);
	push(s , 8);
	int n = s.top;
	FOR(i,1,n) {
		cout << pop(s) << " ";
	}
	return 0 ;
}

