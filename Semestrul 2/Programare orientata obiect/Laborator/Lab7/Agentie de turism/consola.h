#pragma once
#include "AgentieService.h"
#include "VectorDinamic.h"
#include "Oferta.h"

class Consola {
    AgentieService& service;
    void adaugaUI();
    static void afisareUI(VectorDinamic<Oferta> oferte);
    void modificaUI();
    void stergereUI();
    void filtrareDestinatieUI();
    void filtrarePretUI();

public:
    explicit Consola(AgentieService& service): service{service}{}
    Consola(const Consola& ot) = delete;

    void run();
};
