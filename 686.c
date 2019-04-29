#include<stdio.h>
#include<math.h>

/* Goldbach's Conjecture II - 686 */

int ehprime(int n){

int i;

 if((n%2==0 && n!=2)||(n%3==0 && n!=3))
  return 0;
 for(i=3;i<=sqrt(n);i+=2)
 {
  if(n%i==0)
   return 0;
 }

 return 1;
}  

main(){

int i,n,cont;
 
 while(1)
 {
  scanf("%d",&n);
  if(n==0)
   break;
  cont=0;
  if(n==4)
   cont=1; 
  for(i=3;i<=n/2;i+=2)
   if(ehprime(i))
    if(ehprime(n-i))
     cont++;
  printf("%d\n",cont);           
 }
}
