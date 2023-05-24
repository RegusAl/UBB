#pragma once

#include "device.h"
#include "repository.h"

class Service {
private:
    Repository &repo;
public:

    Service(class Repository &repo) : repo{repo} {};
    Service() = delete;
    Service(const Service &s) = delete;

    vector<Device> &getAll() {
        return repo.getAll();
    }

    vector<Device> sortareModel();

    vector<Device> sortarePret();
};