#include<stdio.h>
 
/* The Land of Justice - 10499 */

int main() {
 
    double n;
  
    while(scanf("%lf",&n)!=EOF) {
       if(n < 0) 
          break;
       if(n == 1)
          printf("0%%\n");
       else
           printf("%.0lf%%\n",n * 25); 
    }
    return 0;
}
