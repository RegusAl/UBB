#pragma once

#include "string"
#include "vector"

using namespace std;

class Task {
private:
    int id;
    string descriere;
    vector<string> programatori;
    string stare;
public:
    Task(int id, string descriere, vector<string> programatori, string stare) : id(id), descriere(descriere), programatori(programatori), stare(stare) {}

    int get_id() {
        return id;
    }

    string get_descriere() {
        return  descriere;
    }

    vector<string> get_programatori() {
        return programatori;
    }

    string get_stare() {
        return stare;
    }
};