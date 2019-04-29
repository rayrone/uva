#include<stdio.h>

/* Above Average - 10370 */
main(){

int c,n,i,j,cont,vet[1000];
float somed;

scanf("%d",&c);
for(i=1;i<=c;i++){
  somed=cont=0;
  scanf("%d",&n);
  for(j=0;j<n;j++){
   scanf("%d",&vet[j]);
   somed+=vet[j];
  }
  somed/=n;
  for(j=0;j<n;j++)
   if(vet[j]>somed)
    cont++;
  printf("%0.3f%\n",((float)cont/n)*100);
 }
}