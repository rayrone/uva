#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Formula 1 - 11056 */

struct pilot{
  char name[21];
  int time; 
};

typedef struct pilot Pilot;

int comp(Pilot* a,Pilot* b){
   
   char s1[21],s2[21];
   short i;
   
   if(a->time != b->time)
    return a->time - b->time;
   
   for(i=0;a->name[i]!='\0';i++)
    s1[i] = tolower(a->name[i]);
    
   for(i=0;b->name[i]!='\0';i++)
    s2[i] = tolower(b->name[i]);

   return strcmp(s1,s2);

}

main(){
  
    int i,j,n,min,sec,ms;
    Pilot p[100];
    int (*cmp)() = comp;
    
    while(scanf("%d",&n)!=EOF){
        
        for(i=0;i<n;i++)
        {
          scanf("%s : %d min %d sec %d ms",p[i].name,&min,&sec,&ms);                           
          p[i].time = 60000*min + 1000*sec + ms;
        }  
        
        qsort(p,n,sizeof(Pilot),cmp);
        
        j=1;
        
        for(i=0;i<n;i+=2)
        {
          printf("Row %d\n",j++);
          puts(p[i].name);
          if(i+1<n)
           puts(p[i+1].name);
        }   
           
        printf("\n");  
    }     
}
