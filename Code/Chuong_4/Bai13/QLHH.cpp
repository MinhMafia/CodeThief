#include<iostream>
using namespace std;

typedef struct CELL* TREE;

struct CELL {
    string name;
    int code ,amount ,price;
    TREE  left , right ;
};

TREE T ;

void initializeTree(TREE &T) {
    T = NULL;
}

void insertTree(TREE &T, int code , string name , int amount , int price) {
    if(T == NULL) {
        T = new (CELL);
        T->code = code;
        T->name = name;
        T->amount = amount;
        T->price = price;
        T->left = NULL;
        T->right = NULL;
    } else {
        if(code > T -> code) insertTree(T -> right,code,name,amount,price);
        else if(code < T -> code) insertTree(T -> left,code,name,amount,price);
    }
}

void xuatNameByPrice(TREE T,int k) {
    if(T!=NULL) {
        if(T->price == k) cout << T -> name << " " ;
        xuatNameByPrice(T-> left,k);
        xuatNameByPrice(T-> right,k);
    }
}

int sumPrice(TREE T) {
    if(T == NULL) return 0;
    else  return T -> price + sumPrice(T -> left) + sumPrice(T -> right);
}

int main() {
    insertTree(T, 5 , "Pen" , 5 , 3000);
    insertTree(T, 6 , "Pencil" , 5 , 3000);
    insertTree(T, 2 , "Watch" , 5 , 8000);
    insertTree(T, 8 , "Erase" , 5 , 3000);
    insertTree(T, 3 , "Ruler" , 5 , 35000);
    insertTree(T, 4 , "Book" , 5 , 44000);
    insertTree(T, 10 , "Glass" , 5 , 3000);

    // xuatNameByPrice(T , 3000);
    cout << sumPrice(T);
    return 0;
}