#include<stdio.h>

/* Perfection - 382 */

main(){

int i,n,sum,cont;

 printf("PERFECTION OUTPUT\n");
 while(1)
 {
  sum=0;
  cont=4;
  scanf("%d",&n);
  if(n==0)
   break;
  for(i=1;i<=n/2;i++)
   if(n%i==0)
    sum+=i;
  i=n;
  while(i/10)
  {
   cont--;
   i/=10;
  }
  for(i=1;i<=cont;i++)
   printf(" ");
  printf("%d  ",n);  
  if(sum==n)
   printf("PERFECT\n");
  if(sum<n)
   printf("DEFICIENT\n");
  if(sum>n)    
   printf("ABUNDANT\n");
 }
 printf("END OF OUTPUT\n");
}
