#pragma once

#include "service.h"
#include "MODEL.h"

#include "QWidget"
#include "Qt"
#include "QString"
#include "QLabel"
#include "QLineEdit"
#include "QTableView"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QLayout"
#include "QVBoxLayout"
#include "QPushButton"

class GUI : public QWidget {
private:
    Service &service;

    QVBoxLayout* layout = new QVBoxLayout;

    MyTableModel* model;
    QTableView* tabel = new QTableView;

    QLineEdit* editId = new QLineEdit;
    QLineEdit* editTitlu = new QLineEdit;
    QLineEdit* editTip = new QLineEdit;
    QLineEdit* editPret = new QLineEdit;

    QPushButton* btnAdaugare = new QPushButton("Adaugare");


    void init_GUI();
    void reload_GUI();
    void connectSignalSlots();
public:
    GUI(Service& service) : service(service) {
        init_GUI();
        connectSignalSlots();
    }


};