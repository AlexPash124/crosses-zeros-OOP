#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Player.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
		
	Pole pole;
	Player player;
	//pole.printPole(player);
	
	int x = 1; int y = 1, i = 0; 
	char ch = 'X';
	while (true) {
		char key = _getch();

		if (key == 'w') x--;  
		if (key == 's') x++;
		if (key == 'a') y--;
		if (key == 'd') y++;
		if (x == 0 or x == 5 - 1 or y == 0 or y == 5 - 1) {//умова,за якої при виході за межі поля, змія повертається 
			x = 2;
			y = 2;
		}
		

		if (key == 'c' && i==0) {
			ch = 'X';
			player.setX(x);
			player.setY(y);
			player.setCh(ch);
			system("cls");
			
			pole.printPole(player);
			i = 1;
		}
		else if (key == 'c' && i == 1) {
			ch = '0';
			player.setX(x);
			player.setY(y);
			player.setCh(ch);
			system("cls");
			pole.printPole(player);
			i = 0;
		}
		else {
			system("cls");
			pole.printPole(x, y, '*');
		}
		
	}
	
}
