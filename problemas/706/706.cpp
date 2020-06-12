/* 706 - LC-Display */

#include <iostream>
#include <vector>

using namespace std;

#define MAX_LIN 23
#define MAX_COL 12

struct digit
{
    short n_lin = 0, n_col = 0;
    short last_lin = 0, last_col = 0;
    short mid_lin = 0;
    char mat[MAX_LIN][MAX_COL];
};

void draw_vertical_line_1(short size, digit *d, bool firstColumn)
{
    short col = firstColumn ? 0 : d->last_col;

    for (int j = 1; j <= size; j++)
        d->mat[j][col] = '|';
}

void draw_vertical_line_2(short size, digit *d, bool firstColumn)
{
    short col = firstColumn ? 0 : d->last_col;

    for (int j = 1; j <= size; j++)
        d->mat[d->mid_lin + j][col] = '|';
}

void draw_aux_lines_2_3_5_6_8_9(short size, digit *d)
{
    for (int i = 0; i < d->n_lin; i += d->mid_lin)
        for (int j = 1; j <= size; j++)
            d->mat[i][j] = '-';
}

void draw_digit_1(short size, digit *d1)
{
    draw_vertical_line_1(size, d1, false);
    draw_vertical_line_2(size, d1, false);
}

void draw_digit_2(short size, digit *d2)
{
    draw_aux_lines_2_3_5_6_8_9(size, d2);
    draw_vertical_line_1(size, d2, false);
    draw_vertical_line_2(size, d2, true);
}

void draw_digit_3(short size, digit *d3)
{
    draw_aux_lines_2_3_5_6_8_9(size, d3);
    draw_vertical_line_1(size, d3, false);
    draw_vertical_line_2(size, d3, false);
}

void draw_digit_4(short size, digit *d4)
{
    for (int j = 1; j <= size; j++)
        d4->mat[d4->mid_lin][j] = '-';

    draw_vertical_line_1(size, d4, true);
    draw_vertical_line_1(size, d4, false);
    draw_vertical_line_2(size, d4, false);
}

void draw_digit_5(short size, digit *d5)
{
    draw_aux_lines_2_3_5_6_8_9(size, d5);
    draw_vertical_line_1(size, d5, true);
    draw_vertical_line_2(size, d5, false);
}

void draw_digit_6(short size, digit *d6)
{
    draw_aux_lines_2_3_5_6_8_9(size, d6);
    draw_vertical_line_1(size, d6, true);
    draw_vertical_line_2(size, d6, true);
    draw_vertical_line_2(size, d6, false);
}

void draw_digit_7(short size, digit *d7)
{
    for (int j = 1; j <= size; j++)
        d7->mat[0][j] = '-';

    draw_vertical_line_1(size, d7, false);
    draw_vertical_line_2(size, d7, false);
}

void draw_digit_8(short size, digit *d8)
{
    draw_aux_lines_2_3_5_6_8_9(size, d8);
    draw_vertical_line_1(size, d8, true);
    draw_vertical_line_1(size, d8, false);
    draw_vertical_line_2(size, d8, true);
    draw_vertical_line_2(size, d8, false);
}

void draw_digit_9(short size, digit *d9)
{
    draw_aux_lines_2_3_5_6_8_9(size, d9);
    draw_vertical_line_1(size, d9, true);
    draw_vertical_line_1(size, d9, false);
    draw_vertical_line_2(size, d9, false);
}

void draw_digit_0(short size, digit *d0)
{
    for (int j = 1; j <= size; j++)
    {
        d0->mat[0][j] = '-';
        d0->mat[d0->last_lin][j] = '-';
    }

    draw_vertical_line_1(size, d0, true);
    draw_vertical_line_1(size, d0, false);
    draw_vertical_line_2(size, d0, true);
    draw_vertical_line_2(size, d0, false);
}

void draw_digit(short s, digit *d, int n_digit)
{
    if (n_digit == 0)
        draw_digit_0(s, d);
    else if (n_digit == 1)
        draw_digit_1(s, d);
    else if (n_digit == 2)
        draw_digit_2(s, d);
    else if (n_digit == 3)
        draw_digit_3(s, d);
    else if (n_digit == 4)
        draw_digit_4(s, d);
    else if (n_digit == 5)
        draw_digit_5(s, d);
    else if (n_digit == 6)
        draw_digit_6(s, d);
    else if (n_digit == 7)
        draw_digit_7(s, d);
    else if (n_digit == 8)
        draw_digit_8(s, d);
    else
        draw_digit_9(s, d);
}

void init_digit(digit *d, short s)
{
    d->n_lin = 2 * s + 3;
    d->last_lin = d->n_lin - 1;
    d->mid_lin = d->n_lin / 2;
    d->n_col = s + 2;
    d->last_col = d->n_col - 1;

    for (int i = 0; i < MAX_LIN; i++)
        for (int j = 0; j < MAX_COL; j++)
            d->mat[i][j] = ' ';
}

void print_digits(vector<digit> digits)
{
    int lin = digits[0].last_lin;
    int col = digits[0].last_col;

    for (int i = 0; i <= lin; i++)
    {
        for (int k = digits.size() - 1; k >= 0; k--)
        {
            for (int j = 0; j <= col; j++)
                cout << digits[k].mat[i][j];

            if (k > 0)
                cout << " ";
        }

        cout << endl;
    }

    cout << endl;
}

int main()
{
    int s, n, n_digit;

    while (cin >> s >> n)
    {
        if (s == 0 && n == 0)
            break;

        vector<digit> digits;

        do
        {
            n_digit = n % 10;
            n /= 10;

            digit d;

            init_digit(&d, s);
            draw_digit(s, &d, n_digit);

            digits.push_back(d);
        } while (n != 0);

        print_digits(digits);
    }

    return 0;
}
