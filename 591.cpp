#include<stdio.h>

/* Box of Bricks - 591 */

main(){

   int i,j,k,c=0,n,N[50];
   
    while(1){
    
       scanf("%d",&n);
       if(n==0)
        break;
       
       j = k = 0;
       
       for(i=0;i<n;i++)
       { 
         scanf("%d",&N[i]);
         j += N[i];       
       }
       
       j /=n;
       
       for(i=0;i<n;i++)
        if(N[i] < j)
         k += j - N[i]; 
       
       printf("Set #%d\n",++c);
       printf("The minimum number of moves is %d.\n\n",k);

    }

}
