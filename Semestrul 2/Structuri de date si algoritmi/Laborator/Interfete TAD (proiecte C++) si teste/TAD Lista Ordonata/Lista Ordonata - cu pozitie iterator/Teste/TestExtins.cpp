#include "TestExtins.h"

#include <assert.h>
#include <exception>
#include <cstdlib>
#include <vector>

#include "Iterator.h"
#include "LO.h"

using namespace std;


//Relatie de ordine - crescator
bool cresc(TElement c1, TElement c2) {
	if (c1 <= c2) {
		return true;
	} else {
		return false;
	}
}

//Relatie de ordine - descrescator
bool desc(TElement c1, TElement c2) {
	if (c1 >= c2) {
		return true;
	} else {
		return false;
	}
}

void testCreeaza() {
	LO lo = LO(cresc);
	assert(lo.dim() == 0);
	assert(lo.vida());

	Iterator it = lo.prim();
	assert(!it.valid());
	it.prim();

	for (int i = 0; i < 10; i++) {
		assert(!it.valid());
		assert(!lo.cauta(i).valid());
		try {
			assert(lo.element(it));
			assert(false);
		} catch (exception&) {
			assert(true);
		}
		try {
			assert(lo.sterge(it));
			assert(false);
		} catch (exception&) {
			assert(true);
		}
		try {
            		it.urmator();
            		assert(false);
        	    }
        	catch (exception&) {
           		 assert(true);
       		}
	}
}

//genereaza un vector continand valori >=cMin si <=cMax a.i.:
//1) nicio valoare >=cMin si <=cMax care este multiplu de s nu este continuta
//2) valorile v, v>=cMin si v<=cMax care sunt multiplu de m (dar nu de s) sunt continute de c/m + 1 ori
//3) valorile >=cMin si <=cMax apar in ordine aleatoare
vector<int> random(int cMin, int cMax, int s, int m) {
	vector<int> v;
	for (int c = cMin; c <= cMax; c++) {
		if (c % s != 0) {
			v.push_back(c);
			if (c % m == 0) {
				for (int j = 0; j < c / m; j++) {
					v.push_back(c);
				}
			}
		}
	}
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		int j = i + rand() % (n - i);
		swap(v[i], v[j]);
	}
	return v;
}

//genereaza un vector continand valorile >=cMin si <=cMax, o singura data, in ordine aleatoare
vector<int> random(int cMin, int cMax) {
	vector<int> v;
	for (int c = cMin; c <= cMax; c++) {
		v.push_back(c);
	}

	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		int j = i + rand() % (n - i);
		swap(v[i], v[j]);
	}
	return v;
}

//populeaza LO lo cu valori >=cMin si <=cMax a.i.:
//1) nicio valoare >=cMin si <=cMax care este multiplu de s nu este continuta
//2) valorile v, v>=cMin si v<=cMax care sunt multiplu de m (dar nu de s) sunt continute de c/m + 1 ori
//3) valorile >=cMin si <=cMax apar in ordine aleatoare
int populeaza(LO& lo, int cMin, int cMax, int s, int m) {
	vector<int> v = random(cMin, cMax, s, m);
	int n = v.size();
	for (int i = 0; i < n; i++) {
		lo.adauga(v[i]);
	}
	return n;
}

//populeaza LO lo cu valorile >=cMin si <=cMax in ordine aleatoare, fiecare valoare adaugand-se o singura data
void populeaza(LO& lo, int cMin, int cMax) {
	vector<int> v = random(cMin, cMax);
	int n = v.size();
	for (int i = 0; i < n; i++) {
		lo.adauga(v[i]);
	}
}

void testAdaugaSiCauta(Relatie r) {
	LO lo = LO(r);
	int vMin = 10;
	int vMax = 30;
	int s = 5;
	int m = 3;
	int n = populeaza(lo, vMin, vMax, s, m);
	assert(!lo.vida());
	assert(lo.dim() == n);

    //nu se vor gasi valori in afara intervalului considerat
	int d = 30;
	for (int i = 1; i <= d; i++) {
		assert(!lo.cauta(vMin - i).valid());
		assert(!lo.cauta(vMax + i).valid());
	}

	//se verifica respectarea relatiei de ordine
	Iterator it = lo.prim();
	assert(it.valid());
	TElement prec = it.element();
	it.urmator();
	while (it.valid()) {
		TElement curent = lo.element(it);
		assert(r(prec, curent));
		prec = curent;
		it.urmator();
	}

	//se verifica aparitia valorilor adaugate
		for (int v = vMin; v <= vMax; v++) {
			Iterator p = lo.cauta(v);
			//nu se vor gasi valori care sunt multiplu de s
			assert(p.valid() == (v % s != 0));
			//valorile care sunt multiplu de m se vor gasi de exact v/m+1 ori
            if (p.valid() && v%m == 0){
            	for (int i=0; i<=v/m; i++){
            		try{
            			assert(lo.sterge(p) == v);
            		} catch (exception&) {
						assert(false);
					}
            	}
            	assert(!lo.cauta(v).valid());
            }
		}



}

