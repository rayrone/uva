#include<stdio.h>
#include<math.h>

/* Light, more light - 10110 */

main(){

unsigned long i,n,raiz;

  while(1)
  {
  scanf("%lu",&n);
  if(n==0)
   break;
  raiz=(unsigned long)sqrt(n);
  raiz*=raiz;
  if(n==raiz)
   printf("yes\n");
  else 
   printf("no\n");
 } 
}
