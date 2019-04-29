#include<stdio.h>

/* Triangle Wave - 488 */

main(){

int i,j,k,l,c,f,a;

 scanf("%d",&c);
 for(i=1;i<=c;i++)
 {
  scanf("%d%d",&a,&f);
  for(j=1;j<=f;j++)
  {
   for(k=1;k<=a;k++)
   {
    for(l=1;l<=k;l++)
     printf("%d",k);
    printf("\n");
   }
   for(k=a-1;k>=1;k--)
   {
    for(l=k;l>=1;l--)
     printf("%d",k); 
    if(i!=c || i!=1 || f!=1)
     printf("\n");
   }
   printf("\n"); 
  }    
 }
}
