#include "Header.h"
#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
using namespace std;


void showMap(char arr[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {

			cout <<" "<< arr[i][j];

		}
		cout << endl;

	}
}

void trap(char arr[N][N], int &action, int &y,int &x)
{
	system("cls");
	cout << "Game Over!" << endl;
	cout << "1.Restart game" << endl;
	cout << "2.Exit game" << endl;
	cin >> action;
	if (action == 1) {
		arr[1][1] = '$'; 
		y = 1;
		x = 1;
	}
}
