#include<iostream>
using namespace std;

int findNumberOf1(int num) {
    int count = 0;
    while (num != 0) {
        if (num % 2 == 1) {
            count ++;
        }
        num = num >> 1;
    }
    return count;
}

int main() {
    int n;
    while (cin >> n) {
        cout << findNumberOf1(n) << endl;
    }  
    return 0;
}