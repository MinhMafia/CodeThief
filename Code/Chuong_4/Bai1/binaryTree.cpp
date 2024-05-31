#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
typedef struct CELL* TREE ;

struct CELL {
    int key;
    TREE left ,right;
};

TREE T;

bool snt(int k) {
    if (k <= 1) return false;
    if (k == 2 || k == 3) return true;
    if (k % 2 == 0 || k % 3 == 0) return false;
    for (int i = 5; i * i <= k; i += 6) {
        if (k % i == 0 || k % (i + 2) == 0) return false;
    }
    return true;
}

void initializeTree(TREE &T) {
    T = NULL;
}

void insertTree(TREE &T, int k) {
    if(T == NULL) {
        T = new (CELL);
        T -> key = k;
        T -> left = NULL ; T -> right = NULL;
    } else {
        if(T -> key > k ) {
            insertTree(T -> left, k);
        } else if( k > T -> key) {
            insertTree(T -> right, k);
        }
    }
}

bool searchTree(TREE x , int k) {
    if(x == NULL) return false ;
    if(x != NULL && x -> key == k) {
        return true;
    } else {
        if(x -> key > k) return searchTree(x ->left, k);
        if(x -> key < k) return searchTree(x ->right, k);
    }
}

void LNR_treeWalk(TREE x) {
    if(x != NULL) {
        LNR_treeWalk(x-> left);
        cout << x -> key << " ";
        LNR_treeWalk(x-> right);
    }
}

void NLR_treeWalk(TREE x) {
    if(x != NULL) {
        cout << x -> key << " ";
        NLR_treeWalk(x -> left);
        NLR_treeWalk(x -> right);
    }
}

void LRN_treeWalk(TREE x) {
    if(x != NULL) {
        LRN_treeWalk(x -> left);
        LRN_treeWalk(x -> right);
        cout << x -> key << " ";
    }
}

int deleteMin(TREE &T) {
    int min ;
    if( T -> left == NULL) {
        min = T  -> key;
        T = T -> right;
        return min;
    }
    else  return deleteMin(T -> left);
}

void deleteTree(TREE &T , int k) {
    if(T  != NULL) 
        if( k < T -> key) deleteTree(T ->  left, k);
            else if(k > T -> key) deleteTree(T -> right, k);
                else if(T -> right == NULL) T = T -> left;
                    else if(T -> left == NULL) T = T -> right;
                        else deleteMin(T -> right);
}

//xuất số chẵn giảm dần
void bai5(TREE T) {
    if(T != NULL) {
        if(T -> right != NULL) bai5(T -> right);
        if(T -> key % 2 == 0) cout << T -> key << " ";
        if(T -> left != NULL) bai5(T -> left);
    }
}

//xuất số chia hết cho 3 giảm dần
void bai6(TREE T) {
    if(T != NULL) {
        if(T -> right != NULL) bai6(T -> right);
        if(T -> key % 3 == 0) cout << T -> key << " ";
        if(T -> left != NULL) bai6(T -> left);
    }
}

//Đếm số nút
int bai7(TREE T) {
    if(T == NULL) return 0;
    else return 1 + bai7(T -> left) + bai7(T -> right);
}

//tính tổng giá trị các nút
int bai8(TREE T) {
    if(T == NULL) return 0;
    else return T -> key + bai8(T -> left) + bai8(T -> right);
}

//Tổng lẻ
int bai9(TREE T) {
    if(T == NULL) return 0;
    else return ((T -> key % 2 != 0) ? T -> key : 0) + bai9(T -> left) + bai9(T -> right);
}

//mức của nút có khóa k
int bai14(TREE T , int k , int level = 0) {
    if( T == NULL) return -1;
    if(T -> key == k) return level;

    if(T -> key > k) return bai14(T -> left , k , ++level);
    else if(T -> key < k) return bai14(T -> right , k , ++level);
}

//đếm số nút lá
int bai15(TREE T) {
    if(T == NULL) return -1;
    if(T->left == NULL && T->right == NULL) return 1;
    return bai15(T->left) + bai15(T->right);
}

