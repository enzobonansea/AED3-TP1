#include "Helpers.h"
#include "Dinamica.h"

int sumsetsum_din(vector<int>& B, int V) {
    vector<int> A;
    for (int i = 0; i < B.size(); ++i) {
        if (B[i] <= V) A.push_back(A[i]);
    }

    // Armo el vector solucion S de tamaño V+1, con todos los elementos iguales a -1
    vector<int> S(V + 1, -1);

    for (int i = 0; i < S.size(); ++i) {
        if (i == 0) {
            S[i] = 0;
        } else {
            if (conteins(i, A)) {
                S[i] = 1;
            } else {
                vector<int> L;

                // Hago que L sea A sin los elementos mayores a i
                for (int j = 0; j < A.size(); ++j) {
                    if (A[j] < i) L.push_back(A[j]);
                }

                // i = (i - j) + j => S[i] = S[i - j] + S[j] con S[j] y S[i - j] optimas
                // Busco entonces j tal que S[j] != -1, S[i - j] != -1 y S[i - j] + S[j] es minimal

                // Elimino j = L[k] tal que S[j] == -1 o S[i - j] == -1
                vector<int> L_aux;
                for (int k = 0; k < L.size(); ++k) {
                    int j = L[k];
                    if (S[j] != -1 && S[i - j] != -1) L_aux.push_back(L[j]);
                }
                L = L_aux;

                // Guardo en m el j tal que S[i - j] != -1 y S[i - j] + S[j] es minimal
                if (!L.empty()) {
                    int j = L[0];
                    int m = j;
                    int minimal = S[i - m] + S[m];
                    for (int k = 1; k < L.size(); ++k) {
                        j = L[k];
                        int current = S[j] + S[i - j];
                        if (current < minimal) m = j;
                    }
                    S[i] = S[i - m] + S[m];
                } else {
                    S[i] = -1;
                }
            }
        }
    }
    return S[V];
}