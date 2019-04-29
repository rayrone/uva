#include<stdio.h>

/* The Collatz Sequence - 694 */

main(){

long long n,m,i,ciclo,caso=0;


 while(1)
 {
 caso++;
 scanf("%Ld %Ld",&n,&m);
 if(n<0 && m<0)
  break;
 ciclo=1;
 printf("Case %Ld: A = %Ld, limit = %Ld, ",caso,n,m);
 while(n>1) 
 {
  if(n%2==0)
   n=n/2;
  else
  {
   n=3*n+1;
   if(n>m)
    break;
  }  
  ciclo++; 
 }
 printf("number of terms = %Ld\n",ciclo);
 }
}


