#pragma once

#include "string"

using namespace std;

class Melodie {
private :
    int id;
    string titlu, artist, gen;
public:
    Melodie(int id, string titlu, string artist, string gen) : id{id}, titlu{titlu}, artist(artist), gen(gen) {};

    int get_id() {
        return id;
    }

    string get_titlu() {
        return titlu;
    }

    string get_artist() {
        return artist;
    }

    string get_gen() {
        return gen;
    }

};