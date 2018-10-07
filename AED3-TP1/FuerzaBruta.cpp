#include "stdafx.h"
#include "Helpers.h"
#include "FuerzaBruta.h"

int subsetsum_fuerzabruta(vector<int>& A, int V){
	int n = A.size();
	int res = -1;
	vector<vector<int> >* ptr_partes = new vector<vector<int> >(); 	// guardo en memoria dinamica un vector para almacenar allí partes(A)
	calcular_partes(&A, ptr_partes);
    vector<int> partes_sum;
	for (int i = 0; i < ptr_partes->size(); ++i) {
        partes_sum.push_back(sum((*ptr_partes)[i]));
	}
    vector<int> cardinales;
	for (int i = 0; i < partes_sum.size(); ++i) {
		if (partes_sum[i] == V) {
            cardinales.push_back((*ptr_partes)[i].size());
		}
	}
	if (!cardinales.empty()) {
        res = min(cardinales);
	}

    return res;
}

void calcular_partes(vector<int>* ptr_A, vector<vector<int> >* ptr_partes) {
	if (ptr_A->empty()) {
		vector<int> vacio;
		ptr_partes->push_back(vacio);
	}
	else {
		vector<vector<int> >* ptr_sin_primero = new vector<vector<int> >();
		vector<int>* ptr_tail = tail(*ptr_A);
		calcular_partes(ptr_tail, ptr_sin_primero);
		vector<vector<int> >* ptr_con_primero = new vector<vector<int> >();
		*ptr_con_primero = *ptr_sin_primero;
		for (int i = 0; i < ptr_con_primero->size(); i++)
		{
			(*ptr_con_primero)[i].push_back((*ptr_A)[0]);
		}
		concatenar_en(ptr_sin_primero, ptr_con_primero, ptr_partes);
		
		delete ptr_tail;
		delete ptr_sin_primero;
		delete ptr_con_primero;
	}
}

void concatenar_en(vector<vector<int> >* ptr_sin_primero, vector<vector<int> >* ptr_con_primero, vector<vector<int> >* ptr_partes) {
	for (int i = 0; i < ptr_sin_primero->size(); i++)
	{
		ptr_partes->push_back((*ptr_sin_primero)[i]);
	}
	for (int i = 0; i < ptr_con_primero->size(); i++)
	{
		ptr_partes->push_back((*ptr_con_primero)[i]);
	}
}