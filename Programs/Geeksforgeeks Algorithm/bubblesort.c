/*
First Pass:
( 5 1 4 2 8 ) > ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) >  ( 1 4 5 2 8 ), Swap since 5 > 4
( 1 4 5 2 8 ) >  ( 1 4 2 5 8 ), Swap since 5 > 2
( 1 4 2 5 8 ) > ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
Second Pass:
( 1 4 2 5 8 ) > ( 1 4 2 5 8 )
( 1 4 2 5 8 ) > ( 1 2 4 5 8 ), Swap since 4 > 2
( 1 2 4 5 8 ) > ( 1 2 4 5 8 )
( 1 2 4 5 8 ) >  ( 1 2 4 5 8 )
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.
Third Pass:
( 1 2 4 5 8 ) > ( 1 2 4 5 8 )
( 1 2 4 5 8 ) > ( 1 2 4 5 8 )
( 1 2 4 5 8 ) > ( 1 2 4 5 8 )
( 1 2 4 5 8 ) > ( 1 2 4 5 8 )
Following is C implementation of Bubble Sort.
*/

#include <stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

