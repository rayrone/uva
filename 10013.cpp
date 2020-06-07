#include<stdio.h>

/* Super long sums - 10013 */

main(){

int i,a,b,c,m,n[1000000]; 

   
    scanf("%d",&c);
    
    for(;c>0;c--){
    
        scanf("%d",&m);
      
        for(i=0;i<m;i++){
          scanf("%d %d",&a,&b);
          n[i]=a+b;
        }
      
       for(i=m-1;i>0;i--){
         n[i-1] += n[i]/10;
         n[i]   = n[i]%10;
       }
        
       for(i=0;i<m;i++)
        printf("%d",n[i]);
      
       printf("\n");
       
       if(c!=1)
        printf("\n");
        
    }
}
