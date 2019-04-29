#include<stdio.h>
#include<string.h>

/* All in All - 10340*/
main(){


int ts,tt,i,j;
long cont;
char s[100001],t[100001];

while(scanf("%s %s",s,t)!=EOF){
  ts=strlen(s); tt=strlen(t); cont=0; j=-1;
  if(ts<=tt){
  for(i=0;i<ts;i++)
   while(j<tt){
    j++;
    if(s[i]==t[j]){
    cont++; break;}
   }  
  }
 if(cont==ts)
  printf("Yes\n");
 else
  printf("No\n"); 
 }
}
