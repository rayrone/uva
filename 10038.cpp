#include<stdio.h>
#include<stdlib.h>

/* Jolly Jumpers - 10038 */

main(){

int i,j,n,cont,presente,vet[3000];

 while(scanf("%d",&n)!=EOF){
   for(i=0;i<n;i++)
    scanf("%d",&vet[i]);
   for(i=0;i<n-1;i++)
    vet[i]=abs(vet[i]-vet[i+1]);
    presente=cont=1;
   for(i=1;i<=n-1;i++){
    if(!presente)
      break;
    for(j=0;j<n-1;j++)
     if(vet[j]==cont){
      presente=1;
      cont++;
      break;	
     }	
     else
      presente=0;
     }
  if(presente)
   printf("Jolly\n");
  else
   printf("Not jolly\n");
  }
}

