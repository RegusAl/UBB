#include "Oferta.h"
#include "OfertaRepo.h"

class ActiuneUndo {
public:
    virtual void doUndo() = 0;
    virtual ~ActiuneUndo(){};
};

class UndoAdauga : public ActiuneUndo {
    Oferta ofertaAdaugata;
    OfertaRepo& Repo;
public:
    UndoAdauga(OfertaRepo& repo, const Oferta& o): Repo{repo}, ofertaAdaugata{o} {}
    void doUndo() override {
        Repo.stergere(ofertaAdaugata);
    }
};

class UndoModifica : public ActiuneUndo {
    Oferta ofertaVeche, ofertaNoua;
    OfertaRepo& Repo;
public:
    UndoModifica(OfertaRepo& repo, Oferta& ofertaVeche, Oferta& ofertaNoua): Repo{repo}, ofertaVeche{ofertaVeche}, ofertaNoua{ofertaNoua} {}
    void doUndo() override {
        Repo.stergere(ofertaNoua);
        Repo.adauga(ofertaVeche);
    }
};

class UndoSterge : public ActiuneUndo {
    Oferta ofertaStearsa;
    OfertaRepo& Repo;
public:
    UndoSterge(OfertaRepo& repo, Oferta& ofertaStearsa): Repo{repo}, ofertaStearsa{ofertaStearsa} {}
    void doUndo() override {
        Repo.adauga(ofertaStearsa);
    }
};