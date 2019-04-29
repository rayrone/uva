#include<stdio.h>
#include<stdlib.h>

/* Number Chains - 263 */

int ordem;

int cmp(const void *a,const void *b){
  return *(int*)b-*(int*)a;  
}
 
long converte(long n){

int i,j,k,ant,aux1,aux2,num[9];

i=0; aux1=10; aux2=1; ant=0;
while(n/aux2>0){
 num[i]=(n%aux1-ant)/aux2;
 ant=n%aux1; i++; aux1*=10; aux2*=10; } 
qsort(num,i,sizeof(int),cmp);
aux1=1; n=0;
if(ordem)
for(j=0;j<=i-1;j++){
  n+=aux1*num[j]; aux1*=10; }
else
for(j=i-1;j>=0;j--){
  n+=aux1*num[j]; aux1*=10; }
return n;
}

main(){

int i,j,ciclo,repetido;
long n,n1,n2,rep[1000];

while(1){
 scanf("%ld",&n);
 if(n==0) break;
 repetido=ciclo=i=0;
 printf("Original number was %ld\n",n);
 while(!repetido){
  ordem=1; n1=converte(n);
  ordem=0; n2=converte(n); 
  for(j=0;j<i-1;j++)
   if(rep[i-1]==rep[j])
    repetido=1;
  rep[i]=n=n2-n1; i++;
  if(!repetido){
   printf("%ld - %ld = %ld\n",n2,n1,n2-n1); ciclo++; }
 }
 printf("Chain length %d\n",ciclo);
 printf("\n");
}
}
