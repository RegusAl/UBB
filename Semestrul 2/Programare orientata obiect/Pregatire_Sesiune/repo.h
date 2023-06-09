#pragma once

#include "domain.h"
#include "vector"

using namespace std;

class Repo {
private:
    vector<Melodie> m;
    string filename;
    void load_from_file();
public:
    Repo(const Repo &ot) = delete;
    Repo(string filename) : filename(filename) {
        load_from_file();
    }

    void save_to_file(vector<Melodie> lista);
    vector<Melodie> getAll() {
        return m;
    }

    void modifica(int id, string titlu, int rank);

    void sterge(int id);


};