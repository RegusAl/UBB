#pragma once

#include "service.h"

#include "Qt"
#include "QTableView"
#include "QLayout"
#include "QLabel"
#include "QObject"
#include "QLineEdit"
#include "QVBoxLayout"
#include "QWidget"
#include "QPushButton"
#include "MyTableModel.h"
#include "MyListModel.h"
#include "QListView"
#include "QMessageBox"

class GUI : public QWidget {
private:
    Service &service;

    QVBoxLayout* layout = new QVBoxLayout;

    MyTableModel* model;
    QTableView* tabel = new QTableView;

//    MyListModel* model;
//QListView* lista = new QListView;

    QLineEdit* editId = new QLineEdit;
    QLineEdit* editNume = new QLineEdit;
    QLineEdit* editTip = new QLineEdit;

    QPushButton* btnAdaugare = new QPushButton("Adaugare");
    QPushButton* btnStergere = new QPushButton("Stergere");

    void init_GUI();
    void connectSignalSlots();
    void reload_GUI();
public:
    GUI(Service &service) : service{service} {
        init_GUI();
        connectSignalSlots();
    }
};