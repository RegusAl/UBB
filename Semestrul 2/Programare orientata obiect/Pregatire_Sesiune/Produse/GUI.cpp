#pragma once

#include <QLabel>
#include "GUI.h"

void GUI::init_GUI() {

//    tabel->setSelectionModel(QAbstractItemView::SingleSelection);
    tabel->setModel(model);

//    tabel->clear();
//    tabel->setColumnCount(5);
//    tabel->setRowCount(service.getAll().size());
//    int nr = 0;
//    for(auto &p : service.getAll()) {
//        tabel->setItem(nr, 0, new QTableWidgetItem(QString::number(p.get_id())));
//        tabel->setItem(nr, 1, new QTableWidgetItem(QString::fromStdString(p.get_nume())));
//        tabel->setItem(nr, 2, new QTableWidgetItem(QString::fromStdString(p.get_tip())));
//        tabel->setItem(nr, 3, new QTableWidgetItem(QString::number(p.get_pret())));
//        tabel->setItem(nr, 4, new QTableWidgetItem(QString::number(service.numarVocale(p.get_nume()))));
//        nr++;
//    }

    slider->setMinimum(1);
    slider->setMaximum(100);

    sliderValue = new QLabel;

    this->setLayout(layout);
    layout->addWidget(tabel);
    layout->addWidget(new QLabel("ID"));
    layout->addWidget(editId);
    layout->addWidget(new QLabel("Nume"));
    layout->addWidget(editNume);
    layout->addWidget(new QLabel("Tip"));
    layout->addWidget(editTip);
    layout->addWidget(new QLabel("Pret"));
    layout->addWidget(editPret);
    layout->addWidget(btnAdaugare);
    layout->addWidget(slider);
    layout->addWidget(sliderValue);
}

void GUI::reload_GUI(int sldValue) {
    model->setProduse(service.getAll(), slider->value());
//    tabel->clear();
//    tabel->setColumnCount(5);
//    tabel->setRowCount(service.getAll().size());
//    this->sliderValue->setText(QString::number(sldValue));
//    int nr = 0;
//    for(auto &p : service.getAll()) {
//        QBrush bg(Qt::white);
//        if(sldValue > p.get_pret()) {
//             bg.setColor(Qt::red);
//        }
//        tabel->setItem(nr, 0, new QTableWidgetItem(QString::number(p.get_id())));
//        tabel->setItem(nr, 1, new QTableWidgetItem(QString::fromStdString(p.get_nume())));
//        tabel->setItem(nr, 2, new QTableWidgetItem(QString::fromStdString(p.get_tip())));
//        tabel->setItem(nr, 3, new QTableWidgetItem(QString::number(p.get_pret())));
//        tabel->setItem(nr, 4, new QTableWidgetItem(QString::number(service.numarVocale(p.get_nume()))));
//        tabel->item(nr, 0)->setBackground(bg);
//        tabel->item(nr, 1)->setBackground(bg);
//        tabel->item(nr, 2)->setBackground(bg);
//        tabel->item(nr, 3)->setBackground(bg);
//        tabel->item(nr, 4)->setBackground(bg);
//
//
//        nr++;
//    }
}

void GUI::connectSignalSlots() {
    QObject::connect(btnAdaugare, &QPushButton::clicked, [this] {
        int id = editId->text().toInt();
        string nume = editNume->text().toStdString();
        string tip = editTip->text().toStdString();
        double pret = editPret->text().toDouble();
        editId->clear();
        editNume->clear();
        editTip->clear();
        editPret->clear();
        qDebug()<< id<<" "<<QString::fromStdString(nume)<<" "<<QString::fromStdString(tip)<<pret<<"\n";
        string exceptii = service.adaugare(id, nume, tip, pret);
        reload_GUI(0);
        if(exceptii!="") {
            QMessageBox msgBox;
            msgBox.setText(QString::fromStdString(exceptii));
            msgBox.exec();
        }
    });

    QObject::connect(slider, &QSlider::sliderMoved, [this] {
        int value = slider->value();
        qDebug()<<value;
        int i = 0;
        reload_GUI(value);
    });
}

void GUI::open_dinamic() {
    auto list = service.get_tipuri();
    for(auto &el : list) {
        auto wnd = new newWindow{service, el.first, el.second};
        wnd->run();
    }
}


