#include<iostream>
#include<vector>
using namespace std;

int GetResult(vector<int> &list) {
    for (int z = 0; z <= 100; z+=3) {
        int x = z/3*4-100;
        int y = 200-z/3*7;
        if (x >= 0 && x <= 100 && y >=0 && y <= 100) {
            list.push_back(x);
            list.push_back(y);
            list.push_back(z);
        }
    }
    return 0;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> list;
        GetResult(list);
        for (int i = 0; i < list.size(); i+=3) {
            cout << list[i] << " " << list[i+1] << " " << list[i+2] << endl;
        }
    }
    return 0;
}