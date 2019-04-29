#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* Football (aka Soccer) - 10194 */

typedef struct{
   char name[31];
   int points;
   int wins;
   int loses;
   int ties;
   int goal_difference;
   int goal_against;
   int goal_scored;
   int games; 
   
}Team;

int comp(Team *a,Team *b){
   
    int i;
    char t1[31],t2[31];
    
    if(a->points != b->points)
      return b->points - a->points;
    
    if(a->wins != b->wins)
      return b->wins - a->wins;
      
    if(a->goal_difference != b->goal_difference)
      return b->goal_difference - a->goal_difference;
    
    if(a->goal_scored != b->goal_scored)
      return b->goal_scored - a->goal_scored;
      
    if(a->games != b->games)
      return a->games - b->games;
      
    for(i=0;a->name[i]!='\0';i++)
     t1[i] = tolower(a->name[i]);
    
    for(i=0;b->name[i]!='\0';i++)
     t2[i] = tolower(b->name[i]);
     
    return strcmp(t1,t2);
                   
}



main(){

char aux[256],Tournament[101];
char t1[31],t2[31];
int i,j,k,N,t,g;
int  g1,g2;
int (*cmp)() = comp;
Team T[30];


      N = atoi(gets(aux));
      
      for(;N>0;N--){
          
          for(i=0;i<30;i++)
          {
             T[i].points          = 0;
             T[i].wins            = 0;
             T[i].loses           = 0;
             T[i].ties            = 0;
             T[i].goal_difference = 0;
             T[i].goal_scored     = 0;
             T[i].goal_against    = 0;
             T[i].points          = 0;
             T[i].games           = 0;
          }
          
          gets(Tournament);
          
          t = atoi(gets(aux));
          
          for(i=0;i<t;i++)
           gets(T[i].name);
          
          g = atoi(gets(aux)); 
         
          for(i=0;i<g;i++){
            
            gets(aux);
            
            j = k = 0;
            
            while(aux[j] != '#')
             t1[k++] = aux[j++];
            t1[k] = '\0';
             
            g1 = (aux[++j]-48);
            if(aux[++j] != '@')
             g1=g1*10+(aux[j++]-48);
            
            g2 = (aux[++j]-48);
            if(aux[++j] != '#')
             g2=g2*10+(aux[j++]-48);  
            
            k = 0;
            
            while(aux[++j] != '\0')
              t2[k++] = aux[j];              
            t2[k] = '\0'; 
             
            for(j=0;j<t;j++)
              if(!strcmp(T[j].name,t1))
              {
                  T[j].games++;
                  T[j].goal_scored += g1;
                  T[j].goal_against += g2;
                  T[j].goal_difference += g1-g2;
                  
                  if(g1 > g2)
                  {
                     T[j]. points += 3;
                     T[j].wins++;                
                  }
                  else
                    if(g1 < g2)
                     T[j]. loses++;
                    else
                    {
                      T[j].ties++;
                      T[j].points++;
                    }          
              }
              else
                if(!strcmp(T[j].name,t2))
                {
                   T[j].games++;
                   T[j].goal_scored += g2;
                   T[j].goal_against += g1;
                   T[j].goal_difference += g2-g1;
                   
                   if(g2 > g1)
                   {
                      T[j]. points += 3;
                      T[j].wins++;                
                   }
                   else
                     if(g2 < g1)
                      T[j]. loses++;
                     else
                     {
                       T[j].ties++;
                       T[j].points++;
                     }
                }
            
             
          }
          
          qsort(T,t,sizeof(Team),cmp);
          
          puts(Tournament);
          
          for(i=0;i<t;i++)
          {
          
             printf("%d) %s %dp, %dg ",i+1,T[i].name,T[i].points,T[i].games);                
             printf("(%d-%d-%d), ",T[i].wins,T[i].ties,T[i].loses);
             printf("%dgd (%d-%d)\n",T[i].goal_difference,T[i].goal_scored,T[i].goal_against);
          }
          
          if(N!=1)
           putchar('\n');
      }

}
