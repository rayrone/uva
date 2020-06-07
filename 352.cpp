#include<stdio.h>

/*  The Seasonal War - 352 */

void eagles(int i,int j,char image[][28]){

      image[i][j] = '0';
       
        if(image[i-1][j-1] == '1')
          eagles(i-1,j-1,image);
               
        if(image[i-1][j] == '1')
          eagles(i-1,j,image);
      
        if(image[i-1][j+1] == '1')
          eagles(i-1,j+1,image);
              
        if(image[i][j-1] == '1')
          eagles(i,j-1,image);
        
        if(image[i][j] == '1')
          eagles(i,j,image);
        
        if(image[i][j+1] == '1')
          eagles(i,j+1,image);
        
        if(image[i+1][j-1] == '1')
          eagles(i+1,j-1,image);
        
        if(image[i+1][j] == '1')
          eagles(i+1,j,image);
        
        if(image[i+1][j+1] == '1')
          eagles(i+1,j+1,image);
          
}

main(){
       
int c=0,e,i,j,n;
char aux[27][28],image[27][28];
   
    while(scanf("%d",&n)!=EOF){
   
       for(i=0;i<n;i++)
        scanf("%s",aux[i]);
       
       for(i=0;i<=n+1;i++)
        for(j=0;j<=n+1;j++)
         image[i][j] = '\0'; 
   
       for(i=0;i<n;i++)
        for(j=0;j<=n;j++)
         image[i+1][j+1] = aux[i][j]; 
       
       e = 0;
       
       for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         if(image[i][j] == '1')
         {
            eagles(i,j,image);  
            e ++;
         }  
       
      printf("Image number %d contains %d war eagles.\n",++c,e); 
    }

}
