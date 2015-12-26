#include<stdio.h>

int main() {
    int arr[] = {1,1,0,1,0,0,0,1,0,0,1,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i, count=0;
    for(i=0; i<n; i++) {
        if(arr[i]==1) count++;
    }
    for(i=0; i<n; i++) {
        if(i<count) arr[i]=1;
        else arr[i] = 0;
    }
    for(i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
}
