#include<stdio.h>
#include<stdlib.h>

/* Vito's family - 10041 */

int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}

main(){
       
int i,c,r,sum,relatives[500];
   
     
     scanf("%d",&c);
     for(;c>0;c--){
          
        scanf("%d",&r);
        
        for(i=0;i<r;i++)
         scanf("%d",&relatives[i]);
        
        qsort(relatives,r,sizeof(int),cmp);
        
        sum = 0;
        
        for(i=0;i<r;i++)
         sum += abs(relatives[r/2]-relatives[i]); 
        
        printf("%d\n",sum);
         
     }

}
