#include<stdio.h>
#include<math.h>

/* The Knights Of The Round Table - 10195 */

main(){

double a,b,c,p,r,A;

  while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
  {
    p=(a+b+c)/2;
    A=sqrt(p*(p-a)*(p-b)*(p-c));
    if(a==0.0 || b==0.0 || c==0.0) 
     printf("The radius of the round table is: 0.000\n");
    else
    {
     r=A/p;
    printf("The radius of the round table is: %.3lf\n",r);
    }
  } 
}
