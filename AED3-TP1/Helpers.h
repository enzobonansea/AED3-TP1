//
// Created by enzo on 16/09/18.
//

#ifndef TP1_HELPERS_H
#define TP1_HELPERS_H

#include <vector>
#include <iostream>
#include "math.h"
#include <algorithm>

using namespace std;

int sum(vector<int>& v);
int min(vector<int>& v); //PRE: v.empty() == false
vector<int>* tail(vector<int>& v); //PRE: v.empty() == false
vector<vector<int> > concat(vector<vector<int> >& a, vector<vector<int> >& b);
bool conteins(int e, vector<int>& v);
void print(vector<int>& v);
void concatenar_en(vector<vector<int> >* ptr_sin_primero, vector<vector<int> >* ptr_con_primero, vector<vector<int> >* ptr_partes);

#endif //TP1_HELPERS_H
