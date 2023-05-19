#include <assert.h>

#include "MDO.h"
#include "IteratorMDO.h"

#include <exception>
#include <iostream>
#include <vector>

using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    } else {
        return false;
    }
}

void testAll() {
    MDO dictOrd = MDO(relatie1);
    assert(dictOrd.dim() == 0);
    assert(dictOrd.vid());
    dictOrd.adauga(1, 2);
    dictOrd.adauga(1, 3);
    assert(dictOrd.dim() == 2);
    assert(!dictOrd.vid());
    vector<TValoare> v = dictOrd.cauta(1);
    assert(v.size() == 2);
    v = dictOrd.cauta(3);
    assert(v.size() == 0);
    IteratorMDO it = dictOrd.iterator();
    it.prim();
    while (it.valid()) {
        TElem e = it.element();
        it.urmator();
    }
    assert(dictOrd.sterge(1, 2) == true);
    assert(dictOrd.sterge(1, 3) == true);
    assert(dictOrd.sterge(2, 1) == false);
    assert(dictOrd.vid());

    MDO mdo1 = MDO(relatie1);
    MDO mdo2 = MDO(relatie1);
    mdo1.adauga(3, 5);
    mdo1.adauga(4, 6);
    mdo1.adauga(1, 2);
    mdo2.adauga(5, 7);
    mdo2.adauga(1, 2);
    mdo2.adauga(2, 8);
    mdo2.adauga(3, 56);
//    cout << "Perechi in mdo2: " << mdo2.dim() << endl;
    assert(mdo1.adaugaInexistente(mdo2) == 3);
    assert(mdo1.dim() == 6);
    cout << "Test functionalitate noua - passed!" << endl;
}

