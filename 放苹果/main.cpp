#include<iostream>
using namespace std;

int count(int m, int n) {
    if (m < 0 || n <= 0) {
        return 0;
    }
    if (n == 1 || m == 1 || m == 0) {
        return 1;
    }
    return count(m, n-1) + count(m-n, n);
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        cout << count(m, n) << endl;
    }  
    return 0;
}