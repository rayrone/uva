/* 10062 - Tell me the frequencies! */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define MAX_LINE_LENGTH 1001 // including '\0'
#define NUM_OF_CHAR 128

struct freq_ascii_char
{
    short value;
    short freq = 0;
};

int cmp(const void *a, const void *b)
{
    freq_ascii_char *a1 = (freq_ascii_char *)a;
    freq_ascii_char *b1 = (freq_ascii_char *)b;

    if (a1->freq == b1->freq)
        return b1->value - a1->value;

    return a1->freq - b1->freq;
}

int main()
{
    char line[MAX_LINE_LENGTH];
    int len, index;
    bool firstLine = true;

    while (gets(line))
    {
        freq_ascii_char f[NUM_OF_CHAR];
        len = strlen(line);

        for (int i = 0; i < len; i++)
        {
            index = line[i] - 32;
            f[index].value = line[i];
            f[index].freq++;
        }

        qsort((void *)f, NUM_OF_CHAR, sizeof(f[0]), cmp);

        if (!firstLine)
            putchar('\n');
        else
            firstLine = false;

        for (int i = 0; i < NUM_OF_CHAR; i++)
            if (f[i].freq > 0)
                printf("%d %d\n", f[i].value, f[i].freq);
    }

    return 0;
}
