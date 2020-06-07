#include<stdio.h>

/* You can say 11 - 10929 */

main(){

int i,a,b;
char n[1001]; 
   
   while(1)
   {
      scanf("%s",n);
      
      a=0;
      b=0;
      
      for(i=0;n[i]!='\0';i++)
      {
        if(i%2==0)
         a+=n[i]-48;
        else 
         b+=n[i]-48;
      }
      
      if(a+b==0)
       break;
      
      if((a-b)%11==0)
       printf("%s is a multiple of 11.\n",n);
      else
       printf("%s is not a multiple of 11.\n",n);    
   }
}
