#include<stdio.h>

void initialise(int arr[5][5]) {
    int i,j, count=0;
    for(i=0; i<5;i++) {
        for(j=0;j<5;j++) {
            arr[i][j] = count;
            count++;
        }
    }
}

void printmatrix(int arr[5][5]) {
    int i,j;
    for(i=0; i<5;i++) {
        for(j=0;j<5;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printdiagonal(int arr[5][5]){
    int i,j,sum=0;
    while(sum<9) {
        i=0;
        j=sum;
        while(i+j==sum && i<=sum && j>=0) {
            printf("%d ",arr[i][j]);
            i++;
            j--;
        }
        printf("\n");
        sum++;
    }
}

int main() {
    int arr[5][5];
    int i,j;
    initialise(arr);
    printmatrix(arr);
    printdiagonal(arr);
    return 0;

}
