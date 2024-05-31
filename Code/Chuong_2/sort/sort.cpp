#include<iostream>
using namespace std;
#define MAXN 500

void insertionSort(int a[] , int n)  {
    for(int j = 1 ; j < n ; j++) {
        int key = a[j];
        int i = j - 1;
        while(i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i+1] = key;
    }
}
//• Kết luận về độ phức tạp
//  Tốt nhất T(n)= O(n)
//  Trung bình T(n)= O(n2)
//  Xất nhất T(n)= O(n2)
void swap(int &x , int &y) {
    int temp = x;
    x = y;
    y = temp;
}
void selectionSort(int a[] , int n) {
    for(int i = 0; i < n - 1; i++) {
        int k = i;
        for(int j = i + 1 ; j < n; j++) 
            if(a[j] < a[k]) k = j;
        swap(a[k] , a[i]);
    }
} // T = O(n2)

void bubbleSort(int a[] , int n) {
    for(int i = n - 1 ; i >= 1; i --) {
        for(int j = 0 ; j <= i - 1;j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
} // T = O(n2)

void quickSort(int a[] , int l , int r) {
    int p = a[(l + r) / 2];
    int i = l , j = r;
    while( i < j) {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if(i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if( i < r ) quickSort(a,i,r);
    if( l < j ) quickSort(a,l,j);
}  /* Đối với Quicksort */
/* Tốt nhất T(n) = O(nlog2n) */
/* Xấu nhất T(n) = O(n2) */
/* Trung bình T(n) = O(nlog2n) */

void mergeParts(int a[] , int l , int mid , int r) {
    int i = l , j = mid + 1;
    int k = 0;
    int* temp = new int[MAXN];
    while(i <= mid && j <= r) {
        int nextValue ;
        if(a[i] < a[j]) nextValue = a[i++];
        else nextValue = a[j++];
        temp[k++] = nextValue;
    }
    while(i <= mid ) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];

    for(int i = 0 ; i < k ; i++) a[l+i] = temp[i];
    delete[] temp;
}

void mergeSort(int a[] , int l , int r) {
    if(l >= r) return;
    int mid = (l + r)/2;

    mergeSort(a , l , mid);
    mergeSort(a , mid + 1, r);

    mergeParts(a , l , mid , r);
} //O(N*log(N))

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

int main() {
    int a[] = { 4, 1 , 8 ,3 , 9 ,7  ,2 , 8 , 0 ,23};
    int b[4][5] = { {4, 1 , 8 ,3 , 9 },
                  {5, 7 , 8 ,3 , 9 },
                  {2, 1 , 8 ,3 , 5 },
                  {4, 1 , 2 ,3 , 9 }};

    int n = sizeof(a) / sizeof(a[0]);
    // insertionSort(a , n);
    // selectionSort(a , n);
    // bubbleSort(a , n);
    // quickSort(a,0,n-1);
    // mergeSort(a,0,n-1);
    // radixsort(a,n);
    // for(int i = 0 ; i < 4; i++) {
        // insertionSort(b[i],5);
    // } // sắp từng hàng dãy 2 chiều

    // for(int i = 0 ; i < n ; i++) {
        // cout << a[i] << endl;
    // }
    // for(int i = 0 ; i < 4 ; i++) {
        // for(int j = 0 ; j < 5 ; j++) {
            // cout << b[i][j] << " ";
        // } cout << endl;
    // } // xuất 2 chiều
    return 0;

}