#include<stdio.h>

/* VERY EASY !!! - 10523 */

int num[16][151][200];

void inicializa(int *vet,int *result){

  int i;
  
    for(i=0;i<3;i++)
       vet[i]=0;
    for(i=0;i<200;i++)
       result[i]=0;
}

void quebra(int j,int *vet){
 
 int i,aux1,aux2,ant;
 
 i=0; aux1=10; aux2=1; ant=0;
 
  while(j/aux2>0)
  {
    vet[i]=(j%aux1-ant)/aux2;
    ant=j%aux1; 
    aux1*=10; 
    aux2*=10; 
    i++;
  }
}

void potencia(void){

 int i,j,k;
 
   for(i=1;i<=15;i++)
   {   
       num[i][1][199]=i;
     
       for(j=2;j<=150;j++)
       {
          for(k=199;k>=0;k--)
            num[i][j][k]=num[i][j-1][k]*i;
     
          for(k=199;k>0;k--)
          
           if(num[i][j][k]>9)
           {
              num[i][j][k-1]+=num[i][j][k]/10;
              num[i][j][k]%=10;
           }
       }      
    }   
}

void multiplica(void){
 
   int i,j,k,l,aux1,aux2,lim,vet[3],result[200];
   
   for(i=1;i<=15;i++)
     for(j=1;j<=150;j++)
     {
        if(j<10)
         lim=1;
        if(j>9 && j<100)
         lim=2;
        if(j>99)
         lim=3;
         
        inicializa(vet,result);
        quebra(j,vet);
        aux2=199;
         
        for(k=199;k>1;k--)
        {
           aux1=aux2; 
           for(l=0;l<lim;l++)
           {     
              result[aux1]+=num[i][j][k]*vet[l];
              aux1--;
           }
           aux2--;
        }
       for(k=199;k>0;k--)
        if(result[k]>=10)
        {
           result[k-1]+=result[k]/10;
           result[k]=result[k]%10;
        }
       for(k=199;k>=0;k--)
        num[i][j][k]=result[k];      
     }              
}

void somatorio(void){

  int i,j,k;

  for(i=1;i<=15;i++)
    for(j=1;j<=150;j++)
    {
     for(k=199;k>=0;k--)
       num[i][j][k]+=num[i][j-1][k];
     for(k=199;k>=0;k--)
       if(num[i][j][k]>9)
       {
         num[i][j][k-1]+=num[i][j][k]/10;
         num[i][j][k]%=10;
       }
    }
}

void print(int n,int a){

  int i,j=0;
  
  while(num[a][n][j]==0)
   j++;
  for(i=j;i<=199;i++)
   printf("%d",num[a][n][i]);
  printf("\n"); 
}


main(){

int i,j,k,a,n;

   for(i=0;i<16;i++)
    for(j=0;j<151;j++)
     for(k=0;k<200;k++)
      num[i][j][k]=0;
   
   potencia(); 
   multiplica();
   somatorio();
      
   while(scanf("%d %d",&n,&a)!=EOF)
   {
     if(a==0) 
      printf("0\n");
     else 
      print(n,a);    
   }     
}
