#include<stdio.h>
#include<ctype.h>

/* Kindergarten Counting Game - 494 */

main(){

int flag=1,cont=0;
char a;

 while(scanf("%c",&a)!=EOF)
 {
  if((a==' '|| a=='\n' || isdigit(a) || ispunct(a))&& flag)
  {
    flag=0;
    cont++;
  }  
  else
   if(isalpha(a) && !flag)
    flag=1;
  if(a=='\n')
  {
   printf("%d\n",cont);
   cont=0;
  }  
 }
}
