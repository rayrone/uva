#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Anagrams II - 630 */

int cmp(const void *a,const void *b){
 return *(char*)a-*(char*)b;
}

main(){

int i,j,c,n,cont,size;
char aux[21],aux1[21],mat[21][1000],words[21][1000];

scanf("%d",&c);
for(i=1;i<=c;i++){
 scanf("%d",&n);
 for(j=0;j<n;j++)
  scanf("%s",words[j]);
 for(j=0;j<n;j++)
  strcpy(mat[j],words[j]);
 for(j=0;j<n;j++){
  size=strlen(mat[j]);
  qsort(mat[j],size,sizeof(char),cmp); }
 while(1)
 {
  scanf("%s",aux);
  cont=1;
  if(!strcmp(aux,"END"))
   break;
  size=strlen(aux);
  printf("Anagrams for: %s\n",aux);
  strcpy(aux1,aux);
  qsort(aux,size,sizeof(char),cmp);
  for(j=0;j<n;j++)
   if(!strcmp(aux,mat[j])){
    printf("  %d) %s\n",cont,words[j]);
    cont++; }
  if(cont==1)
   printf("No anagrams for: %s\n",aux1);
  }
  if(i!=c)
   printf("\n");
 }
}
