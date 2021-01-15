#include <iostream>
#include "mpp.hpp"

using namespace std;

int main () {

    MPP *matriz = new MPP(15, 20);//Crea la nueva matriz poco problada

    int posX[10] = {   5,   2,  7,   8,   9,  0,  5,  4,  1, 7 };
    int posY[10] = {   8,   5,  4,   1,   9,  0,  6,  7,  3, 4 };
    int val[10]  = { 545, 123, 27, 141, 258, 12,  0, 25, 76, 8 };

    for (int i = 0; i < 10; i++){
    	matriz->add(val[i],posX[i],posY[i]);
	}
        

    cout << matriz->get(6, 4) << "\n";
    cout << matriz->get(5, 2) << "\n";
    cout << matriz->get(6, 9) << "\n";
    cout << matriz->get(0, 0) << "\n";
    cout << matriz->get(7, 4) << "\n";
    cout << matriz->get(2, 2) << "\n";

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "(" << i << "," << j << ") --> " << matriz->get(i, j) << " | ";
        }
        cout << "\n";
    }

    return 0;
}
