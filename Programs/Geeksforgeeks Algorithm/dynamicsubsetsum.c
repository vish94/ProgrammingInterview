// A recursive solution for subset sum problem
#include <stdio.h>

// Returns true if there is a subset of set[] with sun equal to given sum
int isSubsetSum(int set[], int n, int sum) {
   // Base Cases
   if (sum == 0)
     return 1;
   if (n == 0 && sum != 0)
     return 0;

   // If last element is greater than sum, then ignore it
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);

   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element   */
   return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

// Driver program to test above function
int main() {
  int T;
  scanf("%d",&T);
  while(T--) {
      int set[21];
      int sum, n, i=0;
      scanf("%d %d", &n, &sum);
      for(i=0; i<n; i++) {
        scanf("%d", &set[i]);
      }
      if (isSubsetSum(set, n, sum) == 1)
         printf("YES\n");
      else
         printf("NO\n");
  }
  return 0;
}
