#include <iostream>
using namespace std;

int maze[10][10] = {0};

bool search(int i, int j, int n, int m) 
{
	maze[i][j] = 2;//visited
	if (i == n-1 && j == m-1) return true;
	bool l, r, u, d;
	l = r = u = d = false;
	if (i < n-1 && maze[i+1][j] == 0)
		d = search(i+1, j, n, m);
	if (j < m-1 && maze[i][j+1] == 0)
		r = search(i, j+1, n, m);
	if (i > 0 && maze[i-1][j] == 0)
		u = search(i-1, j, n, m);
	if (j > 0 && maze[i][j-1] == 0)
		l = search(i, j-1, n, m);
	if (!d && !r && !u && !l) {
		maze[i][j] = 1;
		return false;
	}
	return true;
}

void print_trace(int i, int j, int n, int m) 
{
	cout << "(" << i << "," << j << ")" << endl;
	maze[i][j] = 0;
	if (i < n-1 && maze[i+1][j] == 2) print_trace(i+1, j, n, m);
	if (j < m-1 && maze[i][j+1] == 2) print_trace(i, j+1, n, m);
	if (i > 0 && maze[i-1][j] == 2) print_trace(i-1, j, n, m);
	if (j > 0 && maze[i][j-1] == 2) print_trace(i, j-1, n, m);
}

int main()
{
	int n, m;
	while (cin >> n >> m) 
	{
		int i, j;
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
				cin >> maze[i][j];
		if (maze[0][0] == 0 && search(0, 0, n, m)){
			/*
			cout << endl;
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < m; ++y)
					cout << maze[x][y] << " ";
				cout << endl;
			}
			*/
			print_trace(0, 0, n, m);
		}
	}
	return 0;
}