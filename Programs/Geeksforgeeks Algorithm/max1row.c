#include<stdio.h>

int main() {
    int mat[4][4] = { {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    int ans[4];
    int i,j;
    for(i=0; i<4; i++) ans[i]=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(mat[i][j]==1)
                ans[i]++;
        }
    }
    for(i=0; i<4;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
