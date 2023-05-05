#include "teste.h"
#include <cassert>
#include <sstream>
#include <vector>

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
        repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));assert(false);
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
        repo.cauta("nuj", "nuj");assert(false);
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
    assert(repo.getAll().size()==0);
}

// TESTE SERVICE
void test_getAll() {
    OfertaRepo repo;
    Validator valid;
    AgentieService service{repo, valid};
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    repo.adauga(Oferta("Munte", "Sinaia", "all-inclusive", 1280));
    assert(repo.getAll().size()==2);
    auto oferte = service.getAll();
    assert(oferte.size()==2);
}

void test_adaugaOferta() {
    OfertaRepo repo;
    Validator valid;
    AgentieService service{repo, valid};
    assert(service.getAll().size()==0);
    service.adaugaOferta("La Mare", "Mamaia", "allinclusive", 2345);
    assert(service.getAll().size()==1);
    try {
        service.adaugaOferta("12343", "nuj", "fgfg", 1234);assert(false);
    }
    catch (Exception& exception) {
        assert(exception.getMessage().find("invalid")!=std::string::npos);
        assert(true);
    }
}

void test_modificaOferta() {
    OfertaRepo repo;
    Validator valid;
    AgentieService service{repo, valid};
    service.adaugaOferta("La mare", "Mamaia", "allinclusive", 2345);
    assert(repo.getAll().size()==1);
    service.modificaOferta("La mare", "Mamaia", "trei zile", 1000);
    auto o = repo.cauta("La mare", "Mamaia");
    assert(o.getTip()=="trei zile");
    assert(o.getPret()==1000);
}

void test_stergeOferta() {
    OfertaRepo repo;
    Validator valid;
    AgentieService service{repo, valid};
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
//    service.stergereOferta("La munte", "Sinaia");
//    assert(repo.getAll().size()==1);
    service.stergereOferta("La mare", "Mamaia");
//    assert(repo.getAll().empty());
}

void test_filtrareDestinatie() {
    OfertaRepo repo;
    Validator valid;
    AgentieService service{repo, valid};
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    repo.adauga(Oferta("Plaja", "Mamaia", "-", 400));
    repo.adauga(Oferta("Munte", "Sinaia", "all-inclusive", 1234));
    VectorDinamic<Oferta> listaFiltrata1 = service.filtrareDestinatie("Mamaia");
    assert(listaFiltrata1.size()==2);
    assert(listaFiltrata1.get(0).getPret()==2345);
    assert(listaFiltrata1.get(1).getPret()==400);
    VectorDinamic<Oferta> listaFiltrata2 = service.filtrareDestinatie("Exemplu");
//    assert(listaFiltrata2.empty());
}

void test_filtrarePret() {
    OfertaRepo repo;
    Validator valid;
    AgentieService service{repo, valid};
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    repo.adauga(Oferta("Plaja", "Mamaia", "-", 400));
    repo.adauga(Oferta("Munte", "Sinaia", "all-inclusive", 1234));
    VectorDinamic<Oferta> listaFiltrata1 = service.filtrarePret(2000);
    assert(listaFiltrata1.size()==2);
    assert(listaFiltrata1.get(0).getPret()==400);
    assert(listaFiltrata1.get(1).getPret()==1234);
    VectorDinamic<Oferta> listaFiltrata2 = service.filtrarePret(10);
    assert(typeid(service.filtrarePret(100))== typeid(VectorDinamic<Oferta>));
    assert(listaFiltrata2.size()==0);
}

int sortByDenumireTest(const Oferta& o1, const Oferta& o2) {
    return o1.getDenumire().compare(o2.getDenumire());
}

int sortByDestinatieTest(const Oferta& o1, const Oferta& o2) {
    return o1.getDestinatie().compare(o2.getDestinatie());
}

int sortByTipSiPretTest(const Oferta& o1, const Oferta& o2) {
    if (o1.getTip() == o2.getTip()) {
        return (o1.getTip().compare(o2.getTip()));}
    else {
        return o1.getPret()>o2.getPret();
    }
}

void test_sortareOferte() {
    OfertaRepo repo;
    Validator valid;
    AgentieService service{ repo, valid };
    service.adaugaOferta("a", "b", "csc", 100);
    service.adaugaOferta("sa", "a", "c", 50);
    service.adaugaOferta("t", "y", "c", 63);
    service.adaugaOferta("o", "xc", "m", 100);

    auto list = service.sortareOferte(sortByDenumireTest);
    auto list2 = service.sortareOferte(sortByDestinatieTest);
    auto list3 = service.sortareOferte(sortByTipSiPretTest);

    assert(list.size() == 4);
    assert(list.get(0).getDenumire() == "a");
    assert(list.get(3).getDenumire() == "t");

    assert(list2.size() == 4);
    assert(list2.get(1).getDenumire() == "a");
    assert(list2.get(2).getDenumire() == "o");

    assert(list3.size() == 4);
    assert(list3.get(0).getDenumire() == "sa");
    assert(list3.get(1).getDenumire() == "t");
}

template <typename MyVector>
MyVector testCopyIterate(MyVector v) {
    int totalPrice = 0;
    for (const auto& el : v) {
        totalPrice += el.getPret();
    }
    Oferta p{ "total","tt", "sdd", totalPrice};
    v.push_back(p);
    return v;
}

template <typename MyVector>
void addOferte(MyVector& v, int cate) {
    for (int i = 0; i < cate; i++) {
        Oferta p{ std::to_string(i) + "_denumire",std::to_string(i) + "_destinatie",std::to_string(i) + "_tip", i + 10 };
        v.push_back(p);
    }
}

/*
Testare constructori / assignment
E template pentru a refolosi la diferite variante de VectorDinamic din proiect
*/
template <typename MyVector>
void testCreateCopyAssign() {
    MyVector v;//default constructor
    addOferte(v, 100);
    assert(v.size() == 100);
    assert(v.get(50).getTip() == "50_tip");

    MyVector v2{ v };//constructor de copiere
    assert(v2.size() == 100);
    assert(v2.get(50).getTip() == "50_tip");

    MyVector v3;//default constructor
    v3 = v;//operator=   assignment
    assert(v3.size() == 100);
    assert(v3.get(50).getTip() == "50_tip");

    auto v4 = testCopyIterate(v3);
    assert(v4.size() == 101);
    assert(v4.get(50).getTip() == "50_tip");
}

/*
  Test pentru move constructor si move assgnment
*/
template <typename MyVector>
void testMoveConstrAssgnment() {
    std::vector<MyVector> v;
    //adaugam un vector care este o variabila temporara
    //se v-a apela move constructor
    v.push_back(MyVector{});

    //inseram, la fel se apeleaza move costructor de la vectorul nostru
    v.insert(v.begin(), MyVector{});

    assert(v.size() == 2);

    MyVector v2;
    addOferte(v2, 50);

    v2 = MyVector{};//move assignment

    assert(v2.size() == 0);

}


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
    test_filtrareDestinatie();
    test_filtrarePret();
    test_sortareOferte();

    testCreateCopyAssign<VectorDinamic<Oferta>>();
    testMoveConstrAssgnment<VectorDinamic<Oferta>>();
}