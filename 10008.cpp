#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/* What's Cryptanalysis? - 10008 */

typedef struct{
   char l;
   int f;    
}Letter;

int comp(Letter* a,Letter* b){
   
   if(a->f == b->f)
    return a->l - b->l;
   return b->f - a->f;   
}

main(){

int (*cmp)() = comp;       
int i;
Letter v[26];
    
    for(i=0;i<26;i++)
    {
      v[i].l = i+65;
      v[i].f = 0;  
    }    
    
    while(scanf("%c",&i)!=EOF){
                              
        if(isalpha(i))
         v[toupper(i)-'A'].f++;
    
    }
    qsort(v,26,sizeof(Letter),cmp);
    
    for(i=0;i<26;i++)
     if(v[i].f != 0)
      printf("%c %d\n",v[i].l,v[i].f); 
    
}
