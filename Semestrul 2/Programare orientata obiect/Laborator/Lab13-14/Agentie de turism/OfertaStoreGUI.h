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
#include "Service.h"
#include "CosCRUDGUI.h"
#include "CosReadOnlyGUI.h"

using std::vector;
using std::string;
class OfertaStoreGUI : public QWidget {
private:

	OfertaStore& srv;

	QListView* lstV;
	QTableView* tblV = new QTableView;

	QLabel* lblDenumire = new QLabel{ "Denumire oferta:" };
	QLabel* lblDestinatie = new QLabel{ "Destinatie oferta:" };
	QLabel* lblTip = new QLabel{ "Tip oferta:" };
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
	QPushButton* btnCroaziere;
	QPushButton* btnMultiCountry;
	QPushButton* btnAltele;

	QPushButton* btnUndo;

	QTableWidget* tableOferta;
	QListWidget* listaOferte;
	QPushButton* btnCos;
	QWidget* fereastra_cos;
	QPushButton* addCos;
	QLineEdit* denumireOferta;
	QPushButton* addRandomCos;
	QLineEdit* editRandom;
	QPushButton* golesteCos;
	QListWidget* listaCos;
	QLineEdit* editExport;
	QPushButton* exportCos;
	QLabel* lblRandom = new QLabel{ "Nr oferte random: " };
	QLabel* lblDenumireCos = new QLabel{ "Denumire oferta: " };
	QLabel* lblExport = new QLabel{ "Nume fisier: " };

	QPushButton* btnCosCRUGUI;
	QPushButton* btnCosReadOnlyGUI;

	CosGUILista* fereastraCos;
	HistogramGUI* fereastraFiguri;

	QPushButton* btnAddCos;
	QPushButton* btnDeleteCos;
	QPushButton* btnRandomCos;

	void initializeGUIComponents();

	void connectSignalsSlots();
	void reloadOfertaList(vector<Oferta> oferte);
	void reloadOfertaCosList(vector<Oferta> oferte);
public:
	OfertaStoreGUI(OfertaStore& ofSrv) : srv{ ofSrv } {
		initializeGUIComponents();
		connectSignalsSlots();
		reloadOfertaList(srv.getAllOferte());
	}
	int getSelectedIndex() {
		auto currentIndex = this->listaOferte->selectionModel()->currentIndex();
		return currentIndex.row();
	}
	void guiAddOferta();
	void guiModifyOferta();
	void guiDeleteOferta();
};