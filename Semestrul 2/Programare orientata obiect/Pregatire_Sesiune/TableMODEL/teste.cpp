
#include "teste.h"

void test_repository() {
    Repository repo{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/TableMODEL/testfile.txt"};
    assert(repo.getAll().size()==4);
    auto entitate1 = repo.getAll().at(0);
    assert(entitate1.getId()==1);
    assert(entitate1.getNume()=="entitate1");
    assert(entitate1.getTip()=="tip1");
    auto lista = repo.getAll();
    auto listaNoua = repo.getAll();
    repo.adaugare(Entitate(44,"nuj","ex"));
    assert(repo.getAll().size()==5);
    repo.stergere(Entitate(1,"entitate1","tip1"));
    assert(repo.getAll().size()==4);
    repo.stergere(Entitate(44,"nuj","ex"));
    assert(repo.getAll().size()==3);
    repo.saveToFile(lista);
}

void test_service() {
    Repository repo{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/TableMODEL/testfile.txt"};
    Service service{repo};
    assert(service.getAll().size()==4);
    auto lista = service.getAll();
    // test adaugare
    service.adaugare(12,"nuj","nuj");
    assert(service.getAll().size()==5);
    // test stergere
    service.stergere(12,"nuj","nuj");
    assert(service.getAll().size()==4);
    repo.saveToFile(lista);
}
