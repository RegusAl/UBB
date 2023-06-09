#pragma once
#include <qwidget.h>
#include <qtimer.h>
#include <QtWidgets/QHBoxLayout>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <qtablewidget.h>
#include <qstring.h>
#include <qlabel.h>
#include <vector>
#include "Cos_Oferte.h"
#include "observer.h"

class CosGUILista : public QWidget, public Observer {
private:
	CosOferte& cos;
	QListWidget* lst;
	QPushButton* btn;
	QPushButton* btnRandom;
	void loadList(const std::vector<Oferta>& of) {
		lst->clear();
		for (auto& p : of) {
			auto item = new QListWidgetItem(
				QString::fromStdString(
					p.getDenumire() + " "
					+ p.getDestinatie() + " "
					+ p.getTip() + " "
					+ std::to_string(p.getPret()
					)));
			lst->addItem(item);
		}
	}
	void initGUI() {
		QVBoxLayout* ly = new QVBoxLayout;
		lst = new QListWidget;
		ly->addWidget(lst);
		btn = new QPushButton("Clear cos");
		ly->addWidget(btn);

		btnRandom = new QPushButton("Genereaza 3 oferte");
		ly->addWidget(btnRandom);
		setLayout(ly);
	}
	void connectSignals() {
		cos.addObserver(this);
		QObject::connect(btn, &QPushButton::clicked, [&]() {
			cos.emptyCos();
			loadList(cos.getAllOferteCos());
			});
		QObject::connect(btnRandom, &QPushButton::clicked, [&]() {
			cos.umple(3);
			loadList(cos.getAllOferteCos());
			});

	}
public:
	CosGUILista(CosOferte& cos) :cos{ cos } {
		initGUI();
		connectSignals();
		loadList(cos.getAllOferteCos());
	}

	void update() override {
		loadList(cos.getAllOferteCos());
	}
	~CosGUILista() {
		cos.removeObserver(this);
	}

};