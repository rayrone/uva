#include<stdio.h>

/* Minesweeper - 10189 */

int main() {

    int i, j, n, m, cont=0, campo=0;
    char vet[102], mat[102][103];

    scanf("%d %d",&n,&m);
    while(n!=0 && m!=0) {
      for(i=0;i<=n+1;i++)
         for(j=0;j<=m+1;j++)
            mat[i][j]='.';
      for(i=1;i<=n;i++) {
         scanf("%s",vet);
         for(j=1;j<=m;j++)
           mat[i][j]=vet[j-1]; 
      }
      campo++;

      if(campo!=1)
        printf("\n");
        printf("Field #%d:",campo);
      for(i=1;i<=n;i++) {
        printf("\n");
        for(j=1;j<=m;j++) {
           cont=0;
           if(mat[i][j]=='.') {
              if(mat[i-1][j-1]=='*')
                cont++;
              if(mat[i-1][j]=='*')
                cont++;
              if(mat[i-1][j+1]=='*')
                cont++;
              if(mat[i][j-1]=='*')
                cont++;
              if(mat[i][j+1]=='*')
                cont++;
              if(mat[i+1][j-1]=='*')
                cont++;
              if(mat[i+1][j]=='*')
                cont++;
              if(mat[i+1][j+1]=='*')
                cont++;
              printf("%d",cont); 
           }
           else
               printf("*");
        }
	}
    printf("\n");
    scanf("%d %d",&n,&m);
    }
}
