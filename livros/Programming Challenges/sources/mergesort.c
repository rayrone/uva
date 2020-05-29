#include<stdio.h>
#include<stdlib.h>

/* Algoritmo do merge */

void merge(int size,int v1[], int v2[], int v[]){
              
     int c,c1,c2; 
   
     c = c1 = c2 =0;
   
     do{
         if(v1[c1] <= v2[c2]){
            v[c] = v1[c1];
            c1++;            
         }else{
            v[c] = v2[c2];
            c2++; 
         }
         c++;       
     }while(c1 < size / 2 && c2 < size / 2);
   
     if(c1 >= size / 2)
        while(c2 < size / 2 + 1){
            v[c] = v2[c2];
            c2++;
            c++;            
        }
     if(c2 >= size / 2)
        while(c1 < size / 2 + 1){
            v[c] = v1[c1];
            c1++;
            c++;            
        }
}

main(){
  
  int size = 10;
  int i, v1[size/2], v2[size/2], v[size];
  
   for(i=0;i<5;i++)
      scanf("%d",&v1[i]);
   for(i=0;i<5;i++)
      scanf("%d",&v2[i]);
   merge(size,v1,v2,v);
   
   for(i=0;i<10;i++)
      printf("%d ",v[i]);        
   
   puts("");
    
   system("PAUSE");
}
