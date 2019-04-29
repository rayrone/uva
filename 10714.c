#include<stdio.h>

/* Collinding Ants - 10714 */

main(){

int n,i,j,pos,tam,formiga,maior,menor,min,max;

 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  min=0; 
  max=0;
  scanf("%d %d",&tam,&formiga);
  for(j=1;j<=formiga;j++)
  {
    scanf("%d",&pos);
    if(pos>tam/2)
    {
        menor=tam-pos;
        maior=pos;
    }
    else
    {
        menor=pos;
        maior=tam-pos;
    }
  if(menor>min)
    min=menor;
  if(maior>max)
    max=maior;
  }
  printf("%d %d\n",min,max);
 }
}
