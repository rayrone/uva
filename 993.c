#include<stdio.h>
#include<stdlib.h>

/* Product of digits - 993 */

int cmd(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){

    int c,i,j,k,q[50];
    long m,n,prod;
    
    scanf("%d",&c);
    for(i = 0 ; i < c ; i++){
       scanf("%ld",&n);
       if(n == 1){
          puts("1");
          continue;
       }
       m = n;
       k = 0;
       prod = 1;   
       for(j = 9 ; j >= 2 ; j--)
         while(n % j == 0){
            q[k] = j;
            prod *= j;
            n = n / j;
            k++;
         } 
       qsort(q,k,sizeof(int),cmd);   
       if(prod != m)
         puts("-1");
       else{
         for(j = 0 ; j < k ; j++)
          printf("%d",q[j]);
         putchar('\n');
       }    
    }
    return 0;
}
