#pragma once

#include <algorithm>
#include "repository.h"
#include "iostream"

class Service {
private:
    Repository& repository;
public:
    Service(Repository& repository) : repository(repository) {}

    vector<Task> getAll() {
        /*
         * Returneaza un vector de taskuri ce contin toate taskurile
         * : return - taskurile sortate
         */
        return sortare(repository.getAll());
    }

    vector<Task> sortare(vector<Task> taskuri) {
        /*
         * Sorteaza lista de taskuri primita ca parametru
         * : param taskuri - lista de taskuri
         * : return lista de taskuri sortate
         */
        sort(taskuri.begin(), taskuri.end(), [](Task t1, Task t2) {
            if(t1.get_stare() == "open" && (t2.get_stare() == "inprogress" || t2.get_stare() == "closed" || t2.get_stare() == "open")) {
                return 1;
            } else if(t1.get_stare() == "inprogress" && (t2.get_stare() == "closed" || t2.get_stare() == "inprogress")) {
                return 1;
            } else
                 return 0;

        });
        return taskuri;
    }

    void adaugare(int id, string descriere, string prog, string stare);
    /*
     * Adauga un obiect de tip Task cu atributele primite ca parametri
     * : param id - id-ul taskului (int)
     * : param descriere - descrierea taskului (string)
     * : param prog - string de programatori
     * : param stare - starea taskului (string)
     * : throw - exception : - daca id-ul este folosit
     *                       - daca descrierea sau starea este vida
     *                       - daca nu sunt intre 1 - 4 programatori
     *                       - daca starea nu este 'open', 'inprogress', 'closed'
     *
     */

    vector<Task> filtrare(string s);
    /*
     * Filtreaza din  lista de taskuri, taskurile a caror nume a programatorilor contine strinul primit ca parametru
     * : param s - stringul ce se cauta in numele programatorilor
     * : return lista de taskuri filtrate;
     */
};