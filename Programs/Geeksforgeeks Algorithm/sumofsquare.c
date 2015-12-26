#include<stdio.h>

int getsq(int n) {
    int i=1;
    if(n<=3)
        return n;

    while(i*i<=n && (i+1)*(i+1)<=n)
        i++;
    return 1 + getsq(n-(i*i));
}

int main() {
    int n;
    scanf("%d", &n);
    printf("Number of squares: %d", getsq(n));
    return 0;
}
