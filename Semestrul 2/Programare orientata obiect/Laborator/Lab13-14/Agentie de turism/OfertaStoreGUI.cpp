#include "OfertaStoreGUI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OfertaStoreGUI::initializeGUIComponents()
{
	//main layout
	QHBoxLayout* lyMain = new QHBoxLayout;
	this->setLayout(lyMain);


	//left part of the window, pentru care setam layout vertical
	QWidget* left = new QWidget;
	QVBoxLayout* lyLeft = new QVBoxLayout;
	left->setLayout(lyLeft);

	QWidget* form = new QWidget;
	QFormLayout* lyForm = new QFormLayout;
	form->setLayout(lyForm);
	editDenumire = new QLineEdit;
	editDestinatie = new QLineEdit;
	editTip = new QLineEdit;
	editPret = new QLineEdit;

	lyForm->addRow(lblDenumire, editDenumire);
	lyForm->addRow(lblDestinatie, editDestinatie);
	lyForm->addRow(lblTip, editTip);
	lyForm->addRow(lblPret, editPret);
	btnAddOferta = new QPushButton("Adauga oferta");
	lyForm->addWidget(btnAddOferta);
	btnModifyOferta = new QPushButton("Modifica oferta");
	lyForm->addWidget(btnModifyOferta);
	btnDeleteOferta = new QPushButton("Delete oferta");
	lyForm->addWidget(btnDeleteOferta);

	//adaugam toate componentele legate de adaugare oferta in layout-ul care corespunde partii din stanga a ferestrei
	lyLeft->addWidget(form);



	//cream un GroupBox pentru radiobuttons care corespund criteriilor de sortare pe care le avem (dupa denumire, destinatie, tip+pret) + butonul de sortare
	QVBoxLayout* lyRadioBox = new QVBoxLayout;
	this->groupBox->setLayout(lyRadioBox);
	lyRadioBox->addWidget(radioSrtDenumire);
	lyRadioBox->addWidget(radioSrtDestinatue);
	lyRadioBox->addWidget(radioSrtTipPret);

	btnSortOferte = new QPushButton("Sorteaza oferte");
	lyRadioBox->addWidget(btnSortOferte);

	//adaugam acest grup in partea stanga, dupa componentele pentru adaugare in layout-ul vertical
	lyLeft->addWidget(groupBox);

	//cream un form pentru filtrari
	QWidget* formFilter = new QWidget;
	QFormLayout* lyFormFilter = new QFormLayout;
	formFilter->setLayout(lyFormFilter);

	editFilterPret = new QLineEdit();
	lyFormFilter->addRow(lblFilterCriteria, editFilterPret);
	btnFilterOferte1 = new QPushButton("Filtreaza oferte dupa pret");
	lyFormFilter->addWidget(btnFilterOferte1);

	editFilterDestinatie = new QLineEdit();
	lyFormFilter->addRow(lblFilterCriteria2, editFilterDestinatie);
	btnFilterOferte2 = new QPushButton("Filtreaza oferte dupa destinatie");
	lyFormFilter->addWidget(btnFilterOferte2);

	lyLeft->addWidget(formFilter);

	//Buton folosit pentru a reincarca datele; afisam toate oferte in tabel, in ordinea initiala din fisier
	btnReloadData = new QPushButton("Reload data");
	lyLeft->addWidget(btnReloadData);

	btnAllInclusive = new QPushButton("AllInclusive");
	btnCityBreak = new QPushButton("CityBreak");
	btnCroaziere = new QPushButton("Croaziere");
	btnMultiCountry = new QPushButton("MultiCountry");
	btnAltele = new QPushButton("Altele");
	lyLeft->addWidget(btnAllInclusive);
	lyLeft->addWidget(btnCityBreak);
	lyLeft->addWidget(btnCroaziere);
	lyLeft->addWidget(btnMultiCountry);
	lyLeft->addWidget(btnAltele);

	int cnt = 0;
	for (int i = 0; i < srv.getAllOferte().size(); i++)
		if (srv.getAllOferte().at(i).getTip() == "AllInclusive")
			cnt++;
	if (cnt == 0)
		btnAllInclusive->setVisible(false);

	cnt = 0;
	for (int i = 0; i < srv.getAllOferte().size(); i++)
		if (srv.getAllOferte().at(i).getTip() == "CityBreak")
			cnt++;
	if (cnt == 0)
		btnCityBreak->setVisible(false);

	cnt = 0;
	for (int i = 0; i < srv.getAllOferte().size(); i++)
		if (srv.getAllOferte().at(i).getTip() == "Croaziere")
			cnt++;
	if (cnt == 0)
		btnCroaziere->setVisible(false);

	cnt = 0;
	for (int i = 0; i < srv.getAllOferte().size(); i++)
		if (srv.getAllOferte().at(i).getTip() == "MultiCountry")
			cnt++;
	if (cnt == 0)
		btnMultiCountry->setVisible(false);

	cnt = 0;
	for (int i = 0; i < srv.getAllOferte().size(); i++)
		if (srv.getAllOferte().at(i).getTip() == "Altele")
			cnt++;
	if (cnt == 0)
		btnAltele->setVisible(false);

	btnUndo = new QPushButton("Undo");
	lyLeft->addWidget(btnUndo);

	btnCos = new QPushButton("Cos");
	addCos = new QPushButton("Adauga oferta in cos");
	denumireOferta = new QLineEdit;
	addRandomCos = new QPushButton("Adauga oferte random in cos");
	editRandom = new QLineEdit;
	golesteCos = new QPushButton("Goleste cos");
	editExport = new QLineEdit;
	this->listaCos = new QListWidget();
	exportCos = new QPushButton("Export cos");

	btnCosCRUGUI = new QPushButton("CosCRUDGui");
	lyLeft->addWidget(btnCosCRUGUI);

	btnCosReadOnlyGUI = new QPushButton("CosReadOnlyGUI");
	lyLeft->addWidget(btnCosReadOnlyGUI);

	//componenta right - contine doar tabelul cu oferte
	QWidget* right = new QWidget;
	QVBoxLayout* lyRight = new QVBoxLayout;
	right->setLayout(lyRight);

	int noLines = 10;
	int noColumns = 4;
	this->tableOferta = new QTableWidget{ noLines, noColumns };

	//setam header-ul tabelului
	QStringList tblHeaderList;
	tblHeaderList << "Denumire" << "Destinatie" << "Tip" << "Pret";
	this->tableOferta->setHorizontalHeaderLabels(tblHeaderList);

	//optiune pentru a se redimensiona celulele din tabel in functie de continut
	this->tableOferta->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	lyRight->addWidget(tableOferta);

	this->listaOferte = new QListWidget();
	lyRight->addWidget(listaOferte);

	//lyRight->addWidget(btnCos);

	btnAddCos = new QPushButton("Adauga Oferta Cos");
	btnDeleteCos = new QPushButton("Sterge Oferta Cos");
	btnRandomCos = new QPushButton("Adauga Oferte Random Cos");
	lyRight->addWidget(btnAddCos);
	lyRight->addWidget(btnDeleteCos);
	lyRight->addWidget(btnRandomCos);

	lyMain->addWidget(left);
	lyMain->addWidget(right);
}

void OfertaStoreGUI::connectSignalsSlots()
{
	QObject::connect(btnAddOferta, &QPushButton::clicked, this, &OfertaStoreGUI::guiAddOferta);
	QObject::connect(btnModifyOferta, &QPushButton::clicked, this, &OfertaStoreGUI::guiModifyOferta);
	QObject::connect(btnDeleteOferta, &QPushButton::clicked, this, &OfertaStoreGUI::guiDeleteOferta);

	QObject::connect(btnUndo, &QPushButton::clicked, [&]() {
		try {
			this->srv.undo();
			this->reloadOfertaList(this->srv.getAllOferte());
			QMessageBox::information(this, "Info", QString::fromStdString("Undo realizat cu succes."));
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});


	QObject::connect(btnSortOferte, &QPushButton::clicked, [&]() {
		if (this->radioSrtDenumire->isChecked())
			this->reloadOfertaList(srv.sortByDenumire());
		else if(this->radioSrtDestinatue->isChecked())
			this->reloadOfertaList(srv.sortByDestinatie());
		else if(this->radioSrtTipPret->isChecked())
			this->reloadOfertaList(srv.sortByTipSiPret());
		});

	QObject::connect(btnFilterOferte1, &QPushButton::clicked, [&]() {
		string filterC = this->editFilterPret->text().toStdString();
		this->reloadOfertaList(srv.filtrarePret(stoi(filterC)));
		});

	QObject::connect(btnFilterOferte2, &QPushButton::clicked, [&]() {
		string filterC = this->editFilterDestinatie->text().toStdString();
		this->reloadOfertaList(srv.filtrareDest(filterC));
		});

	QObject::connect(btnReloadData, &QPushButton::clicked, [&]() {
		this->reloadOfertaList(srv.getAllOferte());
		});

	QObject::connect(btnAllInclusive, &QPushButton::clicked, [&]() {
		int cnt = 0;
		for (int i = 0; i < srv.getAllOferte().size(); i++)
			if (srv.getAllOferte().at(i).getTip() == "AllInclusive")
				cnt++;
		QMessageBox::information(this, "Info", QString::fromStdString("Nr oferte AllInclusive: %1").arg(cnt));
		});

	QObject::connect(btnCityBreak, &QPushButton::clicked, [&]() {
		int cnt = 0;
		for (int i = 0; i < srv.getAllOferte().size(); i++)
			if (srv.getAllOferte().at(i).getTip() == "CityBreak")
				cnt++;
		QMessageBox::information(this, "Info", QString::fromStdString("Nr oferte CityBreak: %1").arg(cnt));
		});
	
	QObject::connect(btnCroaziere, &QPushButton::clicked, [&]() {
		int cnt = 0;
		for (int i = 0; i < srv.getAllOferte().size(); i++)
			if (srv.getAllOferte().at(i).getTip() == "Croaziere")
				cnt++;
		QMessageBox::information(this, "Info", QString::fromStdString("Nr oferte Croaziere: %1").arg(cnt));
		});

	QObject::connect(btnMultiCountry, &QPushButton::clicked, [&]() {
		int cnt = 0;
		for (int i = 0; i < srv.getAllOferte().size(); i++)
			if (srv.getAllOferte().at(i).getTip() == "MultiCountry")
				cnt++;
		QMessageBox::information(this, "Info", QString::fromStdString("Nr oferte MultiCountry: %1").arg(cnt));
		});

	QObject::connect(btnAltele, &QPushButton::clicked, [&]() {
		int cnt = 0;
		for (int i = 0; i < srv.getAllOferte().size(); i++)
			if (srv.getAllOferte().at(i).getTip() == "Altele")
				cnt++;
		QMessageBox::information(this, "Info", QString::fromStdString("Nr oferte Altele: %1").arg(cnt));
		});


	QObject::connect(this->listaOferte, &QListWidget::itemSelectionChanged, [&]() {
		int index = this->getSelectedIndex();
		auto elements = this->srv.getAllOferte();
		if (index >= elements.size()) {
			this->editDenumire->clear();
			this->editDestinatie->clear();
			this->editTip->clear();
			this->editPret->clear();
			this->denumireOferta->clear();
			return;
		}
		auto element = elements.at(index);
		this->editDenumire->setText(QString::fromStdString(element.getDenumire()));
		this->denumireOferta->setText(QString::fromStdString(element.getDenumire()));
		this->editDestinatie->setText(QString::fromStdString(element.getDestinatie()));
		this->editTip->setText(QString::fromStdString(element.getTip()));
		this->editPret->setText(QString::fromStdString(std::to_string(element.getPret())));
		});

	QObject::connect(this->tableOferta, &QTableWidget::itemClicked, [&]() {
		auto currentIndex = this->tableOferta->selectionModel()->currentIndex();
		int index = currentIndex.row();
		auto elements = this->srv.getAllOferte();
		if (index >= elements.size()) {
			this->editDenumire->clear();
			this->editDestinatie->clear();
			this->editTip->clear();
			this->editPret->clear();
			this->denumireOferta->clear();
			return;
		}
		auto element = elements.at(index);
		this->editDenumire->setText(QString::fromStdString(element.getDenumire()));
		this->denumireOferta->setText(QString::fromStdString(element.getDenumire()));
		this->editDestinatie->setText(QString::fromStdString(element.getDestinatie()));
		this->editTip->setText(QString::fromStdString(element.getTip()));
		this->editPret->setText(QString::fromStdString(std::to_string(element.getPret())));
		});
	
	QObject::connect(btnCos, & QPushButton::clicked, [&]() {
		QWidget* fereastra_cos = new QWidget;
		QFormLayout* lycos = new QFormLayout;
		fereastra_cos->setLayout(lycos);
		//	lycos->addWidget(listaOferte);
		denumireOferta = new QLineEdit;
		lycos->addRow(lblDenumireCos, denumireOferta);
		lycos->addWidget(addCos);
		editRandom = new QLineEdit;
		lycos->addRow(lblRandom, editRandom);
		lycos->addWidget(addRandomCos);
		lycos->addWidget(golesteCos);
		editExport = new QLineEdit;
		lycos->addRow(lblExport, editExport);
		lycos->addWidget(exportCos);
		lycos->addWidget(listaCos);
		fereastra_cos->show();
		});

	QObject::connect(addCos, &QPushButton::clicked, [&]() {
		try {
			string denumire = denumireOferta->text().toStdString();
			denumireOferta->clear();
			this->srv.addToCos(denumire);
			QMessageBox::information(this, "Info", QString::fromStdString("Oferta adaugata cu succes."));
			this->reloadOfertaCosList(this->srv.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(btnAddCos, &QPushButton::clicked, [&]() {
		try {
			string denumire = denumireOferta->text().toStdString();
			denumireOferta->clear();
			this->srv.addToCos(denumire);
			QMessageBox::information(this, "Info", QString::fromStdString("Oferta adaugata cu succes."));
			this->reloadOfertaCosList(this->srv.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(btnDeleteCos, &QPushButton::clicked, [&]() {
		try {
			string denumire = denumireOferta->text().toStdString();
			denumireOferta->clear();
			this->srv.sterge_of(denumire);
			QMessageBox::information(this, "Info", QString::fromStdString("Oferta stearsa cu succes."));
			this->reloadOfertaCosList(this->srv.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(addRandomCos, &QPushButton::clicked, [&]() {
		try {
			int nr = editRandom->text().toInt();
			editRandom->clear();
			int numar = this->srv.getAllOferteCos().size();
			int of = this->srv.addRandomToCos(nr);
			QMessageBox::information(this, "Info", QString::fromStdString("%1 oferte adaugate").arg(of - numar));
			this->reloadOfertaCosList(this->srv.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(btnRandomCos, &QPushButton::clicked, [&]() {
		try {
			int nr = editRandom->text().toInt();
			editRandom->clear();
			int numar = this->srv.getAllOferteCos().size();
			int of = this->srv.addRandomToCos(nr);
			QMessageBox::information(this, "Info", QString::fromStdString("%1 oferte adaugate").arg(of - numar));
			this->reloadOfertaCosList(this->srv.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(golesteCos, &QPushButton::clicked, [&]() {
		try {
			this->srv.emptyCos();
			QMessageBox::information(this, "Info", QString::fromStdString("Cosul a fost golit"));
			this->reloadOfertaCosList(this->srv.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(exportCos, &QPushButton::clicked, [&]() {
		try {
			string fisier = editExport->text().toStdString();
			editExport->clear();
			this->srv.export_fisier(fisier);
			QMessageBox::information(this, "Info", QString::fromStdString("Cosul a fost inregistrat in fisierul dat."));
			listaCos->clear();
			this->srv.emptyCos();
			this->reloadOfertaCosList(this->srv.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(btnCosCRUGUI, &QPushButton::clicked, [&]() {		
		auto fereastraCos = new CosGUILista{ srv.getCos() };
		fereastraCos->show();
		});

	QObject::connect(btnCosReadOnlyGUI, &QPushButton::clicked, [&]() {
		auto fereastraFiguri = new HistogramGUI{ srv.getCos() };
		fereastraFiguri->show();
		});
	
}

void OfertaStoreGUI::reloadOfertaList(vector<Oferta> oferte)
{
	this->tableOferta->clearContents();
	this->tableOferta->setRowCount(oferte.size());

	int lineNumber = 0;
	for (auto& oferta : oferte) {
		this->tableOferta->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(oferta.getDenumire())));
		this->tableOferta->setItem(lineNumber, 1, new QTableWidgetItem(QString::fromStdString(oferta.getDestinatie())));
		this->tableOferta->setItem(lineNumber, 2, new QTableWidgetItem(QString::fromStdString(oferta.getTip())));
		this->tableOferta->setItem(lineNumber, 3, new QTableWidgetItem(QString::number(oferta.getPret())));
		lineNumber++;
	}

	int cnt = 0;
	for (int i = 0; i < srv.getAllOferte().size(); i++)
		if (srv.getAllOferte().at(i).getTip() == "AllInclusive")
			cnt++;
	if (cnt == 0)
		btnAllInclusive->setVisible(false);
	else
		btnAllInclusive->setVisible(true);

	cnt = 0;
	for (int i = 0; i < srv.getAllOferte().size(); i++)
		if (srv.getAllOferte().at(i).getTip() == "CityBreak")
			cnt++;
	if (cnt == 0)
		btnCityBreak->setVisible(false);
	else
		btnCityBreak->setVisible(true);

	cnt = 0;
	for (int i = 0; i < srv.getAllOferte().size(); i++)
		if (srv.getAllOferte().at(i).getTip() == "Croaziere")
			cnt++;
	if (cnt == 0)
		btnCroaziere->setVisible(false);
	else
		btnCroaziere->setVisible(true);

	cnt = 0;
	for (int i = 0; i < srv.getAllOferte().size(); i++)
		if (srv.getAllOferte().at(i).getTip() == "MultiCountry")
			cnt++;
	if (cnt == 0)
		btnMultiCountry->setVisible(false);
	else
		btnMultiCountry->setVisible(true);

	cnt = 0;
	for (int i = 0; i < srv.getAllOferte().size(); i++)
		if (srv.getAllOferte().at(i).getTip() == "Altele")
			cnt++;
	if (cnt == 0)
		btnAltele->setVisible(false);
	else
		btnAltele->setVisible(true);

	
	this->listaOferte->clear();
	for (const auto& elem : oferte) {
		auto item = new QListWidgetItem(
			QString::fromStdString(
				elem.getDenumire() + " "
				+ elem.getDestinatie() + " "
				+ elem.getTip() + " "
				+ std::to_string(elem.getPret()
				)));
		this->listaOferte->addItem(item);
	}
}

void OfertaStoreGUI::reloadOfertaCosList(vector<Oferta> oferte)
{
	this->listaCos->clear();
	for (const auto& elem : oferte) {
		auto item = new QListWidgetItem(
			QString::fromStdString(
				elem.getDenumire() + " "
				+ elem.getDestinatie() + " "
				+ elem.getTip() + " "
				+ std::to_string(elem.getPret()
				)));
		this->listaCos->addItem(item);
	}
}


void OfertaStoreGUI::guiAddOferta()
{
	try {
		string denumire = editDenumire->text().toStdString();
		string destinatie = editDestinatie->text().toStdString();
		string tip = editTip->text().toStdString();
		int pret = editPret->text().toInt();

		editDenumire->clear();
		editDestinatie->clear();
		editTip->clear();
		editPret->clear();

		this->srv.addOferta(denumire, destinatie, tip, pret);
		this->reloadOfertaList(this->srv.getAllOferte());

		QMessageBox::information(this, "Info", QString::fromStdString("Oferta adaugata cu succes."));

	}
	catch (RepoException& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
	}
	catch (ValidationException& ve) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
	}
}

void OfertaStoreGUI::guiModifyOferta()
{
	try {
		string denumire = editDenumire->text().toStdString();
		string destinatie = editDestinatie->text().toStdString();
		string tip = editTip->text().toStdString();
		int pret = editPret->text().toInt();

		editDenumire->clear();
		editDestinatie->clear();
		editTip->clear();
		editPret->clear();

		this->srv.modifyOferta(denumire, destinatie, tip, pret);
		this->reloadOfertaList(this->srv.getAllOferte());

		QMessageBox::information(this, "Info", QString::fromStdString("Oferta modificata cu succes."));

	}
	catch (RepoException& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
	}
	catch (ValidationException& ve) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
	}
}

void OfertaStoreGUI::guiDeleteOferta()
{
	try {
		string denumire = editDenumire->text().toStdString();
		string destinatie = editDestinatie->text().toStdString();
		string tip = editTip->text().toStdString();
		int pret = editPret->text().toInt();

		editDenumire->clear();
		editDestinatie->clear();
		editTip->clear();
		editPret->clear();

		this->srv.deleteOferta(denumire);
		this->reloadOfertaList(this->srv.getAllOferte());

		QMessageBox::information(this, "Info", QString::fromStdString("Oferta stearsa cu succes."));

	}
	catch (RepoException& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
	}
	catch (ValidationException& ve) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
	}
}
