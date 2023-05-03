#include "TestScurt.h"

using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void test_functionalitate_noua() {
    MDO dictionar = MDO(relatie1);
    assert(dictionar.dim() == 0);
    assert(dictionar.vid());
    assert(dictionar.ceaMaiFrecventaValoare()==NULL_TVALOARE);
//    cout<<dictionar.ceaMaiFrecventaValoare()<<endl;
    dictionar.adauga(1,3);
    dictionar.adauga(2, 2);
    dictionar.adauga(2, 3);
    assert(dictionar.dim()==3);
    assert(dictionar.ceaMaiFrecventaValoare()==3);
//    cout<<dictionar.ceaMaiFrecventaValoare()<<endl;
    cout<<"Test functionalitate - passed!"<<endl;
}

void testAll(){
	MDO dictOrd = MDO(relatie1);
    // assert(dictOrd.ceaMaiFrecventaValoare()==NULL);
	assert(dictOrd.dim() == 0);
	assert(dictOrd.vid());
    dictOrd.adauga(1,2);
    dictOrd.adauga(1,3);
    assert(dictOrd.dim() == 2);
    assert(!dictOrd.vid());
    vector<TValoare> v= dictOrd.cauta(1);
    assert(v.size()==2);
    v= dictOrd.cauta(3);
    assert(v.size()==0);
    IteratorMDO it = dictOrd.iterator();
    it.prim();
    while (it.valid()){
    	TElem e = it.element();
//        cout << e.first << " " << e.second << endl;
    	it.urmator();
    }
//    cout<<dictOrd.ceaMaiFrecventaValoare();
    assert(dictOrd.sterge(1, 2) == true);
    assert(dictOrd.sterge(1, 3) == true);
    assert(dictOrd.sterge(2, 1) == false);
    assert(dictOrd.vid());
    test_functionalitate_noua();
}

