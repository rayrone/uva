#include<stdio.h>
#include<stdlib.h>

/* Simple Base Conversion - 10473 */

main(){

int i,num;
char vet[15];

while(1){
  scanf("%s",vet);
  if(vet[1]=='x'){
   sscanf(vet,"0x%X",&num);
   printf("%d\n",num); }
  else{
   if(atol(vet)<0) break;
   sscanf(vet,"%d",&num);
   printf("0x%X\n",num); }
 }
}
