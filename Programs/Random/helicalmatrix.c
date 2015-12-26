#include<stdio.h>

printmatrix(int arr[4][4]) {
    int i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int i, j, dir=1, tmax=0,rmax=3,bmax=3,lmax=0;
    printmatrix(arr);

    while(tmax<=bmax && lmax<=rmax) {
        if(dir==1) {
            for(i=lmax; i<=rmax; i++) printf("%d ", arr[tmax][i]);
            tmax++;
            dir=2;
        } else if (dir==2){
            for(i=tmax; i<=bmax; i++) printf("%d ", arr[i][rmax]);
            rmax--;
            dir=3;
        } else if(dir==3) {
            for(i=rmax; i>=lmax; i--) printf("%d ", arr[bmax][i]);
            bmax--;
            dir = 4;
        } else if(dir==4) {
            for(i=bmax; i>=tmax; i--) printf("%d ", arr[i][lmax]);
            lmax++;
            dir=1;
        }
    }


    return 0;
}
