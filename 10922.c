#include<stdio.h>

/* 2 the 9s - 10922 */

void degree(int s, int *cont){
 
 int n=0, aux1=10, aux2=1, ant=0; 
 
  while(s/aux2>0)
  {
    n+=(s%aux1-ant)/aux2;
    ant=s%aux1; 
    aux1*=10; 
    aux2*=10;
  }
  
  (*cont)++;
  if(n>9)
   degree(n,cont);   
  
}

main(){

int i,s,cont;
char n[1001];
 
  while(1)
  {
    scanf("%s",n);
    
    s=0;
    cont=1; 
    
    if(!atoi(n))
     break; 
   
    for(i=0;n[i]!='\0';i++)
     s+=n[i]-48;
    
    if(s%9==0)
    {
     if(s>9)
      degree(s,&cont);
      printf("%s is a multiple of 9 and has 9-degree %d.\n",n,cont);
    }
    else
     printf("%s is not a multiple of 9.\n",n);
    
  }  
}
