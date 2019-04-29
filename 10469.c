#include<stdio.h>

/* To Carry or not to Carry - 10469 */

int main() {
       
    unsigned long a, b;

    while(scanf("%lu %lu",&a,&b) != EOF) {
       printf("%lu\n",a ^ b);
    }
    return 0;
}
