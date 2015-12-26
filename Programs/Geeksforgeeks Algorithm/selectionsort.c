/*
arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4] and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4] and
// place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4] and
// place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4] and
// place it at beginning of arr[3...4]
11 12 22 25 64
*/

#include<stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionsort(int arr[], int n) {
    int i, j, min_idx;
    for(i=0; i<n-1; i++) {
        min_idx = i;
        for(j=i+1; j<n; j++) {
            if(arr[j]<arr[min_idx])
            min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
