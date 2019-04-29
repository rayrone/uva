#include <iostream>

/* Base Number Conversion */

using namespace std;

/**
 * @author Rayrone
 * @date 06/03/19
 * @brief calculateDecimalValue obtém o valor decimal de um dígito. '0' a '9' possuem o mesmo valor da sua representação decimal.
 * As letras maiúsculas de 'A' a 'Z' possuem os valores de 10 a 35.
 * @param digit o dígito cujo valor decimal deseja-se obter.
 * @return o valor decimal do dígito informado.
 */
int calculateDecimalValue(char digit)
{
    if(digit >= '0' && digit <= '9')
        return digit - '0';
    else
        return digit - 'A' + 10;
}

/**
 * @author Rayrone
 * @date 06/03/19
 * @brief convertTo10Base converte um número para a base decimal.
 * @param num o número a ser convertido.
 * @param base a base na qual o número se encontra.
 * @return o número na base decimal.
 */
long convertTo10Base(string num, int base)
{
    int currDigit;
    long num10 = 0, pow = 1;

    for(string::reverse_iterator rit = num.rbegin() ; rit != num.rend() ; rit++)
    {
        currDigit = calculateDecimalValue(*rit);
        num10 = num10 + currDigit * pow;
        pow *= base;
    }

    return num10;
}

/**
 * @author Rayrone
 * @date 06/03/19
 * @brief toCharFromDecimalValue convert um valor decimal para a sua representação em caractere.
 * '0' a '9' possuem o mesmo valor da sua representação decimal. As letras maiúsculas de 'A' a 'Z' possuem os valores de 10 a 35.
 * @param value o valor a ser convertido para a sua representação em caractere.
 * @return a representação em caractere do valor decimal.
 */
char toCharFromDecimalValue(int value)
{
    if(value >= 0 && value <= 9)
        return static_cast<char>(value + '0');
    else
        return static_cast<char>(value + 'A' - 10);
}

/**
 * @author Rayrone
 * @date 06/03/19
 * @brief convertFrom10Base converte um número na base decimal para uma base qualquer.
 * @param num o número a ser convertido.
 * @param base a base para a qual o número será convertido.
 * @return o número convertido na base informada.
 */
string convertFrom10Base(long num , int base)
{
    int currentDigit;
    string numBase;

    do
    {
        currentDigit = num % base;
        numBase = toCharFromDecimalValue(currentDigit) + numBase;
        num /= base;
    }while(num > 0);

    return numBase;
}

/**
 * @author Rayrone
 * @date 06/03/19
 * @brief findSmallestBase encontra a menor base que pode ser usada para representar um número.
 * @param num o número cuja base queremos encontrar.
 * @return a menor base que pode ser usada para representar o número.
 */
int findSmallestBase(string num)
{
    int digitValue, smallestBase = 1;

    for(string::reverse_iterator rit = num.rbegin() ; rit != num.rend() ; rit++)
    {
        digitValue = calculateDecimalValue(*rit);
        smallestBase = max(digitValue, smallestBase);
    }

    return smallestBase + 1;
}

int main()
{
    return 0;
}
