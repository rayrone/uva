#include <stdio.h>

/* 834 - Continued Fractions */

main(){

int n1,n2,quoc,rest;

while(scanf("%d %d",&n1,&n2)!=EOF){
 quoc=n1/n2;
 rest=n1%n2;
 printf("[");
 printf("%d;",quoc);
 while(rest>=0){
  n1=n2;
  n2=rest;
  quoc=n1/n2;
  rest=n1%n2;
  if (rest!=0)
   printf("%d,",quoc);
  else{
   printf("%d]",quoc);
   rest=-1; }
  }
 printf("\n");
 }
}
