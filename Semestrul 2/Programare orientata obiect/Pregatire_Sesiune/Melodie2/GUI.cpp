#include "GUI.h"

void GUI::init_GUI() {
    tabel->clear();
    tabel = new QTableWidget(service.getAll().size(), 6);

    int i = 0;
    for(auto &m : service.getAll()) {
        tabel->setItem(i, 0, new QTableWidgetItem(QString::number(m.get_id())));
        tabel->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(m.get_titlu())));
        tabel->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(m.get_artist())));
        tabel->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(m.get_gen())));
        tabel->setItem(i, 4, new QTableWidgetItem(QString::number(service.acelasiArtist(m))));
        tabel->setItem(i, 5, new QTableWidgetItem(QString::number(service.acelasiGen(m))));
        i++;
    }



    this->setLayout(mainLayout);
    mainLayout->addWidget(tabel);
    mainLayout->addWidget(new QLabel("Titlu"));
    mainLayout->addWidget(editTitlu);
    mainLayout->addWidget(new QLabel("Artist"));
    mainLayout->addWidget(editArtist);
    mainLayout->addWidget(new QLabel("Gen"));
    mainLayout->addWidget(editGen);
    mainLayout->addWidget(butonAdaugare);
    mainLayout->addWidget(butonStergere);
}

void GUI::reload_GUI() {

    tabel->clear();

    tabel->setRowCount(service.getAll().size());
    int i = 0;
    for(auto &m : service.getAll()) {
        tabel->setItem(i, 0, new QTableWidgetItem(QString::number(m.get_id())));
        tabel->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(m.get_titlu())));
        tabel->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(m.get_artist())));
        tabel->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(m.get_gen())));
        tabel->setItem(i, 4, new QTableWidgetItem(QString::number(service.acelasiArtist(m))));
        tabel->setItem(i, 5, new QTableWidgetItem(QString::number(service.acelasiGen(m))));
        i++;
    }
}

void GUI::connectSignalSlots() {
    QObject::connect(butonAdaugare, &QPushButton::clicked, [this] {
        string titlu = editTitlu->text().toStdString();
        string artist = editArtist->text().toStdString();
        string gen = editGen->text().toStdString();
        editTitlu->clear();
        editArtist->clear();
        editGen->clear();
        try {
            service.adaugare(titlu, artist, gen);
            this->repaint();
            reload_GUI();
        } catch (exception&) {
            QLabel* lbl = new QLabel;
            lbl->setText("Eroare la adaugare!");
            lbl->show();
        }
    });

    QObject::connect(butonStergere, &QPushButton::clicked, [this] {
        if(tabel->selectionModel()->selectedIndexes().isEmpty()) {
            QLabel* lbl = new QLabel;
            lbl->setText("Nu se poate sterge! Selectati din tabel!");
            lbl->show();

        } else {
            auto row = tabel->selectionModel()->selectedIndexes().at(0).row();
            auto id = tabel->model()->data(tabel->model()->index(row, 0), Qt::DisplayRole).toInt();
            service.stergere(id);
            this->repaint();
            reload_GUI();
        }
    });
}

void GUI::paintEvent(QPaintEvent *event) {
    QPainter p{this};
    p.setPen(Qt::darkMagenta);
    int pop = 0, rock = 0, folk = 0, disco = 0;
    for(auto& m : service.getAll()) {
        if(m.get_gen() == "pop") {
            pop++;
            p.drawEllipse(QPoint(0, 0), pop * 8, pop * 8);
        }
        if(m.get_gen() == "rock") {
            rock++;
            p.drawEllipse(QPoint(p.device()->width(), 0), rock * 8, rock * 8);
        }
        if(m.get_gen() == "folk") {
            folk++;
            p.drawEllipse(QPoint(0, p.device()->height()), folk * 8, folk * 8);
        }
        if(m.get_gen() == "disco") {
            disco++;
            p.drawEllipse(QPoint(p.device()->width(), p.device()->height()), disco * 8, disco * 8);
        }
    }
}