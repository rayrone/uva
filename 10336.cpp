#include<stdio.h>
#include<stdlib.h>

/* Rank the Languages - 10336 */

typedef struct{
   int  n;
   char s;     
}States;

int comp(States *a,States *b){
  
  if(a->n == b->n)
   return a->s - b->s;
  return b->n - a->n;    
}

void rank(char map[][103],int x,int y,char state){
     
     map[x][y]='#';
     
     if(map[x][y-1] == state)
      rank(map,x,y-1,state);
     
     if(map[x][y+1] == state)
      rank(map,x,y+1,state);
           
     
     if(map[x-1][y] == state)
       rank(map,x-1,y,state);
      
     if(map[x+1][y] == state)
      rank(map,x+1,y,state); 
      
}

main(){

States st[26];
int (*cmp)() = comp;
int n,i,j,k,c,l;
char map[102][103];

    scanf("%d",&n);
     
    for(k=1;k<=n;k++){
    
      scanf("%d %d",&l,&c);
     
      for(i=0;i<26;i++)
      {
        st[i].n = 0;
        st[i].s = i+97;
      }
      
      for(i=0;i<=l+1;i++)
       for(j=0;j<=c+1;j++)
         map[i][j] = '#';
      
      for(i=1;i<=l;i++)
       for(j=1;j<=c;j++)
        scanf("\n%c",&map[i][j]);
        
      for(i=1;i<=l;i++)
       for(j=1;j<=c;j++)
        if(map[i][j]!='#')
        {
          st[map[i][j]-'a'].n++;
          rank(map,i,j,map[i][j]);
        }      
      
      qsort(st,26,sizeof(States),cmp);
      printf("World #%d\n",k);
      for(i=0;i<26;i++)
       if(st[i].n != 0)
        printf("%c: %d\n",st[i].s,st[i].n);   
   } 
}
