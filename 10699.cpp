#include<stdio.h>
#include<math.h>

/* Count the factors - 10699 */

long ehprime(long n){

long i=2,cont=0,flag;
 
 while(n%2==0)
 {
  n/=2;
  cont=1; 
 }  
 i=3;
 while(n>1)
 { 
  flag=0;
  while(n%i==0)
  {
   flag=1;
   n/=i;  
  }  
  if(flag)
   cont++;
  i+=2;  
 }
 printf("%ld\n",cont);
 
 return 0;
}  

main(){

long i,n; 
 
 while(1)
 {
  scanf("%ld",&n);
  if(n==0)
   break; 
  printf("%ld : ",n);
  ehprime(n);    
 }  
}
