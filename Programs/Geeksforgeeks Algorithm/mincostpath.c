#include<stdio.h>
#define R 3
#define C 3

int min(int x, int y, int z) {
    int a,b;
    a = x<y?x:y;
    b = y<z?y:z;
    return a<b?a:b;
}

int find_min_cost(int cost[3][3], int x, int y) {
    if(x<0 || y<0)
        return 0;
    else if(x==0 && y==0)
        return cost[x][y];
    else
        return cost[x][y] + min(find_min_cost(cost,x-1,y-1),find_min_cost(cost,x-1,y), find_min_cost(cost,x,y-1));
}

int dynamic_min_cost(int cost[R][C], int m, int n)
{
     int i, j;

     // Instead of following line, we can use int tc[m+1][n+1] or
     // dynamically allocate memoery to save space. The following line is
     // used to keep te program simple and make it working on all compilers.
     int tc[R][C];

     tc[0][0] = cost[0][0];

     /* Initialize first column of total cost(tc) array */
     for (i = 1; i <= m; i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];

     /* Initialize first row of tc array */
     for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j-1] + cost[0][j];

     /* Construct rest of the tc array */
     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i-1][j-1], tc[i-1][j], tc[i][j-1]) + cost[i][j];

     return tc[m][n];
}

int main() {
    int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
    printf("Naive Solution: %d\n", find_min_cost(cost, 2,2));
    printf("Dynamic Solution %d", dynamic_min_cost(cost,2,2));
    return 0;

}
