#include<stdio.h>
#include<string.h>
#include<math.h>

/* All You Need Is Love - 10193 */

int binario(char s[]){
    
  int i,n=0,size;
  
  size=strlen(s); 
  for(i=0;s[i]!='\0';i++)
   n+=(s[i]-'0')*(int)pow(2,--size);
  
  return n;  
}

int mdc(int a,int b){
 
  if(b!=0)
   return mdc(b,a%b);
  else
   return a; 
}

main(){
       
int c,a,b,pair=0;
char s1[31],s2[31];

  scanf("%d",&c);
  for(;c>0;c--)
  { 
    pair++;
    scanf("%s %s",s1,s2);
    a=binario(s1);
    b=binario(s2);
    if(mdc(a,b)!=1)
     printf("Pair #%d: All you need is love!\n",pair);
    else
     printf("Pair #%d: Love is not all you need!\n",pair);   
  }
}
