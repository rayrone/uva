#include<stdio.h>

/* Zeros and Ones - 10324 */

main(){
       
int i,j,c=0,k,n,cont,vet[1000000];
char str[1000001];


    while(scanf("%s",str)!=EOF){
        
        scanf("%d",&n);
        printf("Case %d:\n",++c);
        
        for(i=0;str[i]!='\0';i++)
         vet[i] = str[i]-48;
        
        cont = 2;
        for(k=0;str[k]!='\0';k++)
        {
           vet[k] = cont;
           if(str[k]-48 != vet[k+1])
            cont++;            
        }
     
        for(;n>0;n--)
        {
            scanf("%d %d",&i,&j);
            
            if(vet[i] == vet[j])
             puts("Yes");
            else
             puts("No");   
              
        } 
    }

}
