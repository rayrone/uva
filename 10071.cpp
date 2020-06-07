#include<stdio.h>

/* Back to High School Physics - 10071 */

int main(){

    int v, t;

    while(scanf("%d %d",&v,&t)!= EOF) {
        printf("%d\n",2 * (v * t));
    }
    return 0;
}
