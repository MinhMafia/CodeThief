#include<iostream>
using namespace std;
typedef struct CELL* LIST;

struct CELL {
	int key;
	LIST next;
};

LIST A ;
LIST B ;

void initializeList(LIST &L) {
	L = NULL;
}

//Chèn có thứ tự tăng
void Cau10 (LIST &L , int k) {
	LIST temp = new (CELL) ;
	temp -> key = k ;
	temp -> next = NULL;
    if(L == NULL || L -> key > k) {
		temp -> next = L;
		L = temp;
    } else {
		LIST now = L;
        while(now -> next != NULL && now -> next -> key < k) {
			now = now -> next ;
    	}
		temp -> next = now -> next;
		now -> next = temp;
	}
}

//trộn 2 list đã tăng sẵn theo đệ quy
LIST Cau11_DQ(LIST L1, LIST L2) {
	if(L1 == NULL) return L2;
	if(L2 == NULL) return L1;
	LIST L3 = NULL;

	if(L1 -> key < L2 -> key) {
		L3 = L1 ;
		L3 -> next = Cau11_DQ(L1 -> next ,L2);
	}
	else {
		L3 = L2 ;
		L3 -> next = Cau11_DQ(L1 ,L2 -> next);
	}
	return L3;
}

LIST cau11_merge(LIST L1 , LIST L2) {

	LIST L3 = NULL;
	LIST current = NULL;
	while(L1 != NULL && L2 != NULL) {
		if(L1 -> key < L2 -> key) {
			if(L3 == NULL) {
			L3 = L1 ;
			current = L3;
			} else {
				current -> next = L1;
				current = current -> next;
			}
			L1 = L1 -> next;
		}
		else {
			if(L3 == NULL) {
				L3 = L2 ;
				current = L3;
			} else {
				current -> next = L2;
				current = current -> next;
			}
			L2 = L2 -> next;
		}
	}
	if(L1 == NULL) {
		if(L3 == NULL) {
			L3 = L2;
		} else {
			current -> next = L2;
		}
	}
	if(L2 == NULL) {
		if(L3 == NULL) {
			L3 = L1;
		}  else {
			current  -> next = L1;
		}
	}
	return L3;
}

void ListWalk(LIST L) {
	if(L != NULL) {
		cout << L -> key << " ";
		ListWalk(L -> next);
	}
}
int main() {
	initializeList(A);
	Cau10(A , 7);
	Cau10(A , 3);
	Cau10(A , 17);
	Cau10(A , 9);
	Cau10(A , 11);
	Cau10(A , 10);
	Cau10(A , 21);

	Cau10(B , 9);
	Cau10(B , 1);
	Cau10(B , 7);
	Cau10(B , 2);
	Cau10(B , 45);
	
	// LIST L3 = cau11_merge(A , B);
	LIST L4 = Cau11_DQ(A , B);

	// ListWalk(L3);
	ListWalk(L4);

	
	return 0;
}


