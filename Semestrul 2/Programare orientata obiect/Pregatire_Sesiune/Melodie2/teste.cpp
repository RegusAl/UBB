#pragma once
#include "teste.h"

void test_repo() {
    Repository repo{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/Melodie2/fisiertext.txt"};
    auto lista = repo.getAll();
    assert(lista.size() == 4);
    assert(lista.at(0).get_id()==1);
    assert(lista.at(0).get_artist()=="Iron Maiden");
    assert(lista.at(0).get_titlu()=="Fear of the dark");
    assert(lista.at(0).get_gen()=="rock");
}

void test_service() {
    Repository repo{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/Melodie2/fisiertext.txt"};
    Service service(repo);
    auto lista = service.getAll();
    assert(lista.size()==4);
}