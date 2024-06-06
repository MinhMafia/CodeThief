#include<iostream>
#include<limits.h>
using namespace std;
int main() {
    int n = 8;
    int a[n] = {14 ,67, 22, 100, 2 ,31, 71, 1000};
    int min = INT_MAX;
    int x , y;
    for(int i = 0; i < n -1; i++) {

        for(int j = i + 1; j < n; j++) {
            int sub = a[i] - a[j];
            if(sub < 0) sub = -sub;
            if(sub < min ) {
                min = sub;
                x = i ; y = j;
            }
        }
    }
    cout << a[x] << " " << a[y] << endl;
    return 0;
}