#include<iostream>

using namespace std;
typedef struct CELL* LIST ;
struct CELL{
	int key ; 
	LIST next , prev;
};
LIST L;

void initializeList(LIST &L) {
	L = NULL;
}

void insertList (LIST &L , int k) {
	LIST x = new(CELL);
	x -> prev = NULL , x -> key = k , x -> next = L;
	if(L != NULL) L -> prev = x;
	L = x ;
	x -> prev = NULL;
}

int min_Even(LIST L ) {
	LIST x = L ;
	int min = -1;
	if(L != NULL) {
		min = x -> key ;
		while(x != NULL) {
			if(x -> key < min && x -> key % 2 == 0) min = x -> key; //Lon nhat thi thay "<" thành ">"
			x = x -> next;
		}
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
	cout << min_Even(L);
	return 0;
}
