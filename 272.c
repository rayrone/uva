#include<stdio.h>

/* TeX Quotes - 272 */

int main(){

    int flag=1;
    char a;

    while(scanf("%c",&a)!=EOF)
      if(a=='"')
        if(flag) {
          printf("``");
          flag=0;
        }else {
          printf("''");
          flag=1;
      }else
        printf("%c",a);

    return 0;
}
