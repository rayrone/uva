#include<stdio.h>
#include<ctype.h>

/* Marvelous Mazes - 445 */

main(){

int cont=0;
char c,ant;

  while(scanf("%c",&c)!=EOF)
  {
    ant=c;
    if(isdigit(c))
     cont+=c-48;
    else
    {
     if(c=='b')
      c=' ';
     if((c=='!' || c=='\n'))
     {
       if(ant!='!')
       printf("\n"); 
     }
     else
      for(;cont>0;cont--)
       printf("%c",c);  
     cont=0;
    }    
  }
}
