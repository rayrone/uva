#include<stdio.h>

/* 10050 - Hartals */

main(){

int i,j,k,n,cont,dias,partidos,hartal,vet[3651];

 while(scanf("%d",&n)!=EOF)
   for(i=1;i<=n;i++){
     scanf("%d %d",&dias,&partidos);
     for(j=1;j<=dias;j++)
      vet[j]=0;
     for(j=1;j<=partidos;j++){
       scanf("%d",&hartal);
       if(hartal!=0)
        for(k=hartal;k<=dias;k+=hartal)
         vet[k]=1; 
     }
     cont=0;
     for(k=1;k<=dias;k++)
      if(k%7!=0 && k%7!=6)
       if(vet[k]==1)
        cont++;
     printf("%d\n",cont);
   }
}
