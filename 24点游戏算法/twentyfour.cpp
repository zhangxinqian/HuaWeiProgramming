#include<iostream>
using namespace std;

double operate(int op, double x, double y)
{
	switch (op)
	{
	case 0:
		return x+y;
	case 1:
		return x-y;
	case 2:
		return x*y;
	case 3:
		return x/y;
	default:
		return 0;
	}
}

bool _is24(int * num)
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k)
			{			
				if (operate(j, operate(i, num[0], num[1]), operate(k, num[2], num[3])) == 24 || 
					operate(k, operate(j, operate(i, num[0], num[1]), num[2]), num[3]) == 24 || 
					operate(k, operate(i, num[0], operate(j, num[1], num[2])), num[3]) == 24 || 
					operate(i, num[0], operate(k, operate(j, num[1], num[2]), num[3])) == 24 || 
					operate(i, num[0], operate(j, num[1], operate(k, num[2], num[3]))) == 24) {
						return true;
				}
			}
		}
	}
	return false;
}

void swap(int &x, int &y) 
{
	int t = x;
	x = y;
	y = t;
}

bool is24(int * num, int b, int e)
{
	if (b == e) return _is24(num);	
	for (int i = b; i <= e; ++i) {
		swap(num[b], num[i]);
		if (is24(num, b+1, e)) return true;
		swap(num[b], num[i]);
	}
	return false;
}

int main()
{
	int num[4];
	while (cin >> num[0] >> num[1] >> num[2] >> num[3]) {
		if (is24(num, 0, 3)) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}