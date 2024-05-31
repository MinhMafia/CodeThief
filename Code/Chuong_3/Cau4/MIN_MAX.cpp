#include<iostream>

using namespace std;
typedef struct CELL* LIST ;
struct CELL{
	int key ; 
	LIST next;
};
LIST L;

void initializeList(LIST &L) {
	L = NULL;
}

void insertList (LIST &L , int k) {
	LIST x = new(CELL);
	x -> key = k ;
	x -> next = L;
	L = x;
}

int MaxCell(LIST L) {
	if(L == NULL) return -1;
	int max = L -> key;
	while(L != NULL) {
		if(L -> key >= max) max = L-> key;
		L = L -> next;
	}
	return max;
}
int MinCell(LIST L) {
	if(L == NULL) return -1;
	int min = L -> key;
	while(L != NULL) {
		if(L -> key <= min) min = L-> key;
		L = L -> next;
	}
	return min;
}

int main() {
	LIST L;
	initializeList(L);
	insertList(L , 3);
	insertList(L , 7);
	insertList(L , 2);
	insertList(L , 9);
	insertList(L , 33);
	cout << MaxCell(L) << " " << MinCell(L) << " ";
	return 0;
}
