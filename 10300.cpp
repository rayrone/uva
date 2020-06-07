#include<stdio.h>

/* Ecological Premium - 10300 */

int main(){

int i, j, c, f, s, a, aux, farmers, premium; 

    while(scanf("%d",&c) != EOF) {
       for(i = 1 ; i <= c ; i++) {
         scanf("%d",&farmers);
         premium=0;
         for(j = 1 ; j <= farmers ; j++) {
           scanf("%d %d %d",&s,&a,&f);
           premium += s * f; 
         }
         printf("%d\n",premium);
       }
    }
    return 0;
}
