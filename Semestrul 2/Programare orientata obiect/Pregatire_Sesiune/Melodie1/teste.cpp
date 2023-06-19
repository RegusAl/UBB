#pragma once
#include "teste.h"
#include <iostream>
#include <qdebug.h>

void test_domain() {
    Melodie m(1, "abc", "ex", 8);
    assert(m.get_id()==1);
    assert(m.get_titlu()=="abc");
    assert(m.get_artist()=="ex");
    assert(m.get_rank()==8);
}

void test_repo() {
    Repo repo{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/Melodie1/test.txt"};
    assert(repo.getAll().size()==6);
    repo.modifica(6, "kpap", 8);
    assert(repo.getAll().size()==6);
    repo.save_to_file(repo.getAll());
//    qDebug()<<repo.getAll().at(3).get_rank();
    assert(repo.getAll().at(3).get_rank()==7);
    auto lista = repo.getAll();
    repo.sterge(1);
    assert(repo.getAll().size()==5);
    repo.save_to_file(lista);
}

void test_service() {
    Repo repo{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/Melodie1/test.txt"};
    Service service{repo};
    auto lista = repo.getAll();
    service.modificare_rank(5, "xyz", 10);
    try {
        service.modificare_rank(5, "aaa", 100);
    }
    catch(exception&) {
        assert(true);
    }
    try {
        service.sterge(2);
    }
    catch(exception&) {
        assert(true);
    }
    assert(repo.getAll().at(5).get_rank()==10);
    service.sterge(1);
    assert(service.getAll().size()==5);
    repo.save_to_file(lista);
}