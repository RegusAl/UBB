#pragma once

#include "service.h"

#include "QWidget"
#include "QWidgetItem"
#include "QTableWidget"
#include "QTableWidget"
#include "QVBoxLayout"
#include "QMessageBox"
#include "QPushButton"
#include "QLineEdit"
#include "QLabel"

class GUI : public QWidget {
private:
    Service& service;

    QVBoxLayout* layout = new QVBoxLayout;

    QTableWidget* table = new QTableWidget;

    QLineEdit* editId = new QLineEdit;
    QLineEdit* editDescriere = new QLineEdit;
    QLineEdit* editProgramatori = new QLineEdit;
    QLineEdit* editStare = new QLineEdit;

    QPushButton* btnAdaugare = new QPushButton("Adaugare");

    QLineEdit* editString = new QLineEdit;

    void init_GUI();
    void reload_GUI(vector<Task> taskuri);
    void connectSignalSlots();
public:
    GUI(Service& service) : service(service) {
        init_GUI();
        connectSignalSlots();
    }
};