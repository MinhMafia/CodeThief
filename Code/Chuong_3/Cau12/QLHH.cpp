#include<iostream>
using namespace std;

typedef struct CELL* LIST;
struct CELL {
    string code;
    string name;
    int amount;
    int price;
    LIST next;
};

LIST L;

void insert(LIST &L , string code, string name, int amount , int price) {
    LIST x = new(CELL);
    x -> code = code;
    x -> name = name;
    x -> amount = amount;
    x -> price = price;
    x -> next = L ;
    
    L = x ;
} 

void xuat_name(LIST L , int p) {
    LIST x = L;
    while(x != NULL) {
        if(x -> price == p) {
            cout << x -> name << " " ; 
        }
        x = x -> next;
    }
}

int tong(LIST L) {
    LIST x = L;
    int sum = 0;
    while(x != NULL) {
        sum += x -> price;
        x = x -> next;
    }
    return sum;
}

int main() {
    L = NULL ;
    insert(L , "AC1" , "Pen" , 4 , 5000);
    insert(L , "AC2" , "Pencil" , 4 , 5000);
    insert(L , "AC3" , "Erase" , 2 , 2000);
    insert(L , "AC4" , "Ruler" , 1 , 10000);

    xuat_name(L , 5000);
    cout << endl << tong(L);
    return 0;
}