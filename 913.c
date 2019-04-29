#include<stdio.h>

/* Joana and the Odd Numbers - 913 */

main(){

long long n,m;

    while(scanf("%lld",&n)!=EOF){
        m = (1+n)/2;
        printf("%lld\n",6*m*m-9);
    }  
}
