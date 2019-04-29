#include<stdio.h>

/* The Decoder - 458 */

int main(){

    char str;

    while((scanf("%c",&str)!=EOF)) {
       if(str == ' ')
          printf(" ");
       else    
          if(str == '\n')
             printf("\n");
          else {
             str -= 7;
             printf("%c",str);
          }
    }
    return 0;
}
