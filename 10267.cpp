#include<stdio.h>

/* 10267 - Graphical Editor */

char table[252][252];

int vizinhos(int y,int x,char aux){

 if(aux==table[y][x-1] && table[y][x-1]!='+')
  	 table[y][x-1]='*';
 if(aux==table[y][x+1] && table[y][x+1]!='+')
         table[y][x+1]='*';
 if(aux==table[y-1][x] && table[y-1][x]!='+')
         table[y-1][x]='*';
 if(aux==table[y+1][x] && table[y+1][x]!='+')
         table[y+1][x]='*';
  table[y][x]='+';
 return 0;
}


main(){

int i,j,x,y,x1,y1,x2,y2,linhas,colunas,presente;
char cor,aux,comando,nome[32];

   while(scanf("%c",&comando)!=EOF && comando!='X'){
     switch(comando){
      case 'I':
       scanf("%d %d",&colunas,&linhas);
        for(i=0;i<=linhas+1;i++)
        for(j=0;j<=colunas+1;j++)
         table[i][j]='O';
      break;
      case 'C':
       for(i=1;i<=linhas;i++)
        for(j=1;j<=colunas;j++)
         table[i][j]='O';
      break;
      case 'L':
        scanf("%d %d %c",&x,&y,&cor);
        table[y][x]=cor;
      break;
      case 'V':
        scanf("%d %d %d %c",&x,&y1,&y2,&cor);
        if(y1>y2){
         x2=y1;
         y1=y2;
         y2=x2;
        }
         for(i=y1;i<=y2;i++)
         table[i][x]=cor;
      break;
      case 'H':
        scanf("%d %d %d %c",&x1,&x2,&y,&cor);
        if(x1>x2){
         y1=x1;
         x1=x2;
         x2=y1;
        }
        for(j=x1;j<=x2;j++)
         table[y][j]=cor;
      break;
      case 'K':
        scanf("%d %d %d %d %c",&x1,&y1,&x2,&y2,&cor);
        for(i=y1;i<=y2;i++)
         for(j=x1;j<=x2;j++)
          table[i][j]=cor;
      break;
      case 'F':
        presente=1;
        scanf("%d %d %c",&x,&y,&cor);
        if(y<1 || y>linhas || x<1 || x>colunas)
         break;
        aux=table[y][x];
        vizinhos(y,x,aux);
        while(presente){
 	     presente=0;
	     for(i=1;i<=linhas;i++)
	      for(j=1;j<=colunas;j++)
            if(table[i][j]=='*'){
             vizinhos(i,j,aux);
             presente=1; }
        }
        for(i=1;i<=linhas;i++)
	      for(j=1;j<=colunas;j++)
           if(table[i][j]=='+')
             table[i][j]=cor;
      break;
      case 'S':
       scanf("%s",nome);
       printf("%s\n",nome);
       for(i=1;i<=linhas;i++){
          for(j=1;j<=colunas;j++)
             printf("%c",table[i][j]);
          printf("\n");
       }
      break;
      case 'X':    
      break;
     }
  }
}



