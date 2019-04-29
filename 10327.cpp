#include<stdio.h>

/* Flip Sort - 10327 */

main(){
       
int n,i,j,k,cont,vet[1000];

 while(scanf("%d",&n)!=EOF)
 {
  cont=0;
  for(j=0;j<n;j++)
   scanf("%d",&vet[j]);
  for(j=1;j<=n;j++)
   for(k=0;k<n-1;k++)
  	if(vet[k]>vet[k+1])
    {
	 vet[k]^=vet[k+1];
	 vet[k+1]^=vet[k];
	 vet[k]^=vet[k+1];
	 cont++;
	}
  printf("Minimum exchange operations : %d\n",cont);
 }
}
