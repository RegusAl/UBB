#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>

const std::pair<int, int> NIL(-1, -1);

// O(n+m)
// interclasam doi vectori
vector<TElem> IteratorMDO::interclasare(vector<TElem> v1, vector<TElem> v2, Relatie r) {
    auto i = v1.begin();
    auto j = v2.begin();
    vector<TElem> rez;
    while (i != v1.end() && j != v2.end()) {
        if (r(i->first, j->first)) {
            rez.push_back(pair<int, int>(i->first, i->second));
            i++;
        } else {
            rez.push_back(pair<int, int>(j->first, j->second));
            j++;
        }
    }
    while (i < v1.end()) {
        rez.push_back(pair<int, int>(i->first, i->second));
        i++;
    }
    while (j != v2.end()) {
        rez.push_back(pair<int, int>(j->first, j->second));
        j++;
    }

    return rez;
}

// O(m^2)
IteratorMDO::IteratorMDO(const MDO &d) : dict(d) {
    bool viz[300];
    for (int i = 0; i < dict.m; i++) {
        viz[i] = false;
    }
    vector<vector<TElem>> M;
    for (int j = 0; j < dict.m; j++) {
        vector<TElem> v;
        for (int i = 0; i < dict.m; i++) {
            TElem crt = std::pair<int, int>(dict.e[j].first, 0);
            int k = dict.dispersie(crt.first);
            if (dict.e[k] != NIL && !viz[k]) {
                if (!v.empty()) {
                    auto last = v.front();
                    if ((Relatie) (last.first, dict.e[k].first) &&
                        dict.dispersie(last.first) == dict.dispersie(dict.e[k].first)) {
                        v.push_back(dict.e[k]);
                        viz[k] = true;
                    } else
                        break;
                } else {
                    v.push_back(dict.e[k]);
                    viz[k] = true;
                }
            }
            if (dict.e[k] == NIL) {
                break;
            }
        }

        if (!v.empty()) {
            M.push_back(v);
        }
    }

    vector<TElem> ordonat; // vectorul cu elemente ordonate
    // O(m)
    for (int i = 0; i < M.size(); i++) {
        auto v1 = M[i];
        ordonat = interclasare(v1, ordonat, dict.relatie);
    }

    elems = ordonat;
    pozcrt = elems.begin();
}


void IteratorMDO::prim() {
    pozcrt = elems.begin(); // reseteaza pozitia iteratorului la inceput
}

void IteratorMDO::urmator() {
    if (!this->valid()) {
        throw exception(); // arunca exceptie daca iteratorul nu este valid
    }
    pozcrt++;
}

bool IteratorMDO::valid() const {
    return pozcrt != elems.end();
}

TElem IteratorMDO::element() const {
    if (!this->valid()) {
        throw exception();  // arunca exceptie daca iteratorul nu este valid
    }
    return *pozcrt; // indica spre un element al dictionarului
}


