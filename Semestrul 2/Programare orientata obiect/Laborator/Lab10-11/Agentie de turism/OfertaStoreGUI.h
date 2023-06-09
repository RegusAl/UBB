#pragma once
#include <vector>
#include <string>
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QHeaderView>
#include <QGroupBox>
#include <QRadioButton>
#include <qlistwidget.h>
#include <QStringList>
#include "AgentieService.h"

using std::vector;
using std::string;
class OfertaStoreGUI : public QWidget {
private:

	AgentieService& srv;

	QLabel* lblDenumire = new QLabel{ "Denumire oferta:" };
	QLabel* lblDestinatie = new QLabel{ "Destinatie oferta:" };
    QLabel* lblTip = new QLabel{"Tipul ofertei:"};
    QLabel* lblPret = new QLabel{ "Pret oferta:" };

	QLineEdit* editDenumire;
	QLineEdit* editDestinatie;
	QLineEdit* editTip;
	QLineEdit* editPret;

	QPushButton* btnAddOferta;
	QPushButton* btnModifyOferta;
	QPushButton* btnDeleteOferta;

	QGroupBox* groupBox = new QGroupBox(tr("Tip sortare"));

	QRadioButton* radioSrtDenumire = new QRadioButton(QString::fromStdString("Denumire"));
	QRadioButton* radioSrtDestinatue = new QRadioButton(QString::fromStdString("Destinatie"));
	QRadioButton* radioSrtTipPret = new QRadioButton(QString::fromStdString("Tip+Pret"));
	QPushButton* btnSortOferte;

	QLabel* lblFilterCriteria = new QLabel{ "Pretul dupa care se filtreaza:" };
	QLineEdit* editFilterPret;
	QPushButton* btnFilterOferte1;

	QLabel* lblFilterCriteria2 = new QLabel{ "Destinatie dupa care se filtreaza:" };
	QLineEdit* editFilterDestinatie;
	QPushButton* btnFilterOferte2;

	QPushButton* btnReloadData;

	QPushButton* btnAllInclusive;
	QPushButton* btnCityBreak;
	QPushButton* btnHiking;
	QPushButton* btnMultiCountry;
	QPushButton* btnAltele;

	QPushButton* btnUndo;

    // pentru tabel
	QTableWidget* tableOferta;
    // pentru lista
    QListWidget* listaOferte;

    QPushButton* btnCos;
//    QWidget* fereastraCos;
    QPushButton* adaugaCos;
    QLineEdit* denumireOfertaCos;
    QLineEdit* destinatieOfertaCos;
    QPushButton* adaugaRandomCos;
    QLineEdit* numarRandom;
    QPushButton* golesteCos;
    QListWidget* listaCos;
    QLineEdit* editExport;
    QPushButton* exportCos;
    QLabel* lblRandom = new QLabel{"Numar oferte random:"};
    QLabel* lblExport = new QLabel{"Nume fisier:"};

	void initializeGUIComponents();

	void connectSignalsSlots();
	void reloadOfertaList(vector<Oferta> oferte);
    void reloadOfertaCosList(vector<Oferta> oferte);
public:
	OfertaStoreGUI(AgentieService& ofSrv) : srv{ ofSrv } {
		initializeGUIComponents();
		connectSignalsSlots();
		reloadOfertaList(srv.getAll());
	}
	void guiAddOferta();
	void guiModifyOferta();
	void guiDeleteOferta();
};