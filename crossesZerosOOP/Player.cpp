#include "Player.h"

Pole::Pole() {
	this->n = 4;
	this->m = 4;
	this->matrix = nullptr;
	this->matrix = new char* [n];
	this->step = 0;

	for (int i = 0; i < n; i++)
	{
		this->matrix[i] = new char[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			this->matrix[i][j] = '-';
		}
	}

}




void Pole::printPole(Player &player) {
	++step;
	char arr[4]{ '-','A', 'B', 'C'};
	int x = player.getX();
	int y = player.getY();
	char ch = player.getCh();

	matrix[x][y] = ch;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			this->matrix[i][0] = arr[i];
			this->matrix[0][j] = arr[j];
			cout <<this->matrix[i][j] << "\t";
		}
		cout << endl;
	}
}



void Pole::printPole(int x, int y, char ch)
{
	if (getWinner()==true) {
		cout << "Game over" << endl;
	}
	else {

		char arr[4]{ '-','A', 'B', 'C' };
		if (matrix[x][y] == 'X') {
			matrix[x][y] = 'X';
		}
		else if (matrix[x][y] == '0') {
			matrix[x][y] = '0';
		}
		else if(matrix[x][y] == '*'){

			matrix[x][y] = '-';
		}
		else {
			matrix[x][y] = ch;
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{

				this->matrix[i][0] = arr[i];
				this->matrix[0][j] = arr[j];
				cout << this->matrix[i][j] << "\t";
			}
			cout << endl;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (this->matrix[i][j] == '*') {
					this->matrix[i][j] = '-';
				}
			}
		}
	}
}


bool Pole::getWinner()
{
	int sum=0; //кількість співпадінь
	int sum1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (this->matrix[i][j] == 'X')
				sum++;
			if (this->matrix[i][j] == '0')
				sum1++;
			if (sum == 3) {
				cout << "Winner X " << endl;
				return true;
			}
			if (sum1 == 3) {
				cout << "Winner 0 " << endl;
				return true;
			}
		}
		sum = 0;
		sum1 = 0;
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (this->matrix[j][i] == 'X')
				sum++;
			if (this->matrix[j][i] == '0')
				sum1++;
			if (sum == 3) {
				cout << "Winner X " << endl;
				return true;
			}
		    if(sum1 == 3) {
				cout << "Winner 0 " << endl;
				return true;
			}
		}
		sum = 0;
		sum1 = 0;
	}
	if (this->matrix[1][1] == this->matrix[2][2] == this->matrix[3][3] == 'X') {
		cout << "Winner X " << endl;
		return true;
	}
	if (this->matrix[1][1] == this->matrix[2][2] == this->matrix[3][3] == '0') {
		cout << "Winner 0 " << endl;
		return true;
	}


	if (this->matrix[3][1] == this->matrix[2][2] == this->matrix[1][3] == 'X') {
		cout << "Winner X " << endl;
		return true;
	}
	if (this->matrix[3][1] == this->matrix[2][2] == this->matrix[1][3] == '0') {
		cout << "Winner 0 " << endl;
		return true;
	}

	if (this->step >= 9) {
		cout << "Draw " << endl;
		return true;
	}

	return false;
}