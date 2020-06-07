#include<stdio.h>
#include<stdlib.h>

/* Maze Exploration - 784 */

void paint(char maze[][81],int x,int y){
     
     
     maze[x][y]='#';
     
     if(maze[x][y-1] == ' ')
      paint(maze,x,y-1);
      
     if(maze[x][y+1] == ' ')
      paint(maze,x,y+1);
           
     if(maze[x-1][y] == ' ')
      paint(maze,x-1,y);
      
     if(maze[x+1][y] == ' ')
      paint(maze,x+1,y);
}

main(){

int n,i,j,lin;
char maze[30][81];

    n = atoi(gets(maze[0]));
    
    for(;n>0;n--){
     
      lin=0;
         
      while(1){
        
        gets(maze[lin]);
        if(maze[lin][0] == '_')
         break;
        lin++;
 
      }
      
     for(i=0;i<lin;i++)
      for(j=0;maze[i][j]!='\0';j++)
       if(maze[i][j]=='*')
        paint(maze,i,j);
     
     for(i=0;i<=lin;i++)
      puts(maze[i]);
          
   } 
}
