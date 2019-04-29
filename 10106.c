#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Product - 10106 */

int n1[251],n2[251],vet[501];

int converte(char *num1,char *num2,int t1,int t2){

char aux[2];
int i;

 for(i=0;i<t1;i++)
 {
  aux[0]=num1[i];
  n1[i]=atoi(aux);
 }
 for(i=0;i<t2;i++)
 {
  aux[0]=num2[i];
  n2[i]=atoi(aux);
 }
 return 0;
}

int inicializa(){

 int i;

 for(i=0;i<251;i++)
 {
  n1[i]=1;
  n2[i]=1;
 }
 for(i=0;i<501;i++)
  vet[i]=0;
 return 0;
}

int multiplica (int t1,int t2){

 int i,j,k,aux=0;

  for(i=t2-1;i>=0;i--)
  {
   k=aux;
   for(j=t1-1;j>=0;j--)
   {
    vet[k]+=n2[i]*n1[j];
    k++;
   }
   aux++;
  }
 for(i=0;i<k;i++)
  if(vet[i]>=10)
  {
   vet[i+1]+=vet[i]/10;
   vet[i]=vet[i]%10;
  }
 return k;
}

main(){

int i,t,t1,t2;
char num1[252],num2[252];

 while(scanf("%s %s",num1,num2)!=EOF)
 {
  if(num1[0]=='0' || num2[0]=='0')
   printf("0\n");
  else
  {
   inicializa();
   t1=strlen(num1);
   t2=strlen(num2);
   converte(num1,num2,t1,t2);
   t=multiplica(t1,t2);
   for(i=t;i>=0;i--)
   {
    if(i==t && vet[i]==0)
     continue;
    printf("%d",vet[i]);
   }
   printf("\n");
  }
 }
}
