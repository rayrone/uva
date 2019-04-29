#include<stdio.h>

/* A Graph Problem - 11069 */

main(){

int i,one=0,two,a1=0,a2=1;
unsigned long t[76];
     
    for(i=0;i<76;i++)
    {
       two  =  one;
       one  =  a1 + a2;
       t[i] = one + two;
       a1 = a2;
       a2 = two;
    } 
     
    while(scanf("%d",&i)!=EOF)
      printf("%lu\n",t[i-1]);
       
} 
