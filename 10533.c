#include<stdio.h>
#include<math.h>

/* Digit Primes - 10533 */

int quebra(int n){
  
   int i=0,aux1=10,aux2=1,ant=0,sum=0;
   
    while(n/aux2>0)
    {
      sum+=(n%aux1-ant)/aux2;
      ant=n%aux1; i++; 
      aux1*=10; 
      aux2*=10; 
    }
   
   return sum;
}

main(){

int i,j,t1,t2,cont[1000001] = {};
char digit[1000001] = {};
    
    for(i=2;i<1001;i++)
     if(!digit[i])
      for(j=2*i;j<=1000000;j+=i)
        digit[j] = 1;

    for(i=2;i<=1000000;i++)
      if(digit[i]!=1 && digit[quebra(i)]!=1)
        digit[i] = 2;
     
    j = 0;
      
    for(i=2;i<=1000000;i++){
      if(digit[i] == 2)
        j++;       
      cont[i] = j;  
    }         
    
    scanf("%d",&j);
    
    for(;j>0;j--)
    {
      
      scanf("%d %d",&t1,&t2);
      if(digit[t1]!= 2)
       printf("%d\n",cont[t2]-cont[t1]);
      else  
       printf("%d\n",cont[t2]-cont[t1]+1); 
      
    }  
    
}
 
