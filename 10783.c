#include<stdio.h>

/* Odd Sum - 10783 */

int main(){

    int i, j, a, b, c, sum, cont = 1;

    scanf("%d", &c);
    for(i = 1 ; i <= c ; i++) {
      sum = 0;
      scanf("%d %d",&a, &b);
      for(j = a ; j <= b ; j++)
         if(j % 2 != 0)
            sum+=j; 

      printf("Case %d: %d\n",cont++, sum);
    }
    return 0;
}
