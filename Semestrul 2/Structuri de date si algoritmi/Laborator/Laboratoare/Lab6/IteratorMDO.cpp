#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>

const std::pair<int, int> NIL(-1, -1);

vector<TElem> IteratorMDO::interclasare(vector<TElem> v1, vector<TElem> v2, Relatie r) {
    //O(n+m)
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

IteratorMDO::IteratorMDO(const MDO &d) : dict(d) {
    //O(m^2)
    bool viz[400];
    for (int i = 0; i < dict.m; i++) {
        viz[i] = false;
    }
    vector<vector<TElem>> matr;
    for (int j = 0; j < dict.m; j++) {
        vector<TElem> v;
        for (int i = 0; i < dict.m; i++) {
            TElem crt = std::pair<int, int>(dict.e[j].first, 0);
            int k = dict.d(crt.first);
            if (dict.e[k] != NIL && !viz[k]) {
                if (!v.empty()) {
                    auto last = v.front();
                    if ((Relatie) (last.first, dict.e[k].first) && dict.d(last.first) == dict.d(dict.e[k].first)) {
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
            matr.push_back(v);
        }
    }

    vector<TElem> ordonat;
    //O(m)
    for (int i = 0; i < matr.size(); i++) {
        auto v1 = matr[i];
        ordonat = interclasare(v1, ordonat, dict.relatie);
    }

    elems = ordonat;
    pozcrt = elems.begin();
}


void IteratorMDO::prim() {
    pozcrt = elems.begin();
}

void IteratorMDO::urmator() {
    if (!this->valid()) {
        throw exception();
    }
    pozcrt++;
}

bool IteratorMDO::valid() const {
    return pozcrt != elems.end();
}

TElem IteratorMDO::element() const {
    if (!this->valid()) {
        throw exception();
    }
    return *pozcrt;
}


