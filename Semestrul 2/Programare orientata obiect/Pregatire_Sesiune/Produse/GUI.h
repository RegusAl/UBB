#pragma once

#include "service.h"
#include "MODEL.h"
#include <QDebug>
#include "observer.h"

#include "QTableView"
#include "QLayout"
#include "QWidget"
#include "QAbstractItemView"
#include "QVBoxLayout"
#include "QTableWidget"
#include <QBrush>
#include "QLabel"
#include "QLineEdit"
#include "QPushButton"
#include "QMessageBox"

class newWindow : public Observer {
private:
    Service &srv;
    string tip;
    int nr;
    QLabel* label = new QLabel;
    QWidget* window = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout;
public:
    newWindow(Service& srv, string tip, int nr) : srv{srv}, tip(tip), nr{nr} {
        this->srv.addObserver(this);
        auto txt = to_string(nr);
        label->setText(QString::fromStdString(txt));
        window->setWindowTitle(QString::fromStdString(tip));
        window->setLayout(layout);
        layout->addWidget(label);
    }
    ~newWindow() {
        this->srv.removeObserver(this);
    }
    void update() override {
        this->srv.nr_tipuri(tip);
        auto txt = to_string(nr);
        label->setText(QString::fromStdString(txt));
    }
    void run() {
        window->show();
    }
};

class GUI : public QWidget {
private:
    Service& service;

    QTableView* tabel = new QTableView;
    MyTableModel* model = new MyTableModel{service.getAll(), 0};

    QVBoxLayout* layout = new QVBoxLayout();

//    QTableWidget* tabel = new QTableWidget;

    QLineEdit* editId = new QLineEdit;
    QLineEdit* editNume = new QLineEdit;
    QLineEdit* editTip = new QLineEdit;
    QLineEdit* editPret = new QLineEdit;

    QPushButton* btnAdaugare = new QPushButton("Adaugare");

    QSlider* slider = new QSlider;
    QLabel* sliderValue;




    void init_GUI();
    void connectSignalSlots();
    void reload_GUI(int sldValue);
    void open_dinamic();



public:
    GUI(Service& service) : service(service) {
        init_GUI();
        connectSignalSlots();
//        reload_GUI();
    }

    void run() {
        this->show();
        open_dinamic();
    }
};