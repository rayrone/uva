#include<stdio.h>

int inverte(int n){/*Jonathas "inversão"*/
 int aux=n,w=0,y;   
 while(aux!=0){
   w=w*10+aux%10;  
   aux/=10;            
 }
 return w;
}
main(){
 int n;
 while(scanf("%d",&n)==1){
  if(n==inverte(n))printf("PALINDROME\n");
  else printf("NOT PALINDROME\n");
  printf("%d\n",inverte(n));
 }
}
