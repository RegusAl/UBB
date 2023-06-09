#include "StoreGUIModele.h"

void StoreGUIModele::initGUICmps()
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
	

	btnUndo = new QPushButton("Undo");
	lyLeft->addWidget(btnUndo);

	btnCos = new QPushButton("Cos");
	addCos = new QPushButton("Adauga oferta in cos");
	denumireOferta = new QLineEdit;
	addRandomCos = new QPushButton("Adauga oferte random in cos");
	editRandom = new QLineEdit;
	golesteCos = new QPushButton("Goleste cos");
	editExport = new QLineEdit;
	//this->listaCos = new QListWidget();
	exportCos = new QPushButton("Export cos");

	//componenta right - contine doar tabelul cu oferte
	QWidget* right = new QWidget;
	QVBoxLayout* lyRight = new QVBoxLayout;
	right->setLayout(lyRight);


	lyRight->addWidget(tblV);

	btnAddCos = new QPushButton("Adauga Oferta Cos");
	btnDeleteCos = new QPushButton("Sterge Oferta Cos");
	btnRandomCos = new QPushButton("Adauga Oferte Random Cos");
	lyRight->addWidget(btnAddCos);
	lyRight->addWidget(btnDeleteCos);
	lyRight->addWidget(btnRandomCos);

    btnCosCRUGUI = new QPushButton("CosCRUDGui");
    lyRight->addWidget(btnCosCRUGUI);

    btnCosReadOnlyGUI = new QPushButton("CosReadOnlyGUI");
    lyRight->addWidget(btnCosReadOnlyGUI);

	lyMain->addWidget(left);
	lyMain->addWidget(right);
}

