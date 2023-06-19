#pragma once

#include <Qt>
#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QLayout>
#include <QTableWidget>
#include "QLabel"
#include "QLineEdit"
#include "QPushButton"
#include "QConstOverload"
#include "QMessageBox"
#include "QComboBox"

#include "service.h"

class GUI : public QWidget {
private:
    Service& service;

    QVBoxLayout* layout = new QVBoxLayout;
    QTableWidget* tabel = new QTableWidget;

    QLineEdit* editId = new QLineEdit;
    QLineEdit* editDenumire = new QLineEdit;
    QLineEdit* editTip = new QLineEdit;
    QLineEdit* editNrRoti = new QLineEdit;

    QPushButton* btnAdaugare = new QPushButton("Adaugare");

    QComboBox* comboBox = new QComboBox;



    void init_GUI();
    void connectSignalSlots();
    void reload_GUI();
public:
    GUI(Service& service) : service(service) {
        init_GUI();
        connectSignalSlots();
    }

};