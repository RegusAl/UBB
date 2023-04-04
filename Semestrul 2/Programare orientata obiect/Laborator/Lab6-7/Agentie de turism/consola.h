#pragma once
#include "AgentieService.h"
#include "Oferta.h"

class Consola {
    AgentieService& service;
    void adaugaUI();
    void afisareUI();
public:
    Consola(AgentieService& service): service{service} {}
    Consola(const Consola& ot) = delete;

    void run();
};
