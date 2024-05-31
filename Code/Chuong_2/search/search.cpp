#include<iostream>
using namespace std;

bool arraySearch(int a[] , int n , int k) {
    for(int i = 0; i < n; i++) 
        if(a[i] == k)   return true;
            return false;
}

bool binarySearch(int a[] ,int n , int k) {
    int i = 0 , j = n - 1 , m ;
    while(i <= j) {
        m = (i + j) / 2;
        if(k == a[m]) return true;
        if(k > a[m]) i = m + 1;
        else j = m - 1;
    }
    return false;
}

int main() {
    int a[10] = { 4, 1 , 8 ,3 , 9 ,7  ,2 , 8 , 0 ,5 };
    for(int i = 0 ; i < 10 ; i++) {
        cout << a[i] << endl;
    }
    if(binarySearch(a, 10 , 9)) cout << "jjj";
    else cout << "mmm";
    return 0;

}