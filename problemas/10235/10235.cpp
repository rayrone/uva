/* 10235 - Simply Emirp */

#include <stdio.h>
#include <math.h>

int inverte(int n)
{ 
    int aux = n, w = 0, y;   
 
    while(aux != 0)
    {
        w = w * 10 + aux % 10;  
        aux /= 10;            
    }

    return w;
}

int ehPrimo(int n)
{
    int i;

    if((n % 2 == 0 && n != 2) || (n % 3 == 0 && n != 3))
        return 0;
 
    for(i = 3 ; i * i <= n ; i += 2)
        if(n % i == 0)
            return 0;

    return 1;
}  

int main()
{

    int i, j, k = 0, n, m, prime, emirp;

    while(scanf("%d", &n) != EOF)
    {
        emirp = 0;
        prime = ehPrimo(n);
  
        if(n > 9 && prime == 1)
        {
            m = inverte(n);

            if(n != m)
            {
                if(ehPrimo(m))
                  emirp = 1;
                else
                  emirp = 0;
            }
        }
  
      if(emirp)
          prime = 0;  
    
      if(!prime && !emirp)
          printf("%d is not prime.\n", n);
      else if(prime)
          printf("%d is prime.\n", n);
      else if(emirp)
          printf("%d is emirp.\n", n);
    }

    return 0;
}
