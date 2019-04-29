#include<stdio.h>

/* Power Crisis - 151 */
main(){

int regioes,pulocerto,pulo,cont1,cont2,i,vet[101];

scanf("%d",&regioes);
while(regioes>0){
 pulocerto=0;
 pulo=1;
 while(pulocerto==0){
   for(i=1;i<=regioes;i++)
    vet[i]=0;
    cont1=0;
    cont2=i=1;
   while(vet[13]==0){
    if(vet[i]==0)
     cont2--;
    if(vet[i]==0 && cont2==0){
     vet[i]=1; cont1++; cont2=pulo; }
    i++;
    if(i%regioes!=0)
     i=i%regioes;
    else
     i=regioes;
    }
   if(cont1==regioes)
    pulocerto=pulo;
   else
    pulo++; 
  }
  printf("%d\n",pulocerto);
  scanf("%d",&regioes);
 }
}
