#include<iostream>
#include<Windows.h>
#include<math.h>
#include<string>
#include<conio.h>
#include "Header.h"

using namespace std;

int main()
{
    const int N = 10;
	int action = 0;
	int y = 1, x = 1;
   
    char map[10][10] = {   {'*','*','*','*','*','*','*','*','*','*'},
                            {'*','$',' ','#','*',' ',' ',' ',' ','*'},
                            {'*',' ','*',' ','*',' ','*',' ',' ','*'},
                            {'*',' ','*',' ','*',' ','*','#',' ','*'},
                            {'*',' ',' ',' ','*',' ','*',' ',' ','*'},
                            {'*',' ','*',' ','*',' ','*',' ','*','*'},
                            {'*',' ','*',' ',' ',' ','*',' ',' ','*'},
                            {'*',' ','*',' ','#','*',' ','*',' ','*'},
                            {'*',' ',' ','#',' ','*',' ',' ','F','*'},
                            {'*','*','*','*','*','*','*','*','*','*'},
    };  
	
	showMap(map);

	do {

		switch (_getch()) {
		case 72: // vgoru
			system("cls");
			if (map[y - 1][x] == '*' || map[y - 1][x] == '#') {
				if (map[y - 1][x] == '#') {

					trap(map, action, y, x);

					map[2][3] = ' ';
					map[4][7] = ' ';
				}
			}
			else {
				map[y - 1][x] = map[y][x];
				map[y][x] = ' ';
				y--;				
			}
			showMap(map);
			break;
		case 80: //vnyz
			system("cls");
			if (map[y + 1][x] == '*' || map[y + 1][x] == '#') {
				if (map[y + 1][x] == '#') {

					trap(map, action, y, x);
					
					map[7][3] = ' ';
					map[6][4] = ' ';
					map[2][7] = ' ';
				}
			}
			else {
				if (map[y+1][x] == 'F') {
					action = 2;
					cout << "You Win!" << endl;
					Sleep(2000);
				}
				map[y + 1][x] = map[y][x];
				map[y][x] = ' ';
				y++;				
			}

			showMap(map);
			break;
		case 75: //vlivo
			system("cls");
			if (map[y][x - 1] == '*' || map[y][x - 1] == '#') {
				if (map[y][x - 1] == '#') {
					
					trap(map, action, y, x);

					map[3][8] = ' ';
				}
			}
			else {
				map[y][x - 1] = map[y][x];
				map[y][x] = ' ';
				x--;				
			}

			showMap(map);
			break;
		case 77: //vpravo
			system("cls");
			if (map[y][x + 1] == '*' || map[y][x + 1] == '#') {
				if (map[y][x+1] == '#') {

					trap(map, action, y, x);
					
					map[1][2] = ' ';
					map[8][2] = ' ';
					map[7][3] = ' ';
				}
			}
			else {				
				map[y][x + 1] = map[y][x];
				map[y][x] = ' ';
				x++;				
			}

			showMap(map);

			break;
		}
	} while (action != 2);

    system("pause");
    return 0;
}

