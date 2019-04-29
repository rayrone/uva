#include<stdio.h>
#include<math.h>

#define radius 6440

/* Satellites - 10221 */

main(){

int a,s;
double arc,chord;
char str[4];

 while(scanf("%d %d %s",&s,&a,str)!=EOF)
 {
  if(a>180)
   a=360-a;
  if(str[0]=='d')
  {
   arc=(radius+s)*(2*asin(1.0)*a/180);
   chord=2*(radius+s)*sin(asin(1.0)*a/180);
  }
  else
  {
   arc=(radius+s)*(2*acos(0.0)*a/10800);
   chord=2*(radius+s)*sin(acos(0.0)*a/(10800));   
  }
  printf("%.6lf %.6lf\n",arc,chord);  
 }
}
