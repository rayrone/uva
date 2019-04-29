#include<stdio.h>
#include<stdlib.h>

/* Prime Frequency - 10789 */

typedef struct{
   char c;
   int f;
}Alpha_numerals;

int comp(Alpha_numerals *a,Alpha_numerals *b){
   return a-b;
}

int isprime(int n){

int i;

  if((n%2==0 && n!=2) || n == 1)
   return 0;
  for(i=3;i<=sqrt(n);i+=2)
   if(n%i==0)
    return 0;

 return 1;
}  

main(){
       
int i,c=0,T,size,flag,(*cmp)() = comp;
char str[2002];
Alpha_numerals A[62]; 

    scanf("%d",&T);
    
    for(;T>0;T--){
       
       for(i=0;i<62;i++)
        A[i].f = 0;
       
       flag = 0;
        
       scanf("%s",str);
       
       for(i=0;str[i]!='\0';i++)
        if(isupper(str[i]))
        {
          A[str[i]-'A'+10].f++;
          A[str[i]-'A'+10].c = str[i];
        }
        else
         if(islower(str[i]))
         {
           A[str[i]-'a'+36].f++;
           A[str[i]-'a'+36].c = str[i];
         }
         else
         {
           A[str[i]-'0'].f++;
           A[str[i]-'0'].c = str[i];  
         }
       
       qsort(A,62,sizeof(Alpha_numerals),cmp);
       
       printf("Case %d: ",++c);
       for(i=0;i<62;i++)
        if(isprime(A[i].f))
        {
          putchar(A[i].c);
          flag = 1;
        }
        
       if(!flag)
        puts("empty");
       else
        putchar('\n'); 
        
    }
    
}
