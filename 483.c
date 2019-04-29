#include<stdio.h>

/* Word Scramble - 483 */

int main(){

    int i, size = 0;
    char letter, word[10001];

    while(scanf("%c",&letter)!= EOF) {
        if(letter == ' ' || letter == '\n') {
           for(i = size - 1 ; i >= 0 ; i--)
              printf("%c",word[i]);
           printf("%c",letter);
           size = 0;
        } else {
           word[size] = letter;
           size++;
        }
    }
    for(i = size - 1 ; i >= 0 ; i--)
       printf("%c",word[i]);
    return 0;   
}
