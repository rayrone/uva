#include<stdio.h>

/* WERTYU - 10082 */

main(){

int i;
char c,teclado[50];

sprintf(teclado,"´1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./");
while(scanf("%c",&c)!=EOF){
   if(c==' ')
    printf(" ");
   else
    for(i=0;i<47;i++)
     if(c==teclado[i])
      printf("%c",teclado[i-1]);
   if(c=='\n')
    printf("\n");
 }
}
