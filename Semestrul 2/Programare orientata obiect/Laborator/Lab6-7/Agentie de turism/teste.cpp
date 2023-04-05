#include "teste.h"
#include <assert.h>
#include <sstream>

using std::ostream;
using std::stringstream;

//TESTE REPO
void test_adauga() {
    OfertaRepo repo;
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    repo.adauga(Oferta("Munte", "Sinaia", "all-inclusive", 1280));
    assert(repo.getAll().size()==2);
    try {
        repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
        assert(false);
    }
    catch (const OfertaRepoException& ex) {
        stringstream os;
        os << ex;
        assert(os.str().find("Exista")>=0);
    }
}

void test_cauta() {
    OfertaRepo repo;
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    auto o1 = repo.cauta("La mare", "Mamaia");
    assert(o1.getDestinatie()=="Mamaia");
    assert(o1.getDenumire()=="La mare");
    try {
        repo.cauta("nuj", "nuj");
        assert(false);
    }
    catch (OfertaRepoException& ex) {
        stringstream os;
        os<<ex;
        assert(os.str().find("exista")>=0);
    }
}

void test_stergere() {
    OfertaRepo repo;
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    Oferta o1 = Oferta("La mare", "Mamaia", "all-inclusive", 2345);
    repo.stergere(o1);
    assert(repo.getAll().size()==0);
    Oferta o2 = Oferta("La mare", "Mamaia", "all-inclusive", 2345);
    try {
        repo.stergere(o2);
        assert(false);
    }
    catch (OfertaRepoException& ex) {
        stringstream os;
        os << ex;
        assert(os.str().find("Nu se poate sterge o oferta ce nu exista")>=0);
    }
}

//void test_modificare() {
//    OfertaRepo repo;
//    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
//    assert(repo.getAll().size()==1);
//    auto o = repo.modificaOferta("La mare", "Mamaia", "3 zile", 1000);
//    //assert(o.getTip()=="3 zile");
//}

void test_all_repository() {
    test_adauga();
    test_cauta();
    test_stergere();
    //test_modificare();
}
