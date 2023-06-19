#pragma once
#include "GUI.h"

void GUI::init_GUI() {



    tabel->clear();
    tabel->setRowCount(service.getAll().size());
    tabel->setColumnCount(5);
    int nr = 0;
    for(auto &t : service.getAll()) {
        tabel->setItem(nr, 0, new QTableWidgetItem(QString::number(t.get_id())));
        tabel->setItem(nr, 1, new QTableWidgetItem(QString::fromStdString(t.get_denumire())));
        tabel->setItem(nr, 2, new QTableWidgetItem(QString::fromStdString(t.get_tip())));
        tabel->setItem(nr, 3, new QTableWidgetItem(QString::number(t.get_numarRoti())));
        tabel->setItem(nr, 4, new QTableWidgetItem(QString::number(service.nrTip(t))));
        nr++;
    }

    for(auto &tip : service.getTipuri(service.getAll())) {
        comboBox->addItem(QString::fromStdString(tip));
    }

    setLayout(layout);
    layout->addWidget(tabel);
    layout->addWidget(new QLabel("Id"));
    layout->addWidget(editId);
    layout->addWidget(new QLabel("Denumire"));
    layout->addWidget(editDenumire);
    layout->addWidget(new QLabel("Tip"));
    layout->addWidget(editTip);
    layout->addWidget(new QLabel("Numar roti"));
    layout->addWidget(editNrRoti);
    layout->addWidget(btnAdaugare);
    layout->addWidget(comboBox);
}

void GUI::connectSignalSlots() {
    QObject::connect(btnAdaugare, &QPushButton::clicked, [this] {
        int id, nrRoti;
        string denumire, tip;
        id = editId->text().toInt();
        nrRoti = editNrRoti->text().toInt();
        denumire = editDenumire->text().toStdString();
        tip = editTip->text().toStdString();
        editId->clear();
        editDenumire->clear();
        editTip->clear();
        editNrRoti->clear();
        string exceptii = service.adaugare(id, denumire, tip, nrRoti);
        reload_GUI();
        if(!exceptii.empty()) {
            QMessageBox* msg = new QMessageBox();
            msg->setText(QString::fromStdString(exceptii));
            msg->setWindowTitle("WARNING!");
            msg->exec();
        }
    });

//    QComboBox::connect(comboBox, QOverload<int>::of(&QComboBox::activated),[=](int index) {
//        auto ss = comboBox->activated(index);
//    });

}

void GUI::reload_GUI() {
    tabel->clear();
    tabel->setRowCount(service.getAll().size());
    tabel->setColumnCount(5);
    int nr = 0;
    for(auto &t : service.getAll()) {
        tabel->setItem(nr, 0, new QTableWidgetItem(QString::number(t.get_id())));
        tabel->setItem(nr, 1, new QTableWidgetItem(QString::fromStdString(t.get_denumire())));
        tabel->setItem(nr, 2, new QTableWidgetItem(QString::fromStdString(t.get_tip())));
        tabel->setItem(nr, 3, new QTableWidgetItem(QString::number(t.get_numarRoti())));
        tabel->setItem(nr, 4, new QTableWidgetItem(QString::number(service.nrTip(t))));
        nr++;
    }

    for(auto &tip : service.getTipuri(service.getAll())) {
        comboBox->addItem(QString::fromStdString(tip));
    }
}
