#include<stdio.h>

/* Beat the Spread! - 10812 */

int main(){

    int i, n, s, d, x, y;

    scanf("%d",&n);
    for(i = 1 ; i <= n ; i++) {
       scanf("%d %d",&s, &d);
       x = (s + d ) / 2; 
       y = s - x;
       if(s < d || (s + d) % 2 != 0)
          printf("impossible\n");
       else 
          printf("%d %d\n",x ,y);
    }
    return 0;
}
