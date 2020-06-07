#include<stdio.h>
#include<stdlib.h>

/* Exact Sum - 11057 */

int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;          
}

main(){
       
   int i,j,k,n,money,v[10000];
   int *p1,*p2;
     
     while(scanf("%d",&n)!=EOF){
         
        for(k=0;k<n;k++)
         scanf("%d",&v[k]);
        
        scanf("%d",&money);
        
        qsort(v,n,sizeof(int),cmp); 
        
        i = money/2;
        j = money - i;
        
        while(1)
        {
            
            p1 = (int*)bsearch(&i,v,n,sizeof(int),cmp);   
            
            p2 = (int*)bsearch(&j,v,n,sizeof(int),cmp);
            
            if(p1 == p2)
             p2++;
                      
            if(p1!=NULL && p2 != NULL && p1!=p2)
                break; 
              
            i--;
            j = money-i;             
        
        }    
        
         printf("Peter should buy books whose prices are %d and %d.\n\n",i,j);  
     
     }

}
