#include<stdio.h>

/* Combinations - 369 */

double fatorial(double num){

 if(num==1 || num==0)
  return 1;
 else
  return num*fatorial(num-1);
} 

main(){

int i,n,p;
double comb;

 while(1){
  scanf("%d %d",&n,&p);
  if(n==0 && p==0)
   break;
  comb=1;
  if(p<=n-p)
  {
   for(i=n;i>n-p;i--)
    comb*=i;
   comb/=fatorial(p);
  }
  else
  {
   for(i=n;i>p;i--)
    comb*=i;
   comb/=fatorial(n-p);
  }
  printf("%d things taken %d at a time is %.0lf exactly.\n",n,p,comb);   
 }
}
