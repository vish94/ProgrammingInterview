#include<stdio.h>
void swap(long long int *xp, long long int *yp) {
    long long int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionsort(long long int arr[], int n) {
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
    int T;
    scanf("%d", &T);
    while(T--) {
        long long int a[3], ans;
        int i=0;
        long long int m=1000000007;
        for(i=0; i<3; i++) {
            scanf("%lld", &a[i]);
        }
        selectionsort(a, 3);
        ans=(a[0]%m)*((a[1]-1)%m)%m*((a[2]-2)%m)%m;
        printf("%lld\n", ans);
    }
    return 0;
}
