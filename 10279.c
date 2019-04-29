#include<stdio.h>

/* Mine Sweeper - 10279 */

main(){
       
int i,j,c,n,cont,flag;
char aux[10][11],grid[12][13];

    scanf("%d",&c);
    
    for(;c>0;c--){
       
       flag = 0;
       
       scanf("%d",&n);
       
       for(i=0;i<n;i++)
        scanf("%s",aux[i]);
       
       for(i=0;i<=n+1;i++)
        for(j=0;j<=n+1;j++)
         grid[i][j] = '\0';
          
       for(i=0;i<n;i++)
        for(j=0;j<n;j++)
         grid[i+1][j+1] = aux[i][j];
       
       for(i=0;i<n;i++)
        scanf("%s",aux[i]);
       
       for(i=0;i<n;i++)
        for(j=0;j<n;j++)
         if(aux[i][j] == 'x')
         {
           cont = 0;
             
           if(grid[i][j]=='*')   
            cont++;
           if(grid[i][j+1]=='*')   
            cont++;
           if(grid[i][j+2]=='*')   
            cont++;    
         
           if(grid[i+1][j]=='*')   
            cont++;
           if(grid[i+1][j+2]=='*')   
            cont++;    
      
           if(grid[i+2][j]=='*')   
            cont++;
           if(grid[i+2][j+1]=='*')   
            cont++;
           if(grid[i+2][j+2]=='*')   
            cont++;
           
           if(grid[i+1][j+1] == '*')   
             flag = 1;
           else
             aux[i][j] = cont+'0';  
         }
       
       if(flag)
        for(i=0;i<n;i++)
         for(j=0;j<n;j++)
          if(grid[i+1][j+1] == '*')
           aux[i][j] = '*';   
         
       for(i=0;i<n;i++)
       {
         for(j=0;j<n;j++)
          putchar(aux[i][j]);
         putchar('\n');
       }
       
       if(c!=1)
        putchar('\n');
           
    }

}
