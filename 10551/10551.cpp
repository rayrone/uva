/* 10551 - Basic Remains */

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

string convertFrom10Base(long num , int base)
{
    int currentDigit;
    string numBase;

    do
    {
        currentDigit = num % base;
        numBase = static_cast<char>(currentDigit + '0') + numBase;
        num /= base;
    } while(num > 0);

    return numBase;
}

unsigned int convertTo10Base(char* num, int base)
{
	int len = strlen(num), num10 = 0, pow = 1;

	for(int i = len - 1 ; i >= 0 ; i--)
	{
		num10 += pow * (num[i] - '0');
		pow *= base;
	}

	return num10;
}

unsigned int exp_modular(int num, int potencia, int mod)
{
	if(potencia == 1)
		return num % mod;
	else if(potencia == 0)
		return 1;

  	return ((num % mod) * exp_modular(num, potencia - 1, mod)) % mod;
}


int main()
{
	char p[1001], m[10];
  	unsigned int b;

	while(cin >> b)
	{
		if(b == 0)
			break;

		cin >> p >> m;

		int mBase10 = convertTo10Base(m, b);

		// Convertendo p para base10 e calculando o resto ao mesmo tempo
		int modPow, pBase10, pow = strlen(p) - 1, temp = 0, remainder = 0;

		for(int i = 0; p[i] != '\0' ; i++)
		{
			pBase10 = p[i] - '0';
			modPow = exp_modular(b, pow, mBase10);
			temp = (pBase10 * modPow) % mBase10;
			remainder = (remainder + temp) % mBase10;
			pow--;
		}

    	cout << convertFrom10Base(remainder, b) << endl;
	}

	return 0;
}
