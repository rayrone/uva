#include<stdio.h>

/* Oil Deposits - 572 */

void eagles(int i,int j,char image[][103]){

      image[i][j] = '*';
       
        if(image[i-1][j-1] == '@')
          eagles(i-1,j-1,image);
               
        if(image[i-1][j] == '@')
          eagles(i-1,j,image);
      
        if(image[i-1][j+1] == '@')
          eagles(i-1,j+1,image);
              
        if(image[i][j-1] == '@')
          eagles(i,j-1,image);
        
        if(image[i][j] == '@')
          eagles(i,j,image);
        
        if(image[i][j+1] == '@')
          eagles(i,j+1,image);
        
        if(image[i+1][j-1] == '@')
          eagles(i+1,j-1,image);
        
        if(image[i+1][j] == '@')
          eagles(i+1,j,image);
        
        if(image[i+1][j+1] == '@')
          eagles(i+1,j+1,image);
          
}

main(){
       
int i,j,m,n,oil;
char aux[102][103],image[102][103];
   
    while(1){
       
       scanf("%d %d",&m,&n);
       if(m == 0)
        break;
              
       for(i=0;i<m;i++)
        scanf("%s",aux[i]);
       
       for(i=0;i<=m+1;i++)
        for(j=0;j<=n+1;j++)
         image[i][j] = '\0'; 
   
       for(i=0;i<=m;i++)
        for(j=0;j<=n;j++)
         image[i+1][j+1] = aux[i][j]; 
       
       oil = 0;
       
       for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
         if(image[i][j] == '@')
         {
            eagles(i,j,image);  
            oil ++;
         }  
       
      printf("%d\n",oil);
       
    }

}
