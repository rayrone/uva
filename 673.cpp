#include<stdio.h>
#include<string.h>

/* Parentheses Balance - 673 */

char str[129];

int busca(int size){

int i,flag=1,posa,posf;
char aberto='0',fechado='0';

 for(i=0;i<size;i++)
 {
  switch (str[i])
  {
   case '[':
    aberto=str[i];
    posa=i;
   break;
   case '(':
    aberto=str[i];
    posa=i;
   break;
   case ']':
    fechado=str[i];
    posf=i;
   break;
   case ')':
    fechado=str[i];
    posf=i;
   break;
   }
  if(aberto=='0' && fechado!='0')
  {
   flag=0;
   break;
  }
  if(aberto!='0' && fechado!='0')
  {
   if((aberto=='(' && fechado==']') || (aberto=='[' && fechado==')'))
    flag=0;
   else
   {
   aberto='0';
   fechado='0';
   str[posa]='0';
   str[posf]='0';
   i=-1;
   }
  }
 }
 return flag;
}

main(){

int i,j,k,n,size,coch,pare,flag;

scanf("%d\n",&n);
for(i=1;i<=n;i++)
{
 j=coch=0;
 pare=0;
 flag=1;
 gets(str);
 size=strlen(str);
 if(size>=1)
 {
  for(j=0;j<size;j++)
   switch (str[j])
   {
    case '[':
     coch++;
    break;
    case '(':
     pare++;
    break;
    case ']':
     coch--;
    break;
    case ')':
     pare--;
    break;
   }
  flag=busca(size);
 }
  if(pare!=0 || coch!=0)
   flag=0;
  if(flag)
   printf("Yes\n");
  else
   printf("No\n");
 }
}
