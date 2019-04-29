#include<stdio.h>
#include<string.h>

/* Integer Inquiry - 424 */

main(){

int i,j,t;
char n[103],sum[103]={0};
  
      sum[102] = '\0';
      
      while(1)
      {  
        
        n[103] = '\0';      
        for(i=0;i<103;i++)
         n[i] = 0;
         
        scanf("%s",n);
        
        if(n[0] == '0')
           break;
        
        t = strlen(n)-1;
        j = 102;
        
        for(i=0;i<=t;i++)
         n[i] -= 48;
          
        for(i=t;i>=0;i--,j--)
        {
          n[j]^=n[i];
          n[i]^=n[j];
          n[j]^=n[i]; 
        }
        
        for(i=j;i<=102;i++)
         sum[i] += n[i];
        
        for(i=102;i>0;i--)
        {
          sum[i-1]+=sum[i]/10;
          sum[i]%=10;
        }  
           
      }
       
      t = 0;
      while(sum[t]==0)
       t++;
      
      for(i=t;i<=102;i++)
       printf("%d",sum[i]);
      puts("");
      
}
