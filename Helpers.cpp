#include "Helpers.h"

int sum(vector<int>& v){
    int res = 0;
    for (int i = 0; i < v.size(); ++i) res+= v[i];

    return res;
}

int min(vector<int>& v){
    int res = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] < res){
            res = v[i];
        }
    }

    return res;
}

vector<int>& tail(vector<int>& v){
    vector<int> res;
    for (int i = 1; i < v.size(); ++i) res.push_back(v[i]);

    return res;
}

vector<vector<int> > concat(vector<vector<int> >& a, vector<vector<int> >& b){
    vector<vector<int> > res;
    for (int i = 0; i < a.size(); ++i) res.push_back(a[i]);
    for (int i = 0; i < b.size(); ++i) res.push_back(b[i]);

    return res;
}

bool conteins(int e, vector<int>& v){
    bool res = false;
    for (int i = 0; i < v.size() && !res; ++i) res = v[i] == e;

    return res;
}

void print(vector<int>& v){
    cout << "[ " << flush;
    for (int i = 0; i < v.size()-2; ++i) cout << v[i] + ", " << flush;
    cout << v[v.size() - 1] + " ]" << flush;
}