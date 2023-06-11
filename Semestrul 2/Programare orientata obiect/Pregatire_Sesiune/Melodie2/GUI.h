#pragma once

#include "QtWidgets"
#include "QWidget"
#include "QTableWidget"
#include "QTableWidgetItem"

#include "service.h"

class Painter : public QWidget {
private:
    map<string, int> genuri;
public:
    explicit Painter(map<string, int> genuri) : genuri(genuri) {
            this->repaint();
    }
    void paintEvent(QPaintEvent* ev) override;
};

class GUI : public QWidget {
private:
    Service &service;

    QVBoxLayout* mainLayout = new QVBoxLayout;

    QTableWidget* tabel = new QTableWidget;

    QLineEdit* editTitlu = new QLineEdit;
    QLineEdit* editArtist = new QLineEdit;
    QLineEdit* editGen = new QLineEdit;

    QPushButton* butonAdaugare = new QPushButton("Adaugare");
    QPushButton* butonStergere = new QPushButton("Stergere");

    Painter* painter;

    void init_GUI();
    void reload_GUI();
    void connectSignalSlots();
    void paintEvent(QPaintEvent* ev) override;

public:
    explicit GUI(Service &service) : service(service) {
        init_GUI();
        connectSignalSlots();
        reload_GUI();
        this->repaint();
//        reload();

    }
};