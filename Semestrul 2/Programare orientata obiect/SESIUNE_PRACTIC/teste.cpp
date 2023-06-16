#pragma once
#include "iostream"
#include "teste.h"
#include "assert.h"

void test_repository() {
    Repository repo{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/SESIUNE_PRACTIC/fileTests.txt"};
    assert(repo.getAll().size()==4);
    auto task1 = repo.getAll().at(0);
    assert(task1.get_programatori().size()==2);
//    for(auto &el : task1.get_programatori())
//        cout<<el<<endl;
    auto taskuri = repo.getAll();
    repo.saveToFile(taskuri);
    assert(task1.get_programatori().size()==2);
}

void test_service() {
    Repository repo{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/SESIUNE_PRACTIC/fileTests.txt"};
    Service service{repo};
    auto listaInitiala = repo.getAll();
    assert(service.getAll().size()==4);
//    for(auto &el : service.getAll()) {
//        cout<<el.get_id()<<endl;
//    }
    service.adaugare(12,"qqqq","aa bb cc", "closed");
    try {
        service.adaugare(99,"","aa bb cc", "closed");
    } catch (exception&) {
        assert(true);
    }
    try {
        service.adaugare(99,"blabla","aa bb cc", "altceva");
        assert(false);
    } catch (exception&) {
        assert(true);
    }
    try {
        service.adaugare(1,"blabla","aa bb cc", "closed");
        assert(false);
    } catch (exception&) {
        assert(true);
    }
    try {
        service.adaugare(123456,"blabla","aa bb cc dde ttyu", "closed");
        assert(false);
    } catch (exception&) {
        assert(true);
    }
    repo.saveToFile(listaInitiala);
//    for(auto &el : service.getAll()) {
//        for(auto &prog : el.get_programatori()) {
//            cout<<prog<<" ";
//        }
//        cout<<endl;
//    }
    auto listaNoua = service.filtrare("i");
    for(auto &el : listaNoua) {
        cout<<el.get_id();
    }
    cout<<listaNoua.size();
    assert(listaNoua.size()==1);
    assert(service.filtrare("su").size() !=0);
}
