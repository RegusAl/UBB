#pragma once
#include "repo.h"

#include <functional>
#include <algorithm>

class Service {
private:
    Repo& repo;
public:
    Service(Repo& repo) : repo(repo) {};

    vector<Melodie>sortare(vector<Melodie> melodii);

    vector<Melodie>getAll() {
        return sortare(repo.getAll());
    }

    void modificare_rank(int id, string titlu, int rank);

    void sterge(int id);

    vector<int> rank_fr();

};