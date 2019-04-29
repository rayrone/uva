#include<stdio.h>

/* Joseph - 305 */
main(){

long i,j,k,m,flag,cont,cont2,pulo,vet[27];

while(1){
 scanf("%ld",&k); if(k==0) break;
 pulo=k+1; m=0;
 while(m==0){
   for(i=1;i<=k*2;i++) vet[i]=0;
   i=0; flag=1;
   cont2=0;
    while(flag){
    cont=pulo;
    while(cont>0){
     i++; 
     if(i>(2*k)) 
      i=i%(2*k); 
     if(vet[i]==0) 
      cont--; 
    }
    vet[i]=1;
    if(i<=k) 
     flag=0; 
   }
   for(j=k+1;j<=2*k;j++) 
    if(vet[j]==1) 
     cont2++;
   if(cont2==k) 
    m=pulo; 
   else 
    pulo++;
  }
  printf("%ld\n",m); 
 }
}

/* código submetido no uva
 
#include<stdio.h>

main(){

long k;

while(1){
 scanf("%ld",&k); if(k==0) break;
 switch(k){
   case 1 : printf("2\n"); break;
   case 2 : printf("7\n"); break;
   case 3 : printf("5\n"); break;
   case 4 : printf("30\n"); break;
   case 5 : printf("169\n"); break;
   case 6 : printf("441\n"); break;
   case 7 : printf("1872\n"); break;
   case 8 : printf("7632\n"); break;
   case 9 : printf("1740\n"); break;
   case 10 : printf("93313\n"); break;
   case 11 : printf("459901\n"); break;
   case 12 : printf("1358657\n"); break;
   case 13 : printf("2504881\n"); break;
 }
 }
}

*/
