#include<stdio.h>
#include<stdlib.h>

/* Kibbles `n' Bits `n' Bits `n' Bits - 446 */

int binario(int n){

 int i;
 char vet[13];
 
 for(i=0;i<13;i++)
  vet[i]=0;
 i=-1;
 while(n>=1){
  vet[++i]=n%2;
  n/=2; 
 }
 for(i=12;i>=0;i--)
  printf("%d",vet[i]);
 
 return 0;
}

main(){

int i,c,n1,n2,result;
char s,line[10];

 scanf("%d",&c);
 for(i=1;i<=c;i++)
 {
  scanf("%X %c %X",&n1,&s,&n2);
  binario(n1);
  if(s=='+')
  {
   printf(" + ");
   result=n1+n2;
  } 
  else
  { 
   printf(" - ");
   result=n1-n2;
  } 
  binario(abs(n2));
  printf(" = ");
  printf("%d",result);
  printf("\n");
 }
} 
