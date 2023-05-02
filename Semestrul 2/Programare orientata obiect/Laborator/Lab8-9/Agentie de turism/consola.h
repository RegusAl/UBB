#pragma once
#include "AgentieService.h"
#include "Oferta.h"
#include <vector>


class Consola {
    AgentieService& service;
    void adaugaUI();
    static void afisareUI(vector<Oferta> oferte);
    void modificaUI();
    void stergereUI();
    void filtrareDestinatieUI();
    void filtrarePretUI();
    void sortare();

public:
    explicit Consola(AgentieService& service): service{service}{}
    Consola(const Consola& ot) = delete;

    void run();
};
