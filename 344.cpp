#include<stdio.h>

/* Roman Digititis - 344 */

main(){

int i,n,m,rom[2][10];
char letras[9];

rom[0][0]=100; rom[0][1]=90;  rom[0][2]=50;  rom[0][3]=40;  rom[0][4]=10;   
rom[0][5]=9;   rom[0][6]=5;   rom[0][7]=4;   rom[0][8]=1;   rom[0][9]=0;

letras[0]='i'; letras[2]='v'; letras[4]='x'; letras[6]='l'; letras[8]='c';
 
 while(1)
 {
  scanf("%d",&n);
  if(n==0)
   break;
  for(i=0;i<10;i++)
   rom[1][i]=0; 
  printf("%d:",n);
  while(n)
  {
   m=n;
   i=0;
   while(rom[0][i]!=0)
   {
    if(rom[0][i]==90 || rom[0][i]==40 || rom[0][i]==9 || rom[0][i]==4) 
     switch(rom[0][i])
     {  
      case 90:
       rom[1][0]+=m/rom[0][i];
       rom[1][4]+=m/rom[0][i]; 
      break;
      case 40:
       rom[1][2]+=m/rom[0][i];
       rom[1][4]+=m/rom[0][i]; 
      break;
      case 9:
       rom[1][4]+=m/rom[0][i];
       rom[1][8]+=m/rom[0][i]; 
      break;
      case 4:
       rom[1][6]+=m/rom[0][i];
       rom[1][8]+=m/rom[0][i]; 
      break;
     }
    else 
     rom[1][i]+=m/rom[0][i]; 
    m%=rom[0][i++]; 
   }
    n--; 
  }   
  for(i=8;i>=0;i-=2)
  {
   if(i!=0) 
    printf(" %d %c,",rom[1][i],letras[8-i]);
   else
    printf(" %d %c",rom[1][i],letras[8-i]); 
  }
  printf("\n");
 }
}
