/* 10267 - Graphical Editor */

#include <iostream>
#include <algorithm>

using namespace std;

char image[252][252];

void clear(short lin, short col)
{
    for (int i = 0; i <= lin + 1; i++)
        for (int j = 0; j <= col + 1; j++)
            image[i][j] = 'O';
}

void draw_vertical_segment(short x, short y1, short y2, char color)
{
    for (short i = y1; i <= y2; i++)
        image[i][x] = color;
}

void draw_horizontal_segment(short x1, short x2, short y, char color)
{
    for (short j = x1; j <= x2; j++)
        image[y][j] = color;
}

void draw_rectangle(short x1, short y1, short x2, short y2, char color)
{
    for (short i = y1; i <= y2; i++)
        for (short j = x1; j <= x2; j++)
            image[i][j] = color;
}

int find_others_pixels_of_region(int y, int x, char aux_color)
{
    if (aux_color == image[y][x - 1] && image[y][x - 1] != '+')
        image[y][x - 1] = '*';
    if (aux_color == image[y][x + 1] && image[y][x + 1] != '+')
        image[y][x + 1] = '*';
    if (aux_color == image[y - 1][x] && image[y - 1][x] != '+')
        image[y - 1][x] = '*';
    if (aux_color == image[y + 1][x] && image[y + 1][x] != '+')
        image[y + 1][x] = '*';

    image[y][x] = '+';

    return 0;
}

void draw_region(short lin, short col, short x, short y, char color)
{
    bool present = true;

    if (y < 1 || y > lin || x < 1 || x > col)
        return;

    char aux_color = image[y][x];

    find_others_pixels_of_region(y, x, aux_color);

    while (present)
    {
        present = false;

        for (short i = 1; i <= lin; i++)
        {
            for (short j = 1; j <= col; j++)
            {
                if (image[i][j] == '*')
                {
                    find_others_pixels_of_region(i, j, aux_color);
                    present = true;
                }
            }
        }
    }

    for (short i = 1; i <= lin; i++)
        for (short j = 1; j <= col; j++)
            if (image[i][j] == '+')
                image[i][j] = color;
}

void print_image(char *filename, short lin, short col)
{
    cout << filename << endl;

    for (short i = 1; i <= lin; i++)
    {
        for (short j = 1; j <= col; j++)
            cout << image[i][j];

        cout << endl;
    }
}

int main()
{
    char command, color, filename[12];
    short col, lin, x, y, x1, y1, x2, y2;

    while (cin >> command)
    {
        if (command == 'I')
        {
            cin >> col >> lin;
            clear(lin, col);
        }

        else if (command == 'C')
            clear(lin, col);

        else if (command == 'L')
        {
            cin >> x >> y >> color;
            image[y][x] = color;
        }

        else if (command == 'V')
        {
            cin >> x >> y1 >> y2 >> color;
            draw_vertical_segment(x, min(y1, y2), max(y1, y2), color);
        }

        else if (command == 'H')
        {
            cin >> x1 >> x2 >> y >> color;
            draw_horizontal_segment(min(x1, x2), max(x1, x2), y, color);
        }

        else if (command == 'K')
        {
            cin >> x1 >> y1 >> x2 >> y2 >> color;
            draw_rectangle(x1, y1, x2, y2, color);
        }

        else if (command == 'F')
        {
            cin >> x >> y >> color;
            draw_region(lin, col, x, y, color);
        }

        else if (command == 'S')
        {
            cin >> filename;
            print_image(filename, lin, col);
        }
        else if (command == 'X')
            break;
    }

    return 0;
}
