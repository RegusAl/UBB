#include <iostream>

#include "TestExtins.h"
#include "TestScurt.h"
#include "Colectie.h"

using namespace std;

//void creare(Colectie& c) {
//    c.adauga(5);
//    c.adauga(2);
//    c.adauga(5);
//    c.adauga(6);
//    c.adauga(7);
//    c.adauga(2);
//    c.adauga(1);
//    c.adauga(1);
//    c.adauga(1);
//}
//
//void tiparire(Colectie& c) {
//    IteratorColectie i = c.iterator();
//    i.prim();
//    cout<<c.dim()<<endl;
//    while(i.valid()) {
//        cout<<i.element()<<" "<<c.nrAparitii(i.element())<<" ";
//        i.urmator();
//    }
//}

int main() {
    cout<<"Test Extins: ";
	testAllExtins();
    cout<<"done"<<endl;
	cout<<"Test Scurt: ";
    testAll();
    cout<<"done"<<endl;

//    Colectie c;
//    creare(c);
//    tiparire(c);


    return 0;
}
