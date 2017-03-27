#include<iostream>
using namespace std;

void swap(int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
}

bool GetMinK(int uiInputNum, int * pInputArray, int uiK, int * pOutputArray) {
    
    int i, j;
    if (uiInputNum < 1 || uiK < 1) return false;
    for (i = 0; i < uiInputNum; ++i) {
        if (i < uiK) {
            pOutputArray[i] = pInputArray[i];
            for (j = i; j > 0; --j) {
                if (pOutputArray[j] < pOutputArray[j-1]) {
                    swap(pOutputArray[j], pOutputArray[j-1]);
                } 
                else break;
            }
        } 
        else {
            if (pInputArray[i] < pOutputArray[uiK-1]) {
                pOutputArray[uiK-1] = pInputArray[i];
                for (j = uiK-1; j > 0; --j) {
                    if (pOutputArray[j] < pOutputArray[j-1]) {
                        swap(pOutputArray[j], pOutputArray[j-1]);
                    } 
                    else break;
            	}
            }
        }
    }
    
    return true;
}

int main() {
    
    int uiInputNum, uiK;
    while (cin >> uiInputNum >> uiK) {
    	int * pInputArray = new int[uiInputNum];
    	int * pOutputArray = new int[uiK];
    
    	for (int i = 0; i < uiInputNum; ++i) {
        	cin >> pInputArray[i];
    	}
    
    	GetMinK(uiInputNum, pInputArray, uiK, pOutputArray);
    
    	for (int i = 0; i < uiK-1; ++i) {
        	cout << pOutputArray[i] << ' ';
    	}
    	cout << pOutputArray[uiK-1] << endl;
    
    	delete [] pInputArray;
    	delete [] pOutputArray;
    }
    
    return 0;
}