#pragma once
#include "teste.h"

#include "iostream"

void test_repository() {
    Repository repository{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/App/inputTest.txt"};
    assert(repository.getAll().size() == 2);
    auto lista = repository.getAll();
    auto lista2 = repository.getAll();
    Produs p(23,"hhhhhhh","pppppp",90);
    lista2.push_back(p);
    cout<<lista2.size();
    repository.saveToFile(lista2);
    repository.adaugare(Produs(12, "lala", "lala", 67));
    std::cout<<repository.getAll().size();
    assert(repository.getAll().size()==3);
    repository.saveToFile(lista);
//    assert(repository.getAll().size()==2);
}

void test_service() {
    Repository repository{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/App/inputTest.txt"};
    Service service{repository};

    assert(service.getAll().size()==2);
}