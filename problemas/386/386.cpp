/* 386 - Perfect Cubes */

#include <cmath>
#include <iostream>
#include <map>

using namespace std;

#define MAX_A 200

int main()
{
    /*map<int, int> cubes;

    for (int i = 2; i <= MAX_A; i++)
        cubes[i] = pow(i, 3);

    for (int a = 6; a <= MAX_A; a++)
    {
        int a3 = cubes[a];

        for (int b = 2; b < a; b++)
        {
            int b3 = cubes[b];

            for (int c = b + 1; c < a; c++)
            {
                int c3 = cubes[c];

                for (int d = c + 1; d < a; d++)
                {
                    if (a3 == b3 + c3 + cubes[d])
                        cout << "cout << \"Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\" << endl;" << endl;
                }
            }
        }
    }*/

    cout << "Cube = 6, Triple = (3,4,5)" << endl;
    cout << "Cube = 12, Triple = (6,8,10)" << endl;
    cout << "Cube = 18, Triple = (2,12,16)" << endl;
    cout << "Cube = 18, Triple = (9,12,15)" << endl;
    cout << "Cube = 19, Triple = (3,10,18)" << endl;
    cout << "Cube = 20, Triple = (7,14,17)" << endl;
    cout << "Cube = 24, Triple = (12,16,20)" << endl;
    cout << "Cube = 25, Triple = (4,17,22)" << endl;
    cout << "Cube = 27, Triple = (3,18,24)" << endl;
    cout << "Cube = 28, Triple = (18,19,21)" << endl;
    cout << "Cube = 29, Triple = (11,15,27)" << endl;
    cout << "Cube = 30, Triple = (15,20,25)" << endl;
    cout << "Cube = 36, Triple = (4,24,32)" << endl;
    cout << "Cube = 36, Triple = (18,24,30)" << endl;
    cout << "Cube = 38, Triple = (6,20,36)" << endl;
    cout << "Cube = 40, Triple = (14,28,34)" << endl;
    cout << "Cube = 41, Triple = (2,17,40)" << endl;
    cout << "Cube = 41, Triple = (6,32,33)" << endl;
    cout << "Cube = 42, Triple = (21,28,35)" << endl;
    cout << "Cube = 44, Triple = (16,23,41)" << endl;
    cout << "Cube = 45, Triple = (5,30,40)" << endl;
    cout << "Cube = 46, Triple = (3,36,37)" << endl;
    cout << "Cube = 46, Triple = (27,30,37)" << endl;
    cout << "Cube = 48, Triple = (24,32,40)" << endl;
    cout << "Cube = 50, Triple = (8,34,44)" << endl;
    cout << "Cube = 53, Triple = (29,34,44)" << endl;
    cout << "Cube = 54, Triple = (6,36,48)" << endl;
    cout << "Cube = 54, Triple = (12,19,53)" << endl;
    cout << "Cube = 54, Triple = (27,36,45)" << endl;
    cout << "Cube = 56, Triple = (36,38,42)" << endl;
    cout << "Cube = 57, Triple = (9,30,54)" << endl;
    cout << "Cube = 58, Triple = (15,42,49)" << endl;
    cout << "Cube = 58, Triple = (22,30,54)" << endl;
    cout << "Cube = 60, Triple = (21,42,51)" << endl;
    cout << "Cube = 60, Triple = (30,40,50)" << endl;
    cout << "Cube = 63, Triple = (7,42,56)" << endl;
    cout << "Cube = 66, Triple = (33,44,55)" << endl;
    cout << "Cube = 67, Triple = (22,51,54)" << endl;
    cout << "Cube = 69, Triple = (36,38,61)" << endl;
    cout << "Cube = 70, Triple = (7,54,57)" << endl;
    cout << "Cube = 71, Triple = (14,23,70)" << endl;
    cout << "Cube = 72, Triple = (8,48,64)" << endl;
    cout << "Cube = 72, Triple = (34,39,65)" << endl;
    cout << "Cube = 72, Triple = (36,48,60)" << endl;
    cout << "Cube = 75, Triple = (12,51,66)" << endl;
    cout << "Cube = 75, Triple = (38,43,66)" << endl;
    cout << "Cube = 76, Triple = (12,40,72)" << endl;
    cout << "Cube = 76, Triple = (31,33,72)" << endl;
    cout << "Cube = 78, Triple = (39,52,65)" << endl;
    cout << "Cube = 80, Triple = (28,56,68)" << endl;
    cout << "Cube = 81, Triple = (9,54,72)" << endl;
    cout << "Cube = 81, Triple = (25,48,74)" << endl;
    cout << "Cube = 82, Triple = (4,34,80)" << endl;
    cout << "Cube = 82, Triple = (12,64,66)" << endl;
    cout << "Cube = 82, Triple = (19,60,69)" << endl;
    cout << "Cube = 84, Triple = (28,53,75)" << endl;
    cout << "Cube = 84, Triple = (42,56,70)" << endl;
    cout << "Cube = 84, Triple = (54,57,63)" << endl;
    cout << "Cube = 85, Triple = (50,61,64)" << endl;
    cout << "Cube = 87, Triple = (20,54,79)" << endl;
    cout << "Cube = 87, Triple = (26,55,78)" << endl;
    cout << "Cube = 87, Triple = (33,45,81)" << endl;
    cout << "Cube = 87, Triple = (38,48,79)" << endl;
    cout << "Cube = 88, Triple = (21,43,84)" << endl;
    cout << "Cube = 88, Triple = (25,31,86)" << endl;
    cout << "Cube = 88, Triple = (32,46,82)" << endl;
    cout << "Cube = 89, Triple = (17,40,86)" << endl;
    cout << "Cube = 90, Triple = (10,60,80)" << endl;
    cout << "Cube = 90, Triple = (25,38,87)" << endl;
    cout << "Cube = 90, Triple = (45,60,75)" << endl;
    cout << "Cube = 90, Triple = (58,59,69)" << endl;
    cout << "Cube = 92, Triple = (6,72,74)" << endl;
    cout << "Cube = 92, Triple = (54,60,74)" << endl;
    cout << "Cube = 93, Triple = (32,54,85)" << endl;
    cout << "Cube = 95, Triple = (15,50,90)" << endl;
    cout << "Cube = 96, Triple = (19,53,90)" << endl;
    cout << "Cube = 96, Triple = (48,64,80)" << endl;
    cout << "Cube = 97, Triple = (45,69,79)" << endl;
    cout << "Cube = 99, Triple = (11,66,88)" << endl;
    cout << "Cube = 100, Triple = (16,68,88)" << endl;
    cout << "Cube = 100, Triple = (35,70,85)" << endl;
    cout << "Cube = 102, Triple = (51,68,85)" << endl;
    cout << "Cube = 103, Triple = (12,31,102)" << endl;
    cout << "Cube = 105, Triple = (33,70,92)" << endl;
    cout << "Cube = 106, Triple = (58,68,88)" << endl;
    cout << "Cube = 108, Triple = (12,72,96)" << endl;
    cout << "Cube = 108, Triple = (13,51,104)" << endl;
    cout << "Cube = 108, Triple = (15,82,89)" << endl;
    cout << "Cube = 108, Triple = (24,38,106)" << endl;
    cout << "Cube = 108, Triple = (54,72,90)" << endl;
    cout << "Cube = 110, Triple = (29,75,96)" << endl;
    cout << "Cube = 111, Triple = (16,47,108)" << endl;
    cout << "Cube = 112, Triple = (72,76,84)" << endl;
    cout << "Cube = 113, Triple = (50,74,97)" << endl;
    cout << "Cube = 114, Triple = (18,60,108)" << endl;
    cout << "Cube = 114, Triple = (57,76,95)" << endl;
    cout << "Cube = 115, Triple = (3,34,114)" << endl;
    cout << "Cube = 116, Triple = (23,86,97)" << endl;
    cout << "Cube = 116, Triple = (30,84,98)" << endl;
    cout << "Cube = 116, Triple = (44,60,108)" << endl;
    cout << "Cube = 117, Triple = (13,78,104)" << endl;
    cout << "Cube = 120, Triple = (9,55,116)" << endl;
    cout << "Cube = 120, Triple = (42,84,102)" << endl;
    cout << "Cube = 120, Triple = (60,80,100)" << endl;
    cout << "Cube = 121, Triple = (49,84,102)" << endl;
    cout << "Cube = 122, Triple = (19,92,101)" << endl;
    cout << "Cube = 123, Triple = (6,51,120)" << endl;
    cout << "Cube = 123, Triple = (18,96,99)" << endl;
    cout << "Cube = 123, Triple = (44,51,118)" << endl;
    cout << "Cube = 125, Triple = (20,85,110)" << endl;
    cout << "Cube = 126, Triple = (14,84,112)" << endl;
    cout << "Cube = 126, Triple = (23,94,105)" << endl;
    cout << "Cube = 126, Triple = (63,84,105)" << endl;
    cout << "Cube = 127, Triple = (13,65,121)" << endl;
    cout << "Cube = 129, Triple = (38,57,124)" << endl;
    cout << "Cube = 132, Triple = (5,76,123)" << endl;
    cout << "Cube = 132, Triple = (48,69,123)" << endl;
    cout << "Cube = 132, Triple = (66,88,110)" << endl;
    cout << "Cube = 133, Triple = (21,70,126)" << endl;
    cout << "Cube = 134, Triple = (44,102,108)" << endl;
    cout << "Cube = 134, Triple = (86,95,97)" << endl;
    cout << "Cube = 135, Triple = (15,90,120)" << endl;
    cout << "Cube = 137, Triple = (44,73,128)" << endl;
    cout << "Cube = 138, Triple = (9,108,111)" << endl;
    cout << "Cube = 138, Triple = (69,92,115)" << endl;
    cout << "Cube = 138, Triple = (72,76,122)" << endl;
    cout << "Cube = 138, Triple = (81,90,111)" << endl;
    cout << "Cube = 139, Triple = (94,96,99)" << endl;
    cout << "Cube = 140, Triple = (14,108,114)" << endl;
    cout << "Cube = 140, Triple = (49,98,119)" << endl;
    cout << "Cube = 140, Triple = (90,95,105)" << endl;
    cout << "Cube = 141, Triple = (72,85,122)" << endl;
    cout << "Cube = 142, Triple = (28,46,140)" << endl;
    cout << "Cube = 142, Triple = (31,64,137)" << endl;
    cout << "Cube = 144, Triple = (16,96,128)" << endl;
    cout << "Cube = 144, Triple = (68,78,130)" << endl;
    cout << "Cube = 144, Triple = (72,96,120)" << endl;
    cout << "Cube = 145, Triple = (12,81,136)" << endl;
    cout << "Cube = 145, Triple = (55,75,135)" << endl;
    cout << "Cube = 147, Triple = (22,75,140)" << endl;
    cout << "Cube = 150, Triple = (24,102,132)" << endl;
    cout << "Cube = 150, Triple = (71,73,138)" << endl;
    cout << "Cube = 150, Triple = (75,100,125)" << endl;
    cout << "Cube = 150, Triple = (76,86,132)" << endl;
    cout << "Cube = 151, Triple = (46,47,148)" << endl;
    cout << "Cube = 152, Triple = (24,80,144)" << endl;
    cout << "Cube = 152, Triple = (62,66,144)" << endl;
    cout << "Cube = 153, Triple = (17,102,136)" << endl;
    cout << "Cube = 156, Triple = (65,87,142)" << endl;
    cout << "Cube = 156, Triple = (78,104,130)" << endl;
    cout << "Cube = 159, Triple = (3,121,131)" << endl;
    cout << "Cube = 159, Triple = (87,102,132)" << endl;
    cout << "Cube = 160, Triple = (56,112,136)" << endl;
    cout << "Cube = 160, Triple = (69,123,124)" << endl;
    cout << "Cube = 162, Triple = (18,108,144)" << endl;
    cout << "Cube = 162, Triple = (36,57,159)" << endl;
    cout << "Cube = 162, Triple = (50,96,148)" << endl;
    cout << "Cube = 162, Triple = (59,93,148)" << endl;
    cout << "Cube = 162, Triple = (81,108,135)" << endl;
    cout << "Cube = 164, Triple = (8,68,160)" << endl;
    cout << "Cube = 164, Triple = (24,128,132)" << endl;
    cout << "Cube = 164, Triple = (38,120,138)" << endl;
    cout << "Cube = 164, Triple = (69,99,146)" << endl;
    cout << "Cube = 167, Triple = (12,86,159)" << endl;
    cout << "Cube = 168, Triple = (56,106,150)" << endl;
    cout << "Cube = 168, Triple = (84,112,140)" << endl;
    cout << "Cube = 168, Triple = (108,114,126)" << endl;
    cout << "Cube = 170, Triple = (96,107,141)" << endl;
    cout << "Cube = 170, Triple = (100,122,128)" << endl;
    cout << "Cube = 171, Triple = (19,114,152)" << endl;
    cout << "Cube = 171, Triple = (27,90,162)" << endl;
    cout << "Cube = 171, Triple = (54,80,163)" << endl;
    cout << "Cube = 171, Triple = (107,108,136)" << endl;
    cout << "Cube = 174, Triple = (40,108,158)" << endl;
    cout << "Cube = 174, Triple = (45,126,147)" << endl;
    cout << "Cube = 174, Triple = (47,97,162)" << endl;
    cout << "Cube = 174, Triple = (52,110,156)" << endl;
    cout << "Cube = 174, Triple = (66,90,162)" << endl;
    cout << "Cube = 174, Triple = (76,96,158)" << endl;
    cout << "Cube = 174, Triple = (87,116,145)" << endl;
    cout << "Cube = 175, Triple = (28,119,154)" << endl;
    cout << "Cube = 176, Triple = (25,92,167)" << endl;
    cout << "Cube = 176, Triple = (42,86,168)" << endl;
    cout << "Cube = 176, Triple = (50,62,172)" << endl;
    cout << "Cube = 176, Triple = (64,92,164)" << endl;
    cout << "Cube = 177, Triple = (48,137,142)" << endl;
    cout << "Cube = 178, Triple = (34,80,172)" << endl;
    cout << "Cube = 178, Triple = (48,133,147)" << endl;
    cout << "Cube = 179, Triple = (17,57,177)" << endl;
    cout << "Cube = 180, Triple = (20,120,160)" << endl;
    cout << "Cube = 180, Triple = (50,76,174)" << endl;
    cout << "Cube = 180, Triple = (63,126,153)" << endl;
    cout << "Cube = 180, Triple = (90,120,150)" << endl;
    cout << "Cube = 180, Triple = (116,118,138)" << endl;
    cout << "Cube = 181, Triple = (108,109,150)" << endl;
    cout << "Cube = 184, Triple = (12,144,148)" << endl;
    cout << "Cube = 184, Triple = (108,120,148)" << endl;
    cout << "Cube = 185, Triple = (57,68,180)" << endl;
    cout << "Cube = 185, Triple = (68,113,166)" << endl;
    cout << "Cube = 186, Triple = (18,121,167)" << endl;
    cout << "Cube = 186, Triple = (64,108,170)" << endl;
    cout << "Cube = 186, Triple = (93,124,155)" << endl;
    cout << "Cube = 187, Triple = (58,131,160)" << endl;
    cout << "Cube = 188, Triple = (115,122,149)" << endl;
    cout << "Cube = 189, Triple = (21,46,188)" << endl;
    cout << "Cube = 189, Triple = (21,126,168)" << endl;
    cout << "Cube = 190, Triple = (30,100,180)" << endl;
    cout << "Cube = 190, Triple = (56,133,163)" << endl;
    cout << "Cube = 191, Triple = (39,146,156)" << endl;
    cout << "Cube = 192, Triple = (34,123,173)" << endl;
    cout << "Cube = 192, Triple = (38,106,180)" << endl;
    cout << "Cube = 192, Triple = (96,128,160)" << endl;
    cout << "Cube = 193, Triple = (25,68,190)" << endl;
    cout << "Cube = 194, Triple = (90,138,158)" << endl;
    cout << "Cube = 196, Triple = (126,133,147)" << endl;
    cout << "Cube = 197, Triple = (53,58,194)" << endl;
    cout << "Cube = 198, Triple = (22,132,176)" << endl;
    cout << "Cube = 198, Triple = (27,46,197)" << endl;
    cout << "Cube = 198, Triple = (73,135,170)" << endl;
    cout << "Cube = 198, Triple = (99,132,165)" << endl;
    cout << "Cube = 199, Triple = (6,127,180)" << endl;
    cout << "Cube = 200, Triple = (32,136,176)" << endl;
    cout << "Cube = 200, Triple = (70,140,170)" << endl;

    return 0;
}