#include<stdio.h>
#include<ctype.h>

/* Find the Telephone - 10921 */

main(){

char c,number[27]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};

 while(scanf("%c",&c)!=EOF)
 {
  if(isalpha(c))
   printf("%c",number[c-'A']);
  else
   printf("%c",c);  
 }
} 
