#include "stdafx.h"
#include "Helpers.h"
#include "FuerzaBruta.h"

int subsetsum_fuerzabruta(vector<int>& A, int V){
    int res = -1;
    vector<vector<int> > partes = partes_de(A);
    vector<int> partes_sum;
    for (int i = 0; i < partes.size(); ++i)
        partes_sum.push_back(sum(partes[i]));
    vector<int> cardinales;
    for (int i = 0; i < partes_sum.size(); ++i)
        if (partes_sum[i] == V)
            cardinales.push_back(partes[i].size());
    if (!cardinales.empty())
        res = min(cardinales);

    return res;
}

vector<vector<int> >& partes_de(vector<int>& A){
    vector<vector<int> > res;
    if (A.empty()){
        vector<int> v;
        res.push_back(v);
    }else{
        vector<vector<int> > sin_primero = partes_de(tail(A));
        vector<vector<int> > con_primero = sin_primero;
        for (int i = 0; i < con_primero.size(); ++i) con_primero[i].push_back(A[0]);
        res = concat(sin_primero, con_primero);
    }

	return res;
}
