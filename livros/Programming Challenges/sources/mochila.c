#include<stdio.h>
#include<math.h>

main(){

int num_item,vet[10],i,j,k;
float cap_bolsa,peso[10],valor[10],peso_bolsa,valor_bolsa,max_valor; 

 
  while(1)
  {

    scanf("%f",&cap_bolsa); 
    if(cap_bolsa==0)
     break;	
    
    scanf("%d",&num_item);
    for(i=0;i<num_item;i++)
      scanf("%f %f",&peso[i],&valor[i]);
    
    max_valor=0;
    for(i=0;i<pow(2,num_item);i++)
    {
       k=i;
       peso_bolsa=0;
       valor_bolsa=0;
       for(j=0;j<10;j++)
       {
         vet[j]=k%2;
         k=k/2;  
       }
   
      for(j=0;j<num_item;j++)
       if(vet[j]==1)
       {
         peso_bolsa+=peso[j];
         valor_bolsa+=valor[j]; 
       } 
     
      if(peso_bolsa<=cap_bolsa)
       if(valor_bolsa>=max_valor)
        max_valor=valor_bolsa;  
    }
    printf("%0.2f\n",max_valor);
  }

}
