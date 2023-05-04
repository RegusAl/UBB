#include "teste.h"
#include <cassert>
#include <sstream>
#include <vector>

using std::ostream;
using std::stringstream;
using std::vector;

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
        assert(os.str().find("exista")>0);
        assert(true);
    }
}

void test_stergere() {
    OfertaRepo repo;
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    Oferta o1 = Oferta("La mare", "Mamaia", "all-inclusive", 2345);
    repo.stergere(o1);
    assert(repo.getAll().empty());
}

// TESTE SERVICE
void test_getAll() {
    OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    repo.adauga(Oferta("Munte", "Sinaia", "all-inclusive", 1280));
    assert(repo.getAll().size()==2);
    vector<Oferta> oferte = service.getAll();
    assert(oferte.size()==2);
}

void test_adaugaOferta() {
    OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    assert(service.getAll().empty());
    service.adaugaOferta("La Mare", "Mamaia", "allinclusive", 2345);
    assert(service.getAll().size()==1);
}

void test_modificaOferta() {
    OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
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
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    repo.adauga(Oferta("La mare", "Mamaia", "all inclusive", 2345));
    assert(repo.getAll().size()==1);
    try {
        service.stergereOferta("La munte", "Sinaia");
    } catch(OfertaRepoException& ex) {
        stringstream os;
        os<<ex;
        assert(os.str().find("exista")>0);
        assert(true);
    }
    assert(repo.getAll().size()==1);
    service.stergereOferta("La mare", "Mamaia");
    assert(repo.getAll().empty());
    repo.adauga(Oferta("ex unu", "d unu", "e", 2345));
    repo.adauga(Oferta("ex doi", "d doi", "e", 2345));
    service.stergereOferta("ex doi", "d doi");
    assert(repo.getAll().size()==1);
}

void test_filtrareDestinatie() {
    OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    repo.adauga(Oferta("Plaja", "Mamaia", "-", 400));
    repo.adauga(Oferta("Munte", "Sinaia", "all-inclusive", 1234));
    vector<Oferta> listaFiltrata1 = service.filtrareDestinatie("Mamaia");
    assert(listaFiltrata1.size()==2);
//    assert(listaFiltrata1.get(0).getPret()==2345);
//    assert(listaFiltrata1.get(1).getPret()==400);
    vector<Oferta> listaFiltrata2 = service.filtrareDestinatie("Exemplu");
//    assert(listaFiltrata2.empty());
}

void test_filtrarePret() {
    OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    repo.adauga(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.getAll().size()==1);
    repo.adauga(Oferta("Plaja", "Mamaia", "-", 400));
    repo.adauga(Oferta("Munte", "Sinaia", "all-inclusive", 1234));
    vector<Oferta> listaFiltrata1 = service.filtrarePret(2000);
    assert(listaFiltrata1.size()==2);
    assert(listaFiltrata1.at(0).getPret()==400);
    assert(listaFiltrata1.at(1).getPret()==1234);
    vector<Oferta> listaFiltrata2 = service.filtrarePret(10);
    assert(typeid(service.filtrarePret(100))== typeid(vector<Oferta>));
    assert(listaFiltrata2.empty());
}

void test_sortareOferte() {
    OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    service.adaugaOferta("a", "b", "csc", 100);
    service.adaugaOferta("sa", "a", "c", 50);
    service.adaugaOferta("t", "y", "c", 63);
    service.adaugaOferta("o", "xc", "m", 100);

    auto list = service.sortByDenumire();
    auto list2 = service.sortByDestinatie();
    auto list3 = service.sortByTipSiPret();

    assert(list.size() == 4);
    assert(list.at(0).getDenumire() == "a");
    assert(list.at(3).getDenumire() == "t");

    assert(list2.size() == 4);
    assert(list2.at(1).getDenumire() == "a");
    assert(list2.at(2).getDenumire() == "o");

    assert(list3.size() == 4);
    assert(list3.at(0).getDenumire() == "sa");
    assert(list3.at(1).getDenumire() == "t");

    assert(typeid(service.sortByDenumire())== typeid(vector<Oferta>));
    assert(typeid(service.sortByTipSiPret())== typeid(vector<Oferta>));
    assert(typeid(service.sortByDestinatie())== typeid(vector<Oferta>));
}

void test_raport() {
    OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    service.adaugaOferta("a", "b", "csc", 100);
    service.adaugaOferta("sa", "a", "c", 50);
    service.adaugaOferta("t", "y", "c", 63);
    service.adaugaOferta("o", "xc", "m", 100);
    service.adaugaOferta("lolo", "a", "c", 50);

    auto map = service.frecventeDestinatie();
    assert(map.size()==4);
}

void test_undo() {
    OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    try {
        service.undo();
    } catch (Exception ex) {
        assert(true);
    }
    service.adaugaOferta("unu", "a", "lala", 6789);
    service.adaugaOferta("doi", "b", "baab", 1022);
    service.modificaOferta("unu", "a", "lolo", 456);
    service.stergereOferta("doi", "b");
    service.undo();
    assert(service.getAll().size()==2);
    auto oferta = repo.cauta("unu", "a");
    service.undo();
    service.undo();
    try {
        repo.cauta("doi", "b");
    } catch (OfertaRepoException ex) {
        assert(true);
    }
    service.undo();
    assert(service.getAll().empty());
}

void test_cos() {
    OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    service.adaugaOferta("a", "b", "csc", 100);
    service.adaugaOferta("sa", "a", "c", 50);
    service.adaugaOferta("t", "y", "c", 63);
    service.adaugaOferta("o", "xc", "m", 100);
    service.cosAdauga("a", "b");
    assert(service.getAllCos().size()==1);
    try {
        service.cosAdauga("aaaa", "aaaa");
    } catch (OfertaRepoException& ex) {
        assert(true);
    }
    assert(service.getAllCos().size()==1);
    service.cosSterge();
    service.cosAdaugaRandom(3);
    assert(service.getAllCos().size()==3);

    // test export
    string fisier_csv = "/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Laborator/Lab8-9/Agentie de turism/test.csv";
    string fisier_html = "/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Laborator/Lab8-9/Agentie de turism/test.html";
    string fisier_alt = "/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Laborator/Lab8-9/Agentie de turism/test.txt";
    service.cosExport(fisier_csv);
    service.cosExport(fisier_html);
    try {
        service.cosExport(fisier_alt);
    } catch (Exception exception) {
        assert(exception.getMessage()=="Fisierul nu este valid!");
        assert(true);
    }

}

void test_all() {
    // Teste REPOSITORY
    test_adauga();
    test_cauta();
    test_stergere();
    // Teste SERVICE
    // - service oferte
    test_getAll();
    test_adaugaOferta();
    test_modificaOferta();
    test_stergeOferta();
    test_filtrareDestinatie();
    test_filtrarePret();
    test_sortareOferte();
    test_raport();
    test_undo();
    // - service wishlist
    test_cos();

}