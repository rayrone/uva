#include<stdio.h>

/* Divide, But Not Quite Conquer! - 10190 */

main(){

long i,j,a,b,flag,vet[50];

 while(scanf("%ld %ld",&a,&b)!=EOF)
 {
  i=1;
  vet[0]=a;
  flag=1;
  if(a==0 || a==1 || b==0 || b==1)
   flag=0;
  else 
   while(a>1)
   {
    if(a%b!=0)
    {
     flag=0;
     break;
    } 
    vet[i]=a/b;
    a/=b;
    i++;
   }
  if(flag)
  {
   printf("%ld",vet[0]);
   for(j=1;j<i;j++)
    printf(" %ld",vet[j]);
  } 
  else
   printf("Boring!");
  printf("\n");    
 }
}
