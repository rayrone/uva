#include<stdio.h>
#include<math.h>

/* Searching for Nessy - 11044 */

main(){

float c,n,m;

    scanf("%f",&c);
    for(;c>0;c--){
       
       scanf("%f %f",&n,&m);
       printf("%.0f\n",floor(n/3)*floor(m/3));
    }

}
