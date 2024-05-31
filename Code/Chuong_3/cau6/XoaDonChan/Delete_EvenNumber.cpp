#include<iostream> 
using namespace std;

typedef struct CELL* LIST ;
struct CELL {
	int key ;
	LIST next;
};

LIST L;

void initializeList(LIST &L) {
	L = NULL;
}

void insertList(LIST &L , int k) {
	LIST x = new(CELL);
	x -> key = k;
	x -> next = L;
	L = x;
}

void ListWalk(LIST L) {
	if(L != NULL) {
		cout << L -> key << " ";
		ListWalk(L -> next);
	}
}

void DeleteList(LIST &L ,int k) {
	LIST x, y ;
	if(L != NULL) {
		y = NULL , x = L;
	}
	while(x != NULL && x -> key != k) {
		y = x;
		x = x -> next;
	}
	if(x != NULL) {
		if(y == NULL) L = x -> next;
		else y -> next = x -> next;
		delete(x);
	}
}

void Delete_EvenNumber(LIST &L) {
	LIST x = L;
	while(x != NULL) {
		if(x -> key % 2 == 0) {
            LIST temp = x;
            x = x -> next;
            DeleteList(L, temp->key); // Truy?n con tr? c?n xóa
        } else {
            x = x -> next;
        }
	}
}


int main() {
	LIST L;
	initializeList(L);
	insertList(L , 4);
	insertList(L , 3);
	insertList(L , 6);
	insertList(L , 7);
	insertList(L , 2);
	insertList(L , 9);
	insertList(L , 1);
	insertList(L , 6);
	Delete_EvenNumber(L);
	ListWalk(L);
	return 0;
}
