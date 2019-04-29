#include<stdio.h>

/* 500! - 623 */

int t1,t2,n1[3000],vet[1001][3000];

int converte(int num){

 int i,aux1,aux2,ant;
 
 t1=0; 
 aux1=10; 
 aux2=1; 
 ant=0;
 while(num/aux2>0)
 {
  n1[t1]=(num%aux1-ant)/aux2;
  ant=num%aux1; 
  aux1*=10; 
  aux2*=10; 
  t1++;
  }
 return 0; 
}

int multiplica (int t1,int t2,int num){

 int i,j,k,aux=0;
  
  for(i=0;i<t2;i++)
  {
   k=aux; 
   for(j=0;j<t1;j++)
   {     
    vet[num][k]+=vet[num-1][i]*n1[j];
    k++;
   }
   aux++;
  }
 for(i=0;i<=k;i++)
  if(vet[num][i]>9)
  {
   vet[num][i+1]+=vet[num][i]/10;
   vet[num][i]=vet[num][i]%10;
  }
 return i;  
}

main(){

int i,j,num,aux[1001]; 

 n1[0]=1;
 t1=1;
 t2=1;
 
 for(i=1;i<1001;i++)
  for(j=0;j<3000;j++)
   vet[i][j]=0;
 
 for(i=0;i<1001;i++)
   aux[i]=0;
 
 vet[0][0]=vet[1][0]=1;
 
 for(i=2;i<=1000;i++)
 {
  converte(i);
  t2=multiplica(t1,t2,i);
  }
 for(i=0;i<=1000;i++)
  for(j=t2;j>=0;j--)
   if(vet[i][j]==0)
    aux[i]++;
   else
    break;     
    
 while(scanf("%d",&num)!=EOF)
 {
  printf("%d!\n",num);
  for(i=t2-aux[num];i>=0;i--)
   printf("%d",vet[num][i]); 
  printf("\n");
 }
}  
