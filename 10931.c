#include<stdio.h>

/* Parity - 10931 */

int main(){

    int i, j, n, cont, vet[32];

    scanf("%d",&n);
    while(n > 0) {
       for(i=0;i<31;i++)
          vet[i]=1;
       i = 1;
       j = n;
       cont = 0;
       while(j>=1) {
          vet[i] = j % 2;
          if(vet[i] == 1)
            cont++;
          i++;
          j = j / 2;
       }

       printf("The parity of ");
       for(j = i - 1 ; j > 0 ; j--)
           printf("%d",vet[j]);
       printf(" is %d (mod 2).\n",cont);
       scanf("%d",&n);
    }
    return 0;
}
