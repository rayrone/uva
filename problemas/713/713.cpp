/* 713 - Adding Reversed Numbers */

#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAXDIGITS 201 /* maximum length bignum */

typedef struct
{
    char digits[MAXDIGITS + 1]; /* represent the number */
    int lastdigit;              /* index of high-order digit */
} bignum;

void reverse(bignum *n)
{
    char tmp;
    int len = n->lastdigit + 1;

    for (int i = 0; i < len / 2; i++)
    {
        tmp = n->digits[i];
        n->digits[i] = n->digits[len - i - 1];
        n->digits[len - i - 1] = tmp;
    }
}

void print_bignum(bignum *n)
{
    for (int i = n->lastdigit; i >= 0; i--)
        printf("%c", '0' + n->digits[i]);

    printf("\n");
}

void string_to_bignum(char s[], bignum *n)
{
    for (int i = 0; i < MAXDIGITS; i++)
        n->digits[i] = (char)0;

    n->lastdigit = strlen(s) - 1;

    for (int i = 0; i <= n->lastdigit; i++)
        n->digits[i] = s[i] - '0';

    reverse(n);
}

void initialize_bignum(bignum *n)
{
    char zero[2] = "0";
    string_to_bignum(zero, n);
}

void zero_justify(bignum *n)
{
    while ((n->lastdigit > 0) && (n->digits[n->lastdigit] == 0))
        n->lastdigit--;
}

void add_bignum(bignum *a, bignum *b, bignum *c)
{
    initialize_bignum(c);

    c->lastdigit = max(a->lastdigit, b->lastdigit) + 1;
    int carry = 0; /* carry digit */

    for (int i = 0; i <= (c->lastdigit); i++)
    {
        c->digits[i] = (char)(carry + a->digits[i] + b->digits[i]) % 10;
        carry = (carry + a->digits[i] + b->digits[i]) / 10;
    }

    zero_justify(c);
}

int main()
{
    int n;
    char a[MAXDIGITS + 1], b[MAXDIGITS + 1];
    bignum n1, n2, n3;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%s %s", a, b);

        string_to_bignum(a, &n1);
        reverse(&n1);
        zero_justify(&n1);

        string_to_bignum(b, &n2);
        reverse(&n2);
        zero_justify(&n2);

        add_bignum(&n1, &n2, &n3);

        reverse(&n3);
        zero_justify(&n3);
        print_bignum(&n3);
    }

    return 0;
}
