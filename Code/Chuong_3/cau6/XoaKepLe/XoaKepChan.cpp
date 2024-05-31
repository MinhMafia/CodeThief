#include<iostream>
using namespace std;

typedef struct CELL* LIST ;
struct CELL {
	int key;
	LIST prev , next;
};
LIST L;

void initializeList(LIST &L) {
	L = NULL;
}

void ListWalk(LIST L) {
	if(L != NULL) {
		cout <<  L -> key << " ";
		ListWalk(L -> next);
	}
}
void ListInsert (LIST &L , int k) {
	LIST x = new(CELL);
	x -> key = k , x -> prev = NULL , x -> next = L;
	if(L != NULL) L -> prev = x;
	L = x; 
	x -> prev = NULL ; //?
}

void DeleteEvenList(LIST &L ) {
	LIST x = L;
	while(x != NULL) {
		if(x != NULL && x -> key % 2 == 0) {
			if(x -> prev != NULL) x -> prev -> next = x -> next;
			else L = x -> next;
			if(x -> next != NULL) x -> next -> prev = x -> prev;
		}
		x = x -> next;
	}
	delete(x);	
}

int main() {
	LIST L;
	initializeList(L);
	ListInsert(L , 4);
	ListInsert(L , 3);
	ListInsert(L , 6);
	ListInsert(L , 7);
	ListInsert(L , 2);
	ListInsert(L , 9);
	ListInsert(L , 1);
	ListInsert(L , 6);
//	for(int i = 0 ; i < 5 ; i++) {
//		int temp ;
//		cin >> temp;
//		insertList(L , temp);

	DeleteListEven(L);
	ListWalk(L);
	return 0;
}






