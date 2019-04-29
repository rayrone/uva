#include<stdio.h>

/* The Stern-Brocot Number System - 10077 */

main(){
  int a,b,x,y,n1,n2,d1,d2;

  while(1){                
    scanf("%d %d",&a,&b);  
    if(a==1 && b==1) break;
    x=y=1; 
    n1=d2=0; 
    n2=d1=1;
    while(x!=a || y!=b){
      if((float)a/b<(float)x/y){       
        printf("L"); 
        n2=x;
        d2=y;
        x+=n1; 
        y+=d1;          
      }
      else{
        printf("R"); 
        n1=x;
        d1=y;
        x+=n2; 
        y+=d2; 
      }
    }
    printf("\n");
  }
}
