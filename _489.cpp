#include<stdio.h>
#include<string.h>

/* Hangman Judge - 489 */

main(){

int i,j,ts,tg,game,cont,flag,strike;
char guesses[2001],solution[1001];

 while(1)
 {
  cont=0;
  strike=0;
  scanf("%d",&game);
  if(game==-1)
   break;
  scanf("%s",solution);
  scanf("%s",guesses);
  ts=strlen(solution);
  tg=strlen(guesses);
  for(i=0;i<tg;i++)
  {
   if(strike==7)
    break;
   flag=0;
   for(j=0;j<ts;j++)
    if(guesses[i]==solution[j])
    {
     flag=1;
     cont++;
    } 
   if(!flag)
    strike++;
  }
  printf("Round %d\n",game);
  if(cont>=ts && strike!=7)
   printf("You win.\n");
  else
   if(strike==7)
    printf("You lose.\n");
   else
    printf("You chickened out.\n");  
 }
}
