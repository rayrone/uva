#include<stdio.h>
#include<math.h>

/* Prime Factors - 583 */

long long ehprime(long long n){

long long i;

 while(n%2==0)
 {
  printf("2");
  n/=2;
  if(n!=1)
   printf(" x ");
 }  
 i=3;
 while(i<=sqrt(n)+1)
 {  
  if(n%i==0)
  {
   printf("%lld",i);
   n/=i;
   if(n!=1)
    printf(" x ");  
  }  
  else
   i+=2;  
 }
 if(n>1)
  printf("%lld",n);
  
 return 0;
}  

main(){

long long i,n; 
 
  while(1)
 {
  scanf("%lld",&n);
  if(n==0)
   break; 
  printf("%lld = ",n);
  if(n<0)
  {
   printf("-1 x ");
   n=n*(-1);
  }
  ehprime(n); 
  printf("\n");   
 }  
}
