#include "Helpers.h"
#include "Backtracking.h"

int infinity = INT32_MAX;
int optimal = infinity;
int current = 0;

int subsetsum_backtracking(vector<int>& A, int V){
    int res = -1;

    optimal = infinity;
    current = 0;

    // Ordeno a A de forma decreciente
    sort(A.begin(), A.begin() + A.size());
    reverse(A.begin(), A.begin() + A.size());

    desc_in_tree(A, V);

    if (optimal != infinity) res = optimal; // en cambio, si el optimo es infinito, devuelvo -1

    return res;
}

void desc_in_tree(vector<int>& A, int V){
    if (V == 0 && current < optimal){
        optimal = current;
    }
    else if (V > 0 && current < optimal && !A.empty() && sum(A) >= V){
        int m = A[0];
        int temp = current;

        current++;
        desc_in_tree(tail(A), V - m);
        int m_included = current;

        current = temp;
        desc_in_tree(tail(A), V);
        int m_excluded = current;

        current = m_included <= m_excluded ? m_included : m_excluded;
    }
    else{
        current = infinity;
    }
}