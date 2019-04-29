
#include<stdio.h>
#include<ctype.h>

/* Pig-Latin - 492 */

main(){

char a,b,first=1;

 while(scanf("%c",&a)!=EOF)
 { 
  if(!isalpha(a) && first==0)
  {
   first=1;
   if(b=='A' || b=='E' || b=='I' || b=='O' || b=='U' || b=='a' || b=='e' || b=='i' || b=='o' || b=='u')
    printf("ay%c",a);
   else
    printf("%cay%c",b,a);
  }
  else
   if(first && isalpha(a))
   {
    if(a=='A' || a=='E' || a=='I' || a=='O' || a=='U' || a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
     printf("%c",a);
    b=a;
    first=0; 
   }
   else
    printf("%c",a);         
 }
}
