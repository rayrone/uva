#include<stdio.h>

/* An Easy Task - 11068 */

typedef struct line Line;

struct line{
   int a;
   int b;
   int c;
};

main(){
   
    Line r1,r2;
    int Da,Dx,Dy;
    
     while(1){
              
         scanf("%d %d %d",&r1.a,&r1.b,&r1.c);
         scanf("%d %d %d",&r2.a,&r2.b,&r2.c);
         
         if(r1.a == 0 && r1.b == 0 && r1.c == 0)
          if(r2.a == 0 && r2.b == 0 && r2.c == 0)
            break;
            
         Da = r1.a*r2.b - r2.a*r1.b;
         Dx = r1.c*r2.b - r2.c*r1.b;
         Dy = r1.a*r2.c - r2.a*r1.c;   
         
         if(Da != 0)
          printf("The fixed point is at %.2f %.2f.\n",(float)Dx/Da,(float)Dy/Da);
         else
          puts("No fixed point exists."); 
     }     
}
