#include<iostream>
#include<string>
using namespace std;

int main() {
    string dna;
    int n;
    while (cin >> dna >> n) {
        int i, j;
        int maxcount = 0, maxindex = 0;
        for (i = 0; i < dna.length()-n; ++i) {
            int tempcount = 0;
            for (j = 0; j < n; ++j) {
                if (dna[i+j] == 'G'|| dna[i+j] == 'C') {
                    tempcount ++;
                }
            }
            if (maxcount < tempcount) {
                maxcount = tempcount;
                maxindex = i;
            }
        }
        for (i = 0; i < n; ++i) {
            cout << dna[maxindex+i];
        }
        cout << endl;
    }  
    return 0;
}