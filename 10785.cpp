#include<stdio.h>

/* The Mad Numerologist - 10785 */
    
main(){
       
int i,j,k,l,c,n,t,cv,cc;
char nome[211],vogais[6]={"AUEOI"},consoantes[22]={"JSBKTCLDMVNWFXGPYHQZR"};

 scanf("%d",&c);
 for(i=1;i<=c;i++)
 {
  scanf("%d",&n);
  t=n;
  printf("Case %d: ",i);
  j=k=l=cv=cc=0;
  while(n!=0)
  {
   if(cv==21)
   { 
    k++;
    cv=0;
   }
   nome[j]=vogais[k];
   cv++;
   j++;
   n--;
   if(n==0)
    break;
   if(cc==5)
   {
    l++;
    cc=0;
   } 
   nome[j]=consoantes[l];
   cc++;
   j++;  
   n--; 
  }
  for(k=0;k<t-2;k+=2)
   for(l=k+2;l<t;l+=2)
    if(nome[k]>nome[l])
    {
     nome[k]^=nome[l];
     nome[l]^=nome[k];
     nome[k]^=nome[l];
    }
  for(k=1;k<t-2;k+=2)
   for(l=k+2;l<t;l+=2)
    if(nome[k]>nome[l])
    {
     nome[k]^=nome[l];
     nome[l]^=nome[k];
     nome[k]^=nome[l];
    }      
  for(n=0;n<t;n++)
   printf("%c",nome[n]);
  printf("\n");
 }
}
