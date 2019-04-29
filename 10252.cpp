#include<stdio.h>
#include<string.h>

/* Common Permutation - 10252 */

main(){

int i,j,ta,tb,ca[26],cb[26],c[26];
char a[1001],b[1001];

 while(1)
 {
  gets(a);
  if(gets(b)==NULL)
   break;  
  for(i=0;i<26;i++)
   ca[i]=cb[i]=0;
  ta=strlen(a);
  tb=strlen(b);
  for(i=0;i<ta;i++)
   ca[a[i]-'a']++;
  for(i=0;i<tb;i++)
   cb[b[i]-'a']++;
  for(i=0;i<26;i++)
   if(ca[i]<cb[i])
    c[i]=ca[i];
   else
    c[i]=cb[i];
  for(i=0;i<26;i++)
   for(j=1;j<=c[i];j++)
    printf("%c",i+97);
  printf("\n");         
 }
}
