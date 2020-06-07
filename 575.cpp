#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/* Skew Binary - 575 */

main(){

unsigned long i,n,x,size;
char s[32];

 while(1)
 {
  scanf("%s",s);
  if(atoi(s)==0)
   break;
  n=0;
  size=strlen(s);
  for(i=0;s[i]!='\0';i++)
  {
   n+=(int)((s[i]-48)*(pow(2,size)-1));
   size--;
  }  
  printf("%lu\n",n);
 }
 
}
