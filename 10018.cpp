#include<stdio.h>

/* Reverse and Add - 10018 */

 
long long inverte(long long n){

long long i,j,aux1,aux2,ant,num[11]; 

 i=0; 
 aux1=10; 
 aux2=1; 
 ant=0;
 while(n/aux2>0)
 {
  num[i]=(n%aux1-ant)/aux2;
  ant=n%aux1; 
  aux1*=10; 
  aux2*=10;
  i++;  
 }  
 aux1=1; 
 n=0;
 for(j=i-1;j>=0;j--)
 {
  n+=aux1*num[j]; 
  aux1*=10; 
 }
return n;
}

main(){

/* para funcionar no windows troca o long long por um int64*/

long long i,j,c,ciclo,n1,n2,palidrome;

 scanf("%lld",&c);
 for(i=1;i<=c;i++)
 {
  palidrome=0;
  ciclo=0;
  scanf("%lld",&n1);
  while(!palidrome)
  {
   n2=inverte(n1);
   n1=n1+n2;
   n2=inverte(n1);
   ciclo++; 
   if(n1==n2)
    palidrome=1;    
  }
 printf("%lld %lld\n",ciclo,n2);
 }
}