void testStergeCauta(Relatie r) {
	LO lo = LO(r);
	int vMin = 0;
	int vMax = 100;
	populeaza(lo, vMin, vMax);

	int d = 30;
	for (int i = 1; i <= d; i++) {
		try {
			
			IteratorLO caut=lo.cauta(vMax + i);
			lo.sterge(caut);
			assert(false);
		} catch (exception&) {
			assert(true);
		}
	}

	assert(!lo.vida());
	assert(lo.dim() == vMax - vMin + 1);
	Iterator it1 = lo.prim();
	assert(it1.valid());
	TElement sters = NULL_TELEMENT;
	try {
		sters = lo.sterge(it1);
		assert(lo.dim() == vMax - vMin);
		TElement nouPrim = it1.element();
		assert(nouPrim != sters);
		assert(r(sters, nouPrim));
		it1.prim();
		Iterator it2 = lo.prim();
		assert(it1.element() == nouPrim && it2.element() == nouPrim);
	} catch (exception&) {
		assert(false);
	}

	//se sterg in ordine aleatoare valori, verificandu-se relatia de ordine
	vector<int> vs = random(vMin, vMax);
	int n = vs.size();
	for (int i = 0; i < n; i++) {
		int v = vs[i];
		try {
			Iterator it1  = lo.cauta(v);
			TElement stersCurent = lo.sterge(it1);
			assert(stersCurent != sters);
			assert(stersCurent == v);
			assert(!lo.cauta(v).valid());

			if (!lo.vida()) {
				assert(lo.prim().valid());
				Iterator it2 = lo.prim();
				assert(it2.valid());
				TElement prec = it2.element();
				while (it2.valid()) {
					TElement curent = lo.element(it2);
					assert(r(prec, curent));
					assert(!r(stersCurent, curent) || !r(curent, stersCurent));
					prec = curent;
					it2.urmator();
				}
			}

		} catch (exception&) {
			assert(v == sters);
		}
	}

	assert(lo.vida());
	assert(lo.dim() == 0);
}

void testStergeCauta() {
	testStergeCauta(cresc);
	testStergeCauta(desc);
}

void testAdaugaSiCauta() {
	testAdaugaSiCauta(cresc);
	testAdaugaSiCauta(desc);
}


void testCantitativ(){
	LO lo = LO(cresc);

	int vMin = 3000;
	int vMax = 6000;
	vector<int> valori  = random(vMin, vMax);
	int n = valori.size();
    for (int i = 0; i < n; i++){
    	lo.adauga(valori[i]);
    }

    assert(lo.dim() == vMax - vMin + 1);
    for (int v = vMin; v <= vMax; v++){
      	assert(lo.cauta(v).valid());
      	assert(lo.cauta(v).element() == v);
    }

    Iterator it  = lo.prim();
    assert(it.valid());
    TElement primElement = it.element();
    it.prim();
    assert(it.valid());
    assert(it.element() == primElement);
    for (int i = 0; i < lo.dim(); i++) {
    	it.urmator();
    }

    assert(!it.valid());
    it.prim();
    while (it.valid()){
        TElement v  = it.element();
        assert(vMin <= v && v<=vMax);
        it.urmator();
    }
    assert(!it.valid());


    int d = 100;
    //se considera supraintervalul [vMin-d, vMax+d]
    for (int v = vMin-d; v <= vMax+d; v++){
    	//se verifica ca doar valori din [vMin, vMax] sa se gaseasca in LO
    	 assert(lo.cauta(v).valid() == (vMin <= v && v <= vMax));
    	 try{
			IteratorLO caut=lo.cauta(v);
    			assert(lo.sterge(caut));
    		 	assert(vMin <= v && v <= vMax);
    	 } catch (exception&) {
			 assert(vMin > v || v > vMax);
		}
    }
    assert(lo.dim() == 0);
    assert(lo.vida());
}

void testAllExtins() {
	testCreeaza();
	testAdaugaSiCauta();
	testStergeCauta();
    testCantitativ();
}

