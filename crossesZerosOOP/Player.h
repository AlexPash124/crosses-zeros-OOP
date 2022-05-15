#pragma once
#include <iostream>
#include <conio.h>
using std::cout;
using std::endl;

class Player
{
private:
	int x; 
	int y;
	char ch;
public:
	Player() {x = 1; y = 1; }

	int getX() { return this->x; }
	int getY() { return this->y; }
	char getCh() { return this->ch; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setCh(char ch) { this->ch = ch; }
};

class Pole {
private:
	int n;
	int m;
	char** matrix;
	int step;
public:
	Pole(void);
	void printPole(Player& player); 
	void printPole(int,int,char);
	bool getWinner();
};

