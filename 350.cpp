#include<stdio.h>

/* Pseudo-Random Numbers - 350 */

int main(){

int i, c=0 , l, m, z, seed, ciclo;

    while(1) {
        scanf("%d %d %d %d",&z, &i, &m, &l);
        if(z == 0 && i == 0 && m == 0 && l == 0)
            break;
        ciclo = 0;
        c++;
        seed = l = (z * l + i) % m;
        do {
           ciclo++;
           l = (z * l + i) % m;
           if(l == seed)
              break;  
        } while(1);
        printf("Case %d: %d\n",c,ciclo);  
    }
    return 0;
}
