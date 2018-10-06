// AED3-TP1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Helpers.h"
#include "FuerzaBruta.h"
#include "Backtracking.h"
#include "Dinamica.h"
#include <ctime>

unsigned t0, t1;
double span;

int main() {
    vector<int> A = {3, 2, 1, 1};
    int V = 4;
    int res = 2;

    t0=clock();
    int fb = subsetsum_fuerzabruta(A, V);
    t1 = clock();
    span = (double(t1-t0)/CLOCKS_PER_SEC) * 1000;
    cout << "Fuerza bruta tardo: " << span << "ms" << endl;

    t0=clock();
    int bt = subsetsum_backtracking(A, V);
    t1 = clock();
    span = (double(t1-t0)/CLOCKS_PER_SEC) * 1000;
    cout << "Backtracking tardo: " << span << "ms" << endl;

    t0=clock();
    int di = sumsetsum_din(A, V);
    t1 = clock();
    span = (double(t1-t0)/CLOCKS_PER_SEC) * 1000;
    cout << "Dinamica tardo: " << span << "ms" << endl;

    return 0;
}
