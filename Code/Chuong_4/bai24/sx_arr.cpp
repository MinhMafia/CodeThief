#include<iostream>
using namespace std;
typedef struct CELL* TREE ;

struct CELL {
    int key;
    TREE left ,right;
};

TREE T;

void initializeTree(TREE &T) {
    T = NULL;
}

void insertTree(TREE &T, int k) {
    if(T == NULL) {
        T = new (CELL);
        T -> key = k;
        T -> left = NULL;
        T -> right = NULL;
    } else {
        if(k > T -> key ) insertTree(T -> right, k);
        else if(k < T -> key ) insertTree(T -> left, k);
    }
}

void sort_temp(TREE T, int arr[], int &index) {
    if(T == NULL) return;
    sort_temp(T -> left, arr, index);
    arr[index++] = T -> key;
    sort_temp(T -> right, arr, index);
}

void sort(int arr[], int size) {
    TREE temp = NULL;
    for(int i = 0; i < size; i++) {
        insertTree(temp, arr[i]);
    }
    int index = 0;
    sort_temp(temp, arr, index);
    delete temp;
}

int main() {
    int arr[] = {30, 20, 50, 15, 25, 40, 60, 33, 45, 42, 48};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sắp xếp mảng
    sort(arr, size);

    // In ra mảng đã sắp xếp
    cout << "Mảng sau khi đã sắp xếp: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}