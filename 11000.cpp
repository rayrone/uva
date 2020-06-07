#include<stdio.h>

/* Bee - 11000 */

int main(){

    int i, n;
    unsigned long aux, machos, total;

    scanf("%d",&n);
    while(n >= 0) {
       aux=machos=total=0;
       for(i=0;i<=n;i++) {
          machos=total;
          total=machos+aux+1;
          aux=machos;
       }
       printf("%u %u\n",machos,total);
       scanf("%d",&n);
    }
    return 0;
}
