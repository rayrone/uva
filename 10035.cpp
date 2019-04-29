#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Primary Arithmetic - 10035 */

int maior,n1[10],n2[10],n3[11];
char str1[11],str2[11];

int justify(int t1,int t2){

int i;

 maior=t1;
 if(t1>t2)
 {
  for(i=1;i<=t2;i++)
  {
   n2[t1-i]=n2[t2-i];
   n2[t2-i]=0;
  }    
 }
 if(t1<t2)
 {
  maior=t2;
  for(i=1;i<=t1;i++)
  {
   n1[t2-i]=n1[t1-i];
   n1[t1-i]=0;
  } 
 }

 return maior; 
}

int convert(int t1,int t2){

int i;
char aux[2];
 
 for(i=0;i<t1;i++)
 {
  aux[0]=str1[i];
  n1[i]=atoi(aux);  
 }
 for(i=0;i<t2;i++)
 {
  aux[0]=str2[i];
  n2[i]=atoi(aux);  
 }
 
 return 0;
}

int inicializa(){

int i;

 for(i=0;i<102;i++)
 { 
   n1[i]=0;   
   n2[i]=0;
   n3[i]=0;
 }
 
 return 0;
}

int add(int maior){

int i,cont=0;

  for(i=0;i<maior;i++)
   n3[i]+=n1[i]+n2[i];
 
  for(i=maior-1;i>0;i--)
   if(n3[i]>=10)
   {
    cont++;
    n3[i-1]+=n3[i]/10;
    n3[i]=n3[i]%10;
   }
 if(n3[0]>=10)
  cont++;
  
 return cont;  
}

main(){

int i,t1,t2,maior,cont;

 while(true)
 {
  inicializa();
  scanf("%s %s",str1,str2);
  if(atoi(str1)==0 && atoi(str2)==0)
   break;
  t1=strlen(str1);
  t2=strlen(str2);
  convert(t1,t2);
  maior=justify(t1,t2);
  cont=add(maior);  
  if(cont==0)
   printf("No carry operation.");
  if(cont==1)
   printf("%d carry operation.",cont);
  if(cont>1)
   printf("%d carry operations.",cont);
  printf("\n");
 }
}




