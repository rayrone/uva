#include<stdio.h>

/* Ackermann Functions - 371 */

main(){

int i,cont,maior;
long l,h,n,num;

while(1){
 scanf("%ld %ld",&l,&h);
 if(l==0 && h==0) break;
 maior=n=1;
 if(l>h){
  l^=h;
  h^=l;
  l^=h;
 }
 printf("Between %ld and %ld,",l,h);
 if(l<h/2)
  l=h/2;
 for(i=l;i<=h;i++){
  num=i; cont=0;
  do{
	if(num%2==0)
	 num=num/2;
	else
	 num=3*num+1;
	cont++;
  }while(num>1);
  if(cont>maior){
   maior=cont; n=i; } 
 }
 printf(" %ld generates the longest sequence of %d values.\n",n,maior);
}
}
