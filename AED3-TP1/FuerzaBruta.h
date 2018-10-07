//
// Created by enzo on 16/09/18.
//

#ifndef TP1_FUERZABRUTA_H
#define TP1_FUERZABRUTA_H

using namespace std;

void calcular_partes(vector<int>* A, vector<vector<int> >* ptr_partes);
int subsetsum_fuerzabruta(vector<int>& A, int V);
void concatenar_en(vector<vector<int> >* ptr_sin_primero, vector<vector<int> >* ptr_con_primero, vector<vector<int> >* ptr_partes);

#endif //TP1_FUERZABRUTA_H
