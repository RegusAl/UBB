#pragma once

#include "domain.h"

class Repository {
private:
    string fileName;
    vector<Task> all;
    void loadFromFile();
public:
    Repository(string fileName) : fileName(fileName) {
        loadFromFile();
    }

    vector<Task> getAll() {
        /*
         * Returneaza toate vectorul de taskuri all
         */
        return all;
    }

    void saveToFile(vector<Task> taskuri);
    /*
     * Salveaza vectorul de tascuri primit ca parametru in fisier
     * : param taskuri - lista de taskuri
     */

    void adaugare(Task t);
    /*
     * Adauga un task primit ca parametru in vectorul de taskuri
     * : param t - Task
     */

};