#include<stdio.h>

/* f91 - 10696 */

long f91 (long n) {
   
   long f;

   if(n <= 100)
      return f91(f91(n + 11));
   else
       return(n - 10);
   return f;
}

int main(){

    long n;

    while(1) {
      scanf("%ld",&n);
      if(n == 0) break;
      printf("f91(%ld) = %ld\n",n, f91(n));
    }
    return 0;
}
