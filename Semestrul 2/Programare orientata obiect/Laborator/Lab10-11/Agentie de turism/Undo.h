#include "Oferta.h"
#include "OfertaRepo.h"

class ActiuneUndo {
public:
    virtual void doUndo() = 0;

    virtual ~ActiuneUndo() {};
};

class UndoAdauga : public ActiuneUndo {
    Oferta ofertaAdaugata;
    RepoAbstract &Repo;
public:
    UndoAdauga(RepoAbstract &repo, const Oferta &o) : Repo{repo}, ofertaAdaugata{o} {}

    void doUndo() override {
        Repo.stergere(ofertaAdaugata);
    }
};


class UndoModifica : public ActiuneUndo {
    Oferta ofertaVeche, ofertaNoua;
    RepoAbstract &Repo;
public:
    UndoModifica(RepoAbstract &repo, Oferta &ofertaVeche, Oferta &ofertaNoua) : Repo{repo}, ofertaVeche{ofertaVeche},
                                                                              ofertaNoua{ofertaNoua} {}

    void doUndo() override {
        Repo.stergere(ofertaNoua);
        Repo.adauga(ofertaVeche);
    }
};

class UndoSterge : public ActiuneUndo {
    Oferta ofertaStearsa;
    RepoAbstract &Repo;
public:
    UndoSterge(RepoAbstract &repo, Oferta &ofertaStearsa) : Repo{repo}, ofertaStearsa{ofertaStearsa} {}

    void doUndo() override {
        Repo.adauga(ofertaStearsa);
    }
};