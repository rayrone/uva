#include<stdio.h>

/* Cheapest Base - 11005 */

int converte(long n, int base,int cost[]){

 int n_cost=0;
 
  do
  {
   n_cost+=cost[n%base];
   n/=base;
  }while(n!=0);
   
 return n_cost;
}


main(){

int i,j,c,Case=0,base,queries,cost[36],n_cost[36];
long n;

  scanf("%d",&c);
  for(;c>0;c--)
  {
    Case++;
    for(i=0;i<36;i++)
     scanf("%d",&cost[i]);
    scanf("%d",&queries);
    printf("Case %d:\n",Case);
    
    for(i=1;i<=queries;i++)
    { 
      scanf("%ld",&n); 
      for(base=2;base<=36;base++)
       n_cost[base-2]=converte(n,base,cost);
     
       printf("Cheapest base(s) for number %ld:",n);
      
      base=n_cost[0];
      for(j=1;j<35;j++)
       if(n_cost[j]<base)  
        base=n_cost[j];
        
      for(j=0;j<36;j++)
       if(n_cost[j]==base)
        printf(" %d",j+2);
      printf("\n");  
    }
    if(c!=1)
     printf("\n");    
  }
}
