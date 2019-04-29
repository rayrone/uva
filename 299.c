#include<stdio.h>

/* Train Swapping - 299 */

int main(){

  int n, l, i, j, k, cont, vet[50];

    scanf("%d",&n);
    for(i = 1 ; i <= n ; i++) {
       scanf("%d",&l);
       cont=0;
       for(j = 0 ; j < l ; j++)
         scanf("%d",&vet[j]);
       for(j = 1 ; j <= l ; j++)
         for(k = 0 ; k < l-1 ; k++)
            if(vet[k] > vet[k+1]){
                vet[k]  ^= vet[k+1];
                vet[k+1]^= vet[k];
	            vet[k]  ^= vet[k+1];
	            cont++;
            }
       printf("Optimal train swapping takes %d swaps.\n",cont);
    }
    return 0;
}