//chiều cao của 1 cây
int bai16(TREE T) {
    if(T == NULL) return -1;
    int h1 = bai16(T -> left);
    int h2 = bai16(T -> right);
    return 1 + max(h1, h2);
}

//xuất các nút trên dường đi đến k
void bai17(TREE T , int k)  {
    if(T == NULL) return;
    cout << T -> key << " ";
    if(k < T->key) bai17(T -> left, k);
    else if(k > T->key) bai17(T -> right, k);
}

// tổng số nút ở mức i
int bai18(TREE T , int i) {
    if(T == NULL) return 0;
    if(i == 0) return 1;
    return bai18(T -> left, i - 1) + bai18(T -> right, i-1);
}

//đếm số nút có khóa chẵn.
int bai19(TREE T) {
    if(T == NULL) return 0;
    int count = (T -> key % 2 == 0 ) ? 1 : 0;
    return count + bai19(T -> left) + bai19(T -> right);
}

// đếm nút có 1 con trong cây nhị phân.
int bai20(TREE T) {
    if(T == NULL) return 0;
    int count = ((T->left == NULL) != (T->right == NULL)) ? 1 : 0;
    return count + bai20(T -> left) + bai20(T -> right);
}

//đếm nút có 2 con trong cây nhị phân.
int bai21(TREE T) {
    if(T == NULL) return 0;
    int count = (T->left != NULL && T->right != NULL) ? 1 : 0;
    return count + bai21(T -> left) + bai21(T -> right);
}

//in các nút trên mức thứ i
void bai22(TREE T ,int i) {
    if(T == NULL) return ;
    if(i == 0) cout << T -> key << " ";
    bai22(T ->left,i - 1);
    bai22(T ->right,i - 1);
}

//check xem có phải cây nhị phân tìm kiếm không
bool bai23_fake(TREE T ,int min , int max) {
    if(T == NULL) return true;
    if(T -> key < min || T -> key > max) return false;
    return bai23_fake(T -> left, min , T -> key - 1) && bai23_fake(T -> right,T -> key + 1,  max);
}

bool bai23(TREE T){
    return  bai23_fake(T, INT_MIN , INT_MAX);
}

//in ra các nút lá là snt 
void cau_3c_De_22_23(TREE T) {
    if (T == NULL) return;
    if (T->left == NULL && T->right == NULL) {
        if (snt(T->key)) {
            cout << T->key << " ";
        }
    }
    cau_3c_De_22_23(T->left);
    cau_3c_De_22_23(T->right);
}

double cau_3d_De_21_22(TREE T) {
    if(T == NULL) return -1;
    else {
        double left = bai15(T -> left) ;
        double right = bai15(T -> right);
        if (left == 0 || right == 0) return -1;
        return  right / left ;
    }
}

void debug_print_tree(TREE T, string prefix = "") {
    if (T == NULL) return;
    cout << prefix << T->key << endl;
    debug_print_tree(T->left, prefix + "L-");
    debug_print_tree(T->right, prefix + "R-");
}


int main() {
    initializeTree(T);
    insertTree(T , 30);
    insertTree(T , 20);
    insertTree(T , 50);
    insertTree(T , 11);
    insertTree(T , 25);
    insertTree(T , 24);
    insertTree(T , 26);

    insertTree(T , 40);
    insertTree(T , 60);
    insertTree(T , 33);
    insertTree(T , 45);
    insertTree(T , 42);
    insertTree(T , 48);

    // cout << "Tree structure:" << endl;
    // debug_print_tree(T);

    // LRN_treeWalk(T);
    // bai5(T);
    // bai6(T);
    // cout << bai7(T);
    // cout << bai8(T);
    // cout << bai14(T  , 33);
    // cout << bai15(T) ;
    // cout << bai16(T);
    // bai17(T , 45);
    // cout << bai18(T , 2);
    // cout << bai19(T);
    // cout << bai20(T);
    // cout << bai21(T);
    // bai22(T, 2);
    // cout << bai23(T) ? "1" : "0";
    // cau_3c_De_22_23(T);
    cout << (double)cau_3d_De_21_22(T);
    



    return 0;
}

