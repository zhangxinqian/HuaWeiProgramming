#include <iostream>
using namespace std;

int b[9][9] = {0};

bool check_row(int num, int i) 
{
	for (int j = 0; j < 9; j++)
		if (num == b[i][j]) return false;
	return true;
}

bool check_column(int num, int j)
{
	for (int i = 0; i < 9; i++)
		if (num == b[i][j]) return false;
	return true;
}

bool check_block(int num, int i, int j)
{
	int cx = 1+i/3*3;
	int cy = 1+j/3*3;
	for (int x = -1; x <= 1; x++)
		for (int y = -1; y <= 1; y++)
			if (num == b[cx+x][cy+y]) return false;
	return true;
}

bool sudoku(int i, int j) 
{
	while (b[i][j] != 0) {
		if (i == 8 && j == 8) return true;
		i++;
		if (i == 9) {
			i = 0;
			j++;
		}
	}
	for (int num = 1; num <= 9; ++num) {
		if (check_row(num, i) && check_column(num, j) && check_block(num, i, j)) {
			b[i][j] = num;
			if (sudoku(i, j)) return true;
			else b[i][j] = 0;
		}
	}
	return false;
}

int main()
{
	int i, j;
	for (i = 0; i < 9; i++) 
		for (j = 0; j < 9; j++)
			cin >> b[i][j];
	if (sudoku(0, 0)) {
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 8; j++)
				cout << b[i][j] << " ";
			cout << b[i][8] << endl;
		}
	}
	return 0;
}