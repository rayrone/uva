#include<stdio.h>

/* The Department of Redundancy Department - 484 */

struct lista{
 int info;
 int freq;
 struct lista* prox;
};

typedef struct lista Lista;

Lista* inicializa(void){
 return NULL;
}

int vazia(Lista *l){
 return l==NULL;
}

void imprime(Lista *l){
 
    if(vazia(l))
     return ; 
    imprime(l->prox);
    printf("%d %d\n",l->info,l->freq);
    
}

void libera(Lista* l){
 
  Lista* p = l;
  Lista* t;
  
  while(p!=NULL){
    t = p->prox;
    free(p);
    p = t;
  }
}

Lista* busca (Lista *l,int i){
 
  Lista *p;
  
   for(p=l;p!=NULL;p=p->prox) 
    if(p->info == i)
     return p;
   return NULL;
}

Lista* insere(Lista *l,int i){
    
   Lista* p = busca(l,i);
   
     if(p == NULL)
     {
        Lista *novo = (Lista*)malloc(sizeof(Lista));
        novo->info = i; 
        novo->freq = 1;  
        novo->prox = l;
        return novo;
     }
     
     p->freq++;
         
   return l;  
}

main(){

  Lista *l;
  int n;
  
  l=inicializa();

    while(scanf("%d",&n)!=EOF)
    {
      l = insere(l,n);
    }
    
    imprime(l);
    libera(l);

}
