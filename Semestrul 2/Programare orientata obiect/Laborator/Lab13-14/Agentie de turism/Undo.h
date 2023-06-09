#include "oferta.h"
#include "Repo.h"

class ActiuneUndo {
public:
	virtual void doUndo() = 0;
	//destructorul e virtual pentru a ne asigura ca daca dau delete pe un pointer, se apeleleaza destructorul din clasa care trebuie
	virtual ~ActiuneUndo() {};
};

class UndoAdauga : public ActiuneUndo {
	Oferta ofAdaugat;
	OfertaRepo& repo;
public:
	UndoAdauga(OfertaRepo& repo, const Oferta& m) :repo{ repo }, ofAdaugat{ m } {}
	void doUndo() override {
		repo.delete_of(ofAdaugat.getDenumire());
	}
};

class UndoSterge : public ActiuneUndo {
	Oferta ofSters;
	OfertaRepo& repo;
public:
	UndoSterge(OfertaRepo& repo, Oferta& ofSters) :repo{ repo }, ofSters{ ofSters } {}
	void doUndo() override {
		repo.store(ofSters);
	}
};

class UndoModify : public ActiuneUndo {
	Oferta oldOF, newOF;
	OfertaRepo& repo;
public:
	UndoModify(OfertaRepo& repo, Oferta& oldOF, Oferta& newOF) :repo{ repo }, oldOF{ oldOF }, newOF{ newOF } {}
	void doUndo() override {
		repo.delete_of(newOF.getDenumire());
		repo.store(oldOF);
	}
};