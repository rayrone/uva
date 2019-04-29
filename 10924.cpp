#include <stdio.h>
#include <ctype.h>

/* 10924 - Prime Words */

#define ONEPRIME true

bool isPrime(int x)
{
    int i;

    if(x == 1)
    {
        return ONEPRIME;
    }

    if(x == 2)
    {
        return true;
    }

    if(x % 2 == 0)
    {
        return false;
    }

    for(i = 3 ; i * i <= x ; i += 2)
    {
        if(x % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool isPrimeWord(char *word)
{
    int sumOfLetters = 0;

    for(int i = 0 ; word[i] != '\0' ; i++)
    {
        if(islower(word[i]))
        {
            sumOfLetters += word[i] - 96;
        }
        else
        {
            sumOfLetters += word[i] - 38;
        }
    }

    return isPrime(sumOfLetters);
}

int main()
{
    char word[21];

    while(scanf("%s", word) != EOF)
    {
        if(isPrimeWord(word))
        {
            printf("It is a prime word.\n");
        }
        else
        {
            printf("It is not a prime word.\n");
        }
    }

    return 0;
}
