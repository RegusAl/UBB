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
	btnHiking = new QPushButton("Hiking");
	btnMultiCountry = new QPushButton("MultiCountry");
	btnAltele = new QPushButton("Altele");
	lyLeft->addWidget(btnAllInclusive);
	lyLeft->addWidget(btnCityBreak);
	lyLeft->addWidget(btnHiking);
	lyLeft->addWidget(btnMultiCountry);
	lyLeft->addWidget(btnAltele);

	int cnt = 0;
	for (int i = 0; i < srv.getAll().size(); i++)
		if (srv.getAll().at(i).getTip() == "AllInclusive")
			cnt++;
	if (cnt == 0)
		btnAllInclusive->setVisible(false);

	cnt = 0;
	for (int i = 0; i < srv.getAll().size(); i++)
		if (srv.getAll().at(i).getTip() == "CityBreak")
			cnt++;
	if (cnt == 0)
		btnCityBreak->setVisible(false);

	cnt = 0;
	for (int i = 0; i < srv.getAll().size(); i++)
		if (srv.getAll().at(i).getTip() == "Croaziere")
			cnt++;
	if (cnt == 0)
		btnHiking->setVisible(false);

	cnt = 0;
	for (int i = 0; i < srv.getAll().size(); i++)
		if (srv.getAll().at(i).getTip() == "MultiCountry")
			cnt++;
	if (cnt == 0)
		btnMultiCountry->setVisible(false);

	cnt = 0;
	for (int i = 0; i < srv.getAll().size(); i++)
		if (srv.getAll().at(i).getTip() == "Altele")
			cnt++;
	if (cnt == 0)
		btnAltele->setVisible(false);

	btnUndo = new QPushButton("Undo");
	lyLeft->addWidget(btnUndo);


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
			this->reloadOfertaList(this->srv.getAll());
			QMessageBox::information(this, "Info", QString::fromStdString("Undo realizat cu succes."));
		}
		catch (OfertaRepoException& re) {
			QMessageBox::warning(this, "Warning", "");
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
		this->reloadOfertaList(srv.filtrareDestinatie(filterC));
		});

	QObject::connect(btnReloadData, &QPushButton::clicked, [&]() {
		this->reloadOfertaList(srv.getAll());
		});

	QObject::connect(btnAllInclusive, &QPushButton::clicked, [&]() {
		int cnt = 0;
		for (int i = 0; i < srv.getAll().size(); i++)
			if (srv.getAll().at(i).getTip() == "AllInclusive")
				cnt++;
		QMessageBox::information(this, "Info", QString::fromStdString("Nr oferte AllInclusive: %1").arg(cnt));
		});

	QObject::connect(btnCityBreak, &QPushButton::clicked, [&]() {
		int cnt = 0;
		for (int i = 0; i < srv.getAll().size(); i++)
			if (srv.getAll().at(i).getTip() == "CityBreak")
				cnt++;
		QMessageBox::information(this, "Info", QString::fromStdString("Nr oferte CityBreak: %1").arg(cnt));
		});
	
	QObject::connect(btnHiking, &QPushButton::clicked, [&]() {
		int cnt = 0;
		for (int i = 0; i < srv.getAll().size(); i++)
			if (srv.getAll().at(i).getTip() == "Hiking")
				cnt++;
		QMessageBox::information(this, "Info", QString::fromStdString("Nr oferte Hiking: %1").arg(cnt));
		});

	QObject::connect(btnMultiCountry, &QPushButton::clicked, [&]() {
		int cnt = 0;
		for (int i = 0; i < srv.getAll().size(); i++)
			if (srv.getAll().at(i).getTip() == "MultiCountry")
				cnt++;
		QMessageBox::information(this, "Info", QString::fromStdString("Nr oferte MultiCountry: %1").arg(cnt));
		});

	QObject::connect(btnAltele, &QPushButton::clicked, [&]() {
		int cnt = 0;
		for (int i = 0; i < srv.getAll().size(); i++)
			if (srv.getAll().at(i).getTip() == "Altele")
				cnt++;
		QMessageBox::information(this, "Info", QString::fromStdString("Nr oferte Altele: %1").arg(cnt));
		});



	QObject::connect(this->tableOferta, &QTableWidget::itemSelectionChanged, [&]() {
		/*
		QItemSelectionModel *select = table->selectionModel(); select->hasSelection() //check if has selection select->selectedRows() //
		return selected row(s) select->selectedColumns() // return selected column(s) Check selectedRows method of the QItemSelectionModel Class .
		*/
		//auto q = this->tableOferta->SelectedClicked();
		//int index = int(q[1]);
		
		//QItemSelectionModel* select = tableOferta->selectionModel();
		//select->hasSelection();
		///auto q = select->selectedIndexes();
		//int row = 0, col = 0;
		//auto SelectedRow = this->tableOferta->selectedItems().at(row)->data(col).toString();
		

		
		int indexbun;
		QModelIndexList selection = this->tableOferta->selectionModel()->selectedRows();
		for (int i = 0; i < selection.count(); i++)
		{
			QModelIndex index = selection.at(i);
			indexbun = index.row();
			QMessageBox::information(this, "Info", QString::fromStdString("Ati apasat %1").arg(index.row()));
		}

		auto elements = this->srv.getAll();
		QMessageBox::information(this, "Info", QString::fromStdString("Ati apasat %1").arg(indexbun));

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
	for (int i = 0; i < srv.getAll().size(); i++)
		if (srv.getAll().at(i).getTip() == "AllInclusive")
			cnt++;
	if (cnt == 0)
		btnAllInclusive->setVisible(false);
	else
		btnAllInclusive->setVisible(true);

	cnt = 0;
	for (int i = 0; i < srv.getAll().size(); i++)
		if (srv.getAll().at(i).getTip() == "CityBreak")
			cnt++;
	if (cnt == 0)
		btnCityBreak->setVisible(false);
	else
		btnCityBreak->setVisible(true);

	cnt = 0;
	for (int i = 0; i < srv.getAll().size(); i++)
		if (srv.getAll().at(i).getTip() == "Croaziere")
			cnt++;
	if (cnt == 0)
		btnHiking->setVisible(false);
	else
		btnHiking->setVisible(true);

	cnt = 0;
	for (int i = 0; i < srv.getAll().size(); i++)
		if (srv.getAll().at(i).getTip() == "MultiCountry")
			cnt++;
	if (cnt == 0)
		btnMultiCountry->setVisible(false);
	else
		btnMultiCountry->setVisible(true);

	cnt = 0;
	for (int i = 0; i < srv.getAll().size(); i++)
		if (srv.getAll().at(i).getTip() == "Altele")
			cnt++;
	if (cnt == 0)
		btnAltele->setVisible(false);
	else
		btnAltele->setVisible(true);
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

		this->srv.adaugaOferta(denumire, destinatie, tip, pret);
		this->reloadOfertaList(this->srv.getAll());

		QMessageBox::information(this, "Info", QString::fromStdString("Oferta adaugata cu succes."));

	}
	catch (OfertaRepoException& re) {
		QMessageBox::warning(this, "Warning", "");
	}
	catch (Exception& ve) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getMessage()));
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

		this->srv.modificaOferta(denumire, destinatie, tip, pret);
		this->reloadOfertaList(this->srv.getAll());

		QMessageBox::information(this, "Info", QString::fromStdString("Oferta modificata cu succes."));

	}
	catch (OfertaRepoException& re) {
		QMessageBox::warning(this, "Warning", "");
	}
	catch (Exception& ve) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getMessage()));
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

		this->srv.stergereOferta(denumire, destinatie);
		this->reloadOfertaList(this->srv.getAll());

		QMessageBox::information(this, "Info", QString::fromStdString("Oferta stearsa cu succes."));

	}
	catch (OfertaRepoException& re) {
		QMessageBox::warning(this, "Warning", "");
	}
	catch (Exception& ve) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getMessage()));
	}
}
