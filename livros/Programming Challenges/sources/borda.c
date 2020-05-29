#include<stdio.h>
#include<stdlib.h>

/* Algoritmo para inserir borda em uma matriz. by Rayrone */

main(){

int n,m,i,j;
char aux[11],mat[12][13];

     
     scanf("%d %d",&n,&m);
     
     for(i=0;i<=n+1;i++)
         for(j=0;j<=m+1;j++)
            mat[i][j] = '@'; 
   
     for(i=0;i<n;i++){
         scanf("%s",aux);
         for(j=0;j<m;j++)
           mat[i+1][j+1] = aux[j];             
     }
     
     for(i=0;i<=n+1;i++){
       for(j=0;j<=m+1;j++)
         printf("%c",mat[i][j]);
       putchar('\n');
     } 
     system("PAUSE");
}
