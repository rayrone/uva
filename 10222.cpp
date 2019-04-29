#include<stdio.h>
#include<ctype.h>

/* Decode the Mad man - 10222 */

main(){

int i;
char c,teclado[50];

sprintf(teclado,"´1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./");
while(scanf("%c",&c)!=EOF){
   if(c==' ')
    printf(" ");
   else
   {
    if(isupper(c))
     c=tolower(c);
    for(i=0;i<47;i++)
     if(c==teclado[i])
      printf("%c",teclado[i-2]);
   }
   if(c=='\n')
    printf("\n");
 }
}