void StoreGUIModele::connectSignalsSlots()
{
	QObject::connect(btnAddOferta, &QPushButton::clicked, this, &StoreGUIModele::guiAddOferta);
	QObject::connect(btnModifyOferta, &QPushButton::clicked, this, &StoreGUIModele::guiModifyOferta);
	QObject::connect(btnDeleteOferta, &QPushButton::clicked, this, &StoreGUIModele::guiDeleteOferta);

	QObject::connect(btnUndo, &QPushButton::clicked, [&]() {
		try {
			this->ctr.undo();
			this->reloadList(this->ctr.getAllOferte());
			QMessageBox::information(this, "Info", QString::fromStdString("Undo realizat cu succes."));
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});


	QObject::connect(btnSortOferte, &QPushButton::clicked, [&]() {
		if (this->radioSrtDenumire->isChecked())
			this->reloadList(ctr.sortByDenumire());
		else if (this->radioSrtDestinatue->isChecked())
			this->reloadList(ctr.sortByDestinatie());
		else if (this->radioSrtTipPret->isChecked())
			this->reloadList(ctr.sortByTipSiPret());
		});

	QObject::connect(btnFilterOferte1, &QPushButton::clicked, [&]() {
		string filterC = this->editFilterPret->text().toStdString();
		this->reloadList(ctr.filtrarePret(stoi(filterC)));
		});

	QObject::connect(btnFilterOferte2, &QPushButton::clicked, [&]() {
		string filterC = this->editFilterDestinatie->text().toStdString();
		this->reloadList(ctr.filtrareDest(filterC));
		});

	QObject::connect(btnReloadData, &QPushButton::clicked, [&]() {
		this->reloadList(ctr.getAllOferte());
		});

	QObject::connect(tblV->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
		if (tblV->selectionModel()->selectedIndexes().isEmpty()) {
			editDenumire->setText("");
			editDestinatie->setText("");
			editTip->setText("");
			editPret->setText("");
			return;
		}
		int selRow = tblV->selectionModel()->selectedIndexes().at(0).row();
		auto cel0Index = tblV->model()->index(selRow, 0);
		auto cel0Value = tblV->model()->data(cel0Index, Qt::DisplayRole).toString();
		editDenumire->setText(cel0Value);
		auto cel1Index = tblV->model()->index(selRow, 1);
		auto cel1Value = tblV->model()->data(cel1Index, Qt::DisplayRole).toString();
		editDestinatie->setText(cel1Value);
		auto cel2Index = tblV->model()->index(selRow, 2);
		auto cel2Value = tblV->model()->data(cel2Index, Qt::DisplayRole).toString();
		editTip->setText(cel2Value);
		auto cel3Index = tblV->model()->index(selRow, 3);
		auto cel3Value = tblV->model()->data(cel3Index, Qt::DisplayRole).toString();
		editPret->setText(cel3Value);
		});

	QObject::connect(btnCos, &QPushButton::clicked, [&]() {
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
			this->ctr.addToCos(denumire);
			QMessageBox::information(this, "Info", QString::fromStdString("Oferta adaugata cu succes."));
			this->reloadList(this->ctr.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(btnAddCos, &QPushButton::clicked, [&]() {
		try {
			string denumire = editDenumire->text().toStdString();
			editDenumire->clear();
			this->ctr.addToCos(denumire);
			QMessageBox::information(this, "Info", QString::fromStdString("Oferta adaugata cu succes."));
			//this->reloadList(this->ctr.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(btnDeleteCos, &QPushButton::clicked, [&]() {
		try {
			string denumire = editDenumire->text().toStdString();
			editDenumire->clear();
			this->ctr.sterge_of(denumire);
			QMessageBox::information(this, "Info", QString::fromStdString("Oferta stearsa cu succes."));
			//this->reloadList(this->ctr.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(addRandomCos, &QPushButton::clicked, [&]() {
		try {
			int nr = editRandom->text().toInt();
			editRandom->clear();
			int numar = this->ctr.getAllOferteCos().size();
			int of = this->ctr.addRandomToCos(nr);
			QMessageBox::information(this, "Info", QString::fromStdString("%1 oferte adaugate").arg(of - numar));
			//this->reloadList(this->ctr.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(btnRandomCos, &QPushButton::clicked, [&]() {
		try {
			int nr = editRandom->text().toInt();
			editRandom->clear();
			int numar = this->ctr.getAllOferteCos().size();
			int of = this->ctr.addRandomToCos(nr);
			QMessageBox::information(this, "Info", QString::fromStdString("%1 oferte adaugate").arg(of - numar));
			//this->reloadList(this->ctr.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(golesteCos, &QPushButton::clicked, [&]() {
		try {
			this->ctr.emptyCos();
			QMessageBox::information(this, "Info", QString::fromStdString("Cosul a fost golit"));
			//this->reloadList(this->ctr.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(exportCos, &QPushButton::clicked, [&]() {
		try {
			string fisier = editExport->text().toStdString();
			editExport->clear();
			this->ctr.export_fisier(fisier);
			QMessageBox::information(this, "Info", QString::fromStdString("Cosul a fost inregistrat in fisierul dat."));
			listaCos->clear();
			this->ctr.emptyCos();
			//this->reloadOfertaCosList(this->ctr.getAllOferteCos());
		}
		catch (RepoException& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
		}
		});

	QObject::connect(btnCosCRUGUI, &QPushButton::clicked, [&]() {
		auto fereastraCos = new CosGUILista{ ctr.getCos() };
		fereastraCos->show();
		});

	QObject::connect(btnCosReadOnlyGUI, &QPushButton::clicked, [&]() {
		auto fereastraFiguri = new HistogramGUI{ ctr.getCos() };
		fereastraFiguri->show();
		});
}

void StoreGUIModele::reloadList(std::vector<Oferta> oferte)
{
	modelTabel->setOferte(oferte);
}

void StoreGUIModele::guiAddOferta()
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

		this->ctr.addOferta(denumire, destinatie, tip, pret);
		this->reloadList(this->ctr.getAllOferte());

		QMessageBox::information(this, "Info", QString::fromStdString("Oferta adaugata cu succes."));

	}
	catch (RepoException& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
	}
	catch (ValidationException& ve) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
	}
}

void StoreGUIModele::guiModifyOferta()
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

		this->ctr.modifyOferta(denumire, destinatie, tip, pret);
		this->reloadList(this->ctr.getAllOferte());

		QMessageBox::information(this, "Info", QString::fromStdString("Oferta modificata cu succes."));

	}
	catch (RepoException& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
	}
	catch (ValidationException& ve) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
	}
}

void StoreGUIModele::guiDeleteOferta()
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

		this->ctr.deleteOferta(denumire);
		this->reloadList(this->ctr.getAllOferte());

		QMessageBox::information(this, "Info", QString::fromStdString("Oferta stearsa cu succes."));

	}
	catch (RepoException& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
	}
	catch (ValidationException& ve) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
	}
}
