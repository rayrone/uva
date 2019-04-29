#include<stdio.h>

/* Funny Encryption Method - 10019 */

int binario(int n){

 int cont=0;

 while(n>=1)
 {
  if(n%2==1)
   cont++;
  n=n/2;
 }
 return cont;
}

main(){

int i,c,n,b1,b2;
char line[20];

 scanf("%d",&c);
 for(i=1;i<=c;i++)
 {
  scanf("%s",line);
  sscanf(line,"%d",&n);
  b1=binario(n);
  sscanf(line,"%x",&n);
  b2=binario(n);
  printf("%d %d",b1,b2);
  printf("\n");
 }
}
