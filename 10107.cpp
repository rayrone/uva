#include<stdio.h>
#include<stdlib.h>

/* What is the Median? - 10107 */

struct lista{
 unsigned long info;
 struct lista* prox; 
};

typedef struct lista Lista;

Lista* inicializa(void){
 return NULL;
}

void libera(Lista* l){
 
 Lista* p=l;
 Lista* t;
  
  while(p!=NULL){
    t = p->prox;
    free(p);
    p = t;  
  }
}

Lista* cria_no(unsigned long i){
  
  Lista* p = (Lista*)malloc(sizeof(Lista));
  p->info = i;
  return p;  
}

Lista* insere_ordenado(Lista* l,unsigned long i){
 
  Lista* novo = cria_no(i);
  Lista* p = l;
  Lista* ant = NULL;
  
    while(p!=NULL && p->info<i){
      ant = p;
      p = p->prox;
    }
    
    if(ant == NULL){
      novo->prox = l;
      l = novo;
    }
    else{
      novo->prox = ant->prox;
      ant->prox = novo;
    }

  return l;   
}

main(){

  int i,size=0;
  unsigned long x,median;   
  Lista* l;
  Lista* p;
  
   l = inicializa();  
   
   while(scanf("%lu",&x)!=EOF)
   {
      l=insere_ordenado(l,x);
      p=l;
      size++;
      i = 1;
      median = 0;
      if(size%2==0)
      {
        while(i<size/2)
        {
         p = p->prox;
         i++;
        }     
        median += p->info;
        p = p->prox;
        median += p->info;
        median/=2;
      }
      else
      {
        while(i<(size+1)/2)
        {
          p = p->prox;
          i++;
        }          
        median = p->info;     
      }    
     printf("%lu\n",median); 
   }

  libera(l); 
}
