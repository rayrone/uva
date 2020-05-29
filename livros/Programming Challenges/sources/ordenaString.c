#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void* a, const void* b){
     return( strcmp((char *)a,(char *)b) );         
}

main(){
       
       int i,n;
       char in[6],names[100][51];
       
       while(1){
                
                n = atoi(gets(in));
                
                if(n == 0)
                 break;
                
                for(i = 0 ; i < n ; i++)
                  gets(names[i]);
                
                qsort((void*)names,n,sizeof(names[0]),cmp);
                
                for(i = 0 ; i < n ; i++)
                  puts(names[i]);
                  
                putchar('\n');  
       }  

}
