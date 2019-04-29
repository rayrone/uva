#include<stdio.h>
#include<ctype.h>
#include<string.h>

/* Love Calculator - 10424 */

int sum(int love){

int i,j,aux1,aux2,ant,vet[5];

 i=0; aux1=10; aux2=1; ant=0;
 while(love/aux2>0)
 {
  vet[i]=(love%aux1-ant)/aux2;
  ant=love%aux1; 
  aux1*=10; 
  aux2*=10;
  i++;   
 }
 love=0;
 for(j=0;j<=i-1;j++)
  love+=vet[j];
 return love;
}

int love(char* name,int size){

int i,love=0;

 for(i=0;i<size;i++)
 {
  if(islower(name[i]))
	love+=name[i]-96;
  else
	if(isupper(name[i]))
	 love+=name[i]-64;
 }
 while(love>9)
  love=sum(love);
return love;
}


main(){

int i,sh,sm;
float lh,lm,ratio;
char h[26],m[26];

 while(1)
 {
  if(gets(h)==NULL)
	break;
  gets(m);
  sh=strlen(h);
  sm=strlen(m);
  lh=love(h,sh);
  lm=love(m,sm);
  if(lh<lm)
	ratio=lh/lm*100;
  else
	ratio=lm/lh*100;
  printf("%.2f %%\n",ratio);
 }
}
