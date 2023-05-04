#pragma once
#include "AgentieService.h"
#include "Oferta.h"
#include <vector>


class Consola {
    AgentieService& service;
    void adaugaUI();
    static void afisareUI(const vector<Oferta>& oferte);
    void modificaUI();
    void stergereUI();
    void filtrareDestinatieUI();
    void filtrarePretUI();
    void sortare();
    void raportUI();

    void cosAdaugaUI();
    void cosAdaugaRandomUI();
    void cosStergeUI();
//    void cosExportUI();

    void MeniuCos();

public:
    explicit Consola(AgentieService& service): service{service}{}
    Consola(const Consola& ot) = delete;

    void run();
};
