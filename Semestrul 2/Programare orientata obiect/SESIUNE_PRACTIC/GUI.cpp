#pragma once

#include "GUI.h"

#include "qdebug.h"

void GUI::init_GUI() {

    this->setLayout(layout);

    table->setColumnCount(4);
    table->setRowCount(service.getAll().size());

    int nr = 0;
    for(auto &el : service.getAll()) {
        table->setItem(nr, 0, new QTableWidgetItem(QString::number(el.get_id())));
        table->setItem(nr, 1, new QTableWidgetItem(QString::fromStdString(el.get_descriere())));
        table->setItem(nr, 2, new QTableWidgetItem(QString::fromStdString(el.get_stare())));
        table->setItem(nr, 3, new QTableWidgetItem(QString::number(el.get_programatori().size())));
        nr++;
    }

    layout->addWidget(table);
    layout->addWidget(new QLabel("ID"));
    layout->addWidget(editId);
    layout->addWidget(new QLabel("Descriere"));
    layout->addWidget(editDescriere);
    layout->addWidget(new QLabel("Stare"));
    layout->addWidget(editStare);
    layout->addWidget(new QLabel("Programatori"));
    layout->addWidget(editProgramatori);
    layout->addWidget(btnAdaugare);
    layout->addWidget(editString);

}

void GUI::reload_GUI(vector<Task> taskuri) {
    table->setColumnCount(4);
    table->setRowCount(taskuri.size());

    int nr = 0;
    for(auto &el : taskuri) {
        table->setItem(nr, 0, new QTableWidgetItem(QString::number(el.get_id())));
        table->setItem(nr, 1, new QTableWidgetItem(QString::fromStdString(el.get_descriere())));
        table->setItem(nr, 2, new QTableWidgetItem(QString::fromStdString(el.get_stare())));
        table->setItem(nr, 3, new QTableWidgetItem(QString::number(el.get_programatori().size())));
        nr++;
    }
}

void GUI::connectSignalSlots() {
    QObject::connect(btnAdaugare, &QPushButton::clicked, [this]{
        int id = editId->text().toInt();
        string descriere = editDescriere->text().toStdString();
        string stare = editStare->text().toStdString();
        string programatori = editProgramatori->text().toStdString();
        editId->clear();
        editDescriere->clear();
        editStare->clear();
        editProgramatori->clear();
        try {
            service.adaugare(id, descriere, programatori, stare);
            reload_GUI(service.getAll());
        } catch (exception&) {
            QMessageBox* msgBox = new QMessageBox;
            msgBox->setText(QString::fromStdString("EROARE! DATE INVALIDE!"));
            msgBox->exec();
        }
    });

    QObject::connect(editString, &QLineEdit::textChanged, [this]{
        string filtru = editString->text().toStdString();
        if(filtru == "")
            reload_GUI(service.getAll());
        else
            reload_GUI(service.sortare(service.filtrare(filtru)));
    });

}
