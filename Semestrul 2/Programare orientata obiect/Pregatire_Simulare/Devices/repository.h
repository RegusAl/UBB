#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "device.h"

class Repository {
private:
    std::string fileName;
    vector<Device> all;
    void loadFromFile();
public:
    Repository() = default;
    Repository(const Repository &r) = delete;

    Repository(std::string fileName) : fileName{fileName} {
        loadFromFile();
    }

    vector<Device> &getAll() {
        return all;
    }
};