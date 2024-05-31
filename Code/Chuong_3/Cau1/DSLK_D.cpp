#include<iostream>
#include<limits.h>
using namespace std;
typedef struct CELL* LIST;

struct CELL {
	int key;
	LIST next;
};

LIST L ;

void ListWalk(LIST L);

void initializeList(LIST &L) {
	L = NULL;
}

//Chèn vào đầu
void insertList (LIST &L , int k) {
	LIST x = new (CELL) ;
	x -> key = k;
	x -> next = L;
	L = x;
}

LIST ListSearch(LIST L , int k) {
	LIST x = L ;
	while( x != NULL && x -> key != k) {
		x = x -> next ;
	}
	return x;
}

void ListDelete(LIST &L , int k) {
	LIST x , y;
	if ( L != NULL) {
		y = NULL ; x = L;
	}
	while (x != NULL && x -> key != k) {
		y = x ; x  = x -> next;
	}
//	ListWalk(y);
//	cout << endl;
	if(x != NULL) {
		if( y == NULL) L = x -> next ;
		else y -> next = x -> next;
		delete(x);
	}
}

int listWidth(LIST L) {
	if(L == NULL) return 0;
	else return 1 + listWidth(L -> next);
}

void ListWalk(LIST L) {
	if(L != NULL) {
		cout << L -> key << " ";
		ListWalk(L -> next);
	}
}

//Tổng phần tử lẻ
int cau7(LIST L) {
	LIST x;
	int sum = 0 ;
	if(L != NULL) x = L ;
	while(x != NULL) {
		if(x-> key % 2 != 0) sum += x-> key;
		x = x -> next;
	}
	return sum;
}

//Tổng chẵn , chia hết cho 3
int cau8(LIST L) {
	LIST x;
	int sum = 0 ;
	if(L != NULL) x = L ;
	while(x != NULL) {
		int temp = x-> key;
		if(temp % 2 == 0 && temp % 3 == 0 ) sum += x-> key;
		x = x -> next;
	}
	return sum;
}

//Đệ quy chèn cuối
void cau9(LIST &L, int k ) {
	if(L == NULL) {
		L = new (CELL);
		L -> key = k;
		L -> next = NULL;
	}
	else {
		cau9(L -> next, k);
	}
}

//Sắp xếp tăng
void cau13(LIST &L3) {
	if(L3 == NULL || L3->next == NULL) return;
	LIST sorted = NULL;
	LIST current = L3;

	while(current != NULL) {
		LIST nextNode = current -> next;
		if(sorted == NULL || sorted -> key > current->key) {
			current -> next = sorted;
			sorted = current;
		} else {
			LIST temp = sorted ;
			while(temp -> next != NULL && temp -> next -> key < current -> key) {
				temp = temp -> next;
			}
			current -> next = temp -> next ;
			temp -> next = current;
		}
		current = nextNode;
	}
	L3 = sorted ;
}

//  chèn 1 số k sau số m
void cau15(LIST &L , int k ,int m) {
	LIST x = L;
	LIST y = new(CELL);
	y -> key = k ;
	y -> next = NULL;
	while(x != NULL && x -> key != m) {
		x = x -> next;
	} 
	if(x != NULL) {
		y -> next = x -> next ;
		x -> next = y;
	}
}

bool snt( int k) {
	if(k == 2 || k == 3 ) return true;
	if(k == 0 || k == 1 || k % 2 == 0 || k % 3 == 0) return false;
	for(int i = 4 ; i <= (k/2) ; i++) {
		if(k % i == 0) return false;
	}
	return true;
}

//chèn sau 1 snt đầu tiên
void cau16(LIST &L , int k ) {
	LIST x = L;
	LIST y = new(CELL);
	y -> key = k ;
	y -> next = NULL;
	//while(x != NULL && x -> key % 2 != 0) nếu muốn sau chẵn
	//{ x = x -> next; }
	while(x != NULL) {
		if (snt(x -> key)) break;
		x = x -> next;
	} 
	if(x != NULL) {
		y -> next = x -> next ;
		x -> next = y;
	}
}

//Đảo ngược dslk đơn
void cau17(LIST &L ) {
	if(L == NULL || L -> next == NULL) return;
	LIST x = L ;
	LIST reverse = NULL ;

	while (x != NULL) {
        LIST newNode = new CELL;
        newNode->key = x->key;
        newNode->next = reverse;
        reverse = newNode;
        x = x->next;
    }
	L = reverse;

}
//cách 2 của câu 17
void reverseList(LIST &L) {
    LIST prev = NULL;
    LIST current = L;
    LIST next = NULL;

    while (current != NULL) {
        next = current->next; // Lưu trữ con trỏ tới nút tiếp theo
        current->next = prev; // Đảo ngược liên kết của nút hiện tại
        prev = current;       // Di chuyển prev đến nút hiện tại
        current = next;       // Di chuyển current đến nút tiếp theo
    }

    L = prev; // Cập nhật đầu danh sách
}

void cau_2c_De_22_23(LIST& L) {
	if(L == NULL) return ;
	LIST x = L;
	while(x != NULL) {
	if( x -> key % 2 == 0) {
		x -> key  = x -> key + 1;
	}
	x = x -> next;
	}
}

//tìm giá trị nhỏ nhất thứ 2
int cau_2b_De_21_22(LIST L) {
	if(L == NULL) return -1;
	int min1 = INT_MAX, min2 = INT_MAX;
    LIST x = L;

    // Tìm min1 và min2 trong một lần duyệt
    while (x != NULL) {
        if (x->key < min1) {
            min2 = min1;
            min1 = x->key;
        } else if (x->key < min2 && x->key != min1) {
            min2 = x->key;
        }
        x = x->next;
    }

    // Kiểm tra nếu min2 vẫn là INT_MAX thì danh sách không có giá trị nhỏ thứ 2 hợp lệ
    if (min2 == INT_MAX) return -1;

    return min2;
}

void cau_2c_De_21_22(LIST L ,int k) {
	if(L == NULL) return;
	else {
		LIST x = L;
		while(x != NULL) {
			if(x -> key > k) cout << x -> key <<" ";
			x = x -> next;
		}
	}
}

// xxóa các phần tử bé hơn k
void cau_2d_De_21_22(LIST &L ,int k) {
	if(L == NULL) return;
	else {
		while(L != NULL && L->key < k) {
			LIST temp = L;
			L = L -> next;
			delete(temp);
		}

		if(L == NULL) return;

		LIST current = L ; 
		while(current -> next != NULL) {
			if(current -> next -> key < k ) {
				LIST temp = current -> next;
				current -> next = current -> next -> next;
				delete(temp);
			} else {
				current = current -> next;
			}

		}
	}

}
void cau_2a_20_21(LIST &L, int x, int i) {
    LIST temp = new CELL;
    temp->key = x;
    temp->next = NULL;

    if (i == 0) {
        temp->next = L;
        L = temp;
        return;
    } else {
        LIST y = L;
        while (y != NULL && i != 1) {
            y = y->next;
            i -= 1;
        }
        if (y != NULL) {
            temp->next = y->next;
            y->next = temp;
        } else {
            // Trường hợp i lớn hơn số lượng phần tử hiện tại, chèn vào cuối danh sách
			LIST last = L;
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = temp;
        }
    }
}

int cau_2b_20_21(LIST L, int x) {
	if(L == NULL) return -1;
	int count = 0;
	LIST y = L;
	while(y != NULL && y -> key != x) {
		y = y -> next;
		count++;
	}
	if(y != NULL) return count;
	else return -1;
}

double cau_2c_20_21(LIST x) {
	if(x == NULL) return -1;
	else {
		int count = 0;
		int sum = 0;
		while(x != NULL) {
			count++;
			sum += x -> key;
			x = x -> next;
		} 
		return (double)sum / (double)count;
	}
}

int main() {
	LIST L;
	initializeList(L);
	insertList(L , 5);
	insertList(L , 7);
	insertList(L , 2);
	insertList(L , 7);
	insertList(L , 9);
	insertList(L , 1);
	cau_2a_20_21(L,11,2);
	// cau17(L);
	// cau16(L ,4);
	// cau15(L , 1 ,4);
//	for(int i = 0 ; i < 5 ; i++) {
//		int temp ;
//		cin >> temp;
//		insertList(L , temp);
//	}
	// ListDelete(L  , 7);
	// cau9(L , 8);
	// cau13(L);
	// cout << listWidth(L) << endl;
	// cau_2c_De_22_23(L);
	
	// cout << endl << cau7(L) << endl;
	// cout << cau8(L) << endl;
	// cout << cau_2b_De_21_22(L);
	// cau_2c_De_21_22(L, 2);
	// cau_2d_De_21_22(L, 7);
	// cout << cau_2b_20_21(L, 7);
	cout << cau_2c_20_21(L);

	// ListWalk(L);
	
	return 0;
}


