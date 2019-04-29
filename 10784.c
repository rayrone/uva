#include<stdio.h>
#include<math.h>

/* Diagonal - 10784 */

main(){

int c = 1;       
double d,n1,n2;

   while(1){
   
    scanf("%lf",&d);
    if(d == 0)
     break;
    
     n1 = ceil((3-sqrt((double)9+8*d))/2);
     n2 = ceil((3+sqrt((double)9+8*d))/2);           
     
     printf("Case %d: ",c++);
     if(n1>n2)
      printf("%.0lf\n",n1);
     else
      printf("%.0lf\n",n2);    
   }          
}
