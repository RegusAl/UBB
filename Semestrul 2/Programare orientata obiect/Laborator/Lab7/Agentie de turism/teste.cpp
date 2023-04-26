#include "teste.h"
#include <cassert>
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
    assert(o1.getTip()=="all-inclusive");
    assert(o1.getPret()==2345);
    try {
        repo.cauta("nuj", "nuj");
        assert(false);
    }
    catch (OfertaRepoException& ex) {
        stringstream os;
        os<<ex;
        assert(os.str().find("exista")>=0);
        assert(true);
    }
}

void test_stergere() {
    OfertaRepo repo;
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    Oferta o1 = Oferta("La mare", "Mamaia", "all-inclusive", 2345);
    repo.stergere(o1);
    //assert(repo.getAll().empty());
    Oferta o2 = Oferta("La mare", "Mamaia", "all-inclusive", 2345);
    try {
        repo.stergere(o2);
        assert(false);
    }
    catch (OfertaRepoException& ex) {
        stringstream os;
        os << ex;
        assert(os.str().find("Nu se poate sterge o oferta ce nu exista")>=0);
        assert(true);
    }
}

// TESTE SERVICE
void test_getAll() {
    OfertaRepo repo;
    AgentieService service{repo};
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    repo.adauga(Oferta("Munte", "Sinaia", "all-inclusive", 1280));
    assert(repo.getAll().size()==2);
    VectorDinamic<Oferta> oferte = service.getAll();
    assert(oferte.size()==2);
}

void test_adaugaOferta() {
    OfertaRepo repo;
    AgentieService service{repo};
//    assert(repo.getAll().empty());
    service.adaugaOferta("La mare", "Mamaia", "all-inclusive", 2345);
    assert(repo.getAll().size()==1);
}

void test_modificaOferta() {
    OfertaRepo repo;
    AgentieService service{repo};
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    service.modificaOferta("La mare", "Mamaia", "3 zile", 1000);
    auto o = repo.cauta("La mare", "Mamaia");
    assert(o.getTip()=="3 zile");
    assert(o.getPret()==1000);
}

void test_stergeOferta() {
    OfertaRepo repo;
    AgentieService service{repo};
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
//    service.stergereOferta("La munte", "Sinaia");
//    assert(repo.getAll().size()==1);
    service.stergereOferta("La mare", "Mamaia");
//    assert(repo.getAll().empty());
}

//void test_filtrareDestinatie() {
//    OfertaRepo repo;
//    AgentieService service{repo};
//    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
//    assert(repo.getAll().size()==1);
//    repo.adauga(Oferta("Plaja", "Mamaia", "-", 400));
//    repo.adauga(Oferta("Munte", "Sinaia", "all-inclusive", 1234));
//    VectorDinamic<Oferta> listaFiltrata1 = service.filtrareDestinatie("Mamaia");
//    assert(listaFiltrata1.size()==2);
//    assert(listaFiltrata1.get(0).getPret()==2345);
//    assert(listaFiltrata1.get(1).getPret()==400);
//    VectorDinamic<Oferta> listaFiltrata2 = service.filtrareDestinatie("Exemplu");
////    assert(listaFiltrata2.empty());
//}
//
//void test_filtrarePret() {
//    OfertaRepo repo;
//    AgentieService service{repo};
//    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
//    assert(repo.getAll().size()==1);
//    repo.adauga(Oferta("Plaja", "Mamaia", "-", 400));
//    repo.adauga(Oferta("Munte", "Sinaia", "all-inclusive", 1234));
//    VectorDinamic<Oferta> listaFiltrata1 = service.filtrarePret(2000);
//    assert(listaFiltrata1.size()==2);
//    assert(listaFiltrata1.get(0).getPret()==400);
//    assert(listaFiltrata1.get(1).getPret()==1234);
//    VectorDinamic<Oferta> listaFiltrata2 = service.filtrarePret(10);
//    assert(typeid(service.filtrarePret(100))== typeid(VectorDinamic<Oferta>));
////    assert(listaFiltrata2.empty());
//}

void test_all() {
    // Teste REPOSITORY
    test_adauga();
    test_cauta();
    test_stergere();
    // Teste SERVICE
    test_getAll();
    test_adaugaOferta();
    test_modificaOferta();
    test_stergeOferta();
//    test_filtrareDestinatie();
//    test_filtrarePret();
}