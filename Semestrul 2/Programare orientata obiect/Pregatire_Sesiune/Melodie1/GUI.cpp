#pragma once

#include <QPainter>
#include "GUI.h"


void GUI::init_GUI() {

//    tabel = new QTableWidget(service.getAll().size(), 4);
//    tabel->clear();

    model = new MyTableModel{service.getAll(), service.rank_fr()};
//    tabel->setSelectionModel(QAbstractItemView::SingleSelection);
    tabel->setModel(model);

//    int i = 0;
//    for(auto & m : service.getAll()) {
//        tabel->setItem(i, 0, new QTableWidgetItem(QString::number(m.get_id())));
//        tabel->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(m.get_titlu())));
//        tabel->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(m.get_artist())));
//        tabel->setItem(i, 3, new QTableWidgetItem(QString::number(m.get_rank())));
//        i++;
//    }

    titluMelodie = new QLineEdit;

    butonUpdate = new QPushButton("Update");
    butonDelete = new QPushButton("Delete");

    sliderRank->setMinimum(0);
    sliderRank->setMaximum(10);

    this->setLayout(mainLayout);
    mainLayout->addWidget(tabel);
    mainLayout->addWidget(new QLabel("TITLU"));
    mainLayout->addWidget(titluMelodie);
    mainLayout->addWidget(sliderRank);
    mainLayout->addWidget(butonUpdate);
    mainLayout->addWidget(butonDelete);

}

void GUI::connect_slots() {
    QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [this] {
        if(tabel->selectionModel()->selectedIndexes().isEmpty()) {
            titluMelodie->setText("");
            return;
        } else {
            auto row = tabel->selectionModel()->selectedIndexes().at(0).row();
            auto titlu = tabel->model()->data(tabel->model()->index(row, 1), Qt::DisplayRole).toString();
            titluMelodie->setText(titlu);
        }
    });

    QObject::connect(butonUpdate, &QPushButton::clicked, [this] {
        if(tabel->selectionModel()->selectedIndexes().isEmpty()) {
            return;
        }
        auto row = tabel->selectionModel()->selectedIndexes().at(0).row();
        auto id = tabel->model()->data(tabel->model()->index(row, 0), Qt::DisplayRole).toInt();
        auto titlu_nou = titluMelodie->text().toStdString();
        auto rank_nou = sliderRank->value();
        try {
            service.modificare_rank(id, titlu_nou, rank_nou);
            this->repaint();
            reload_GUI();
        }
        catch (exception&) {
            QLabel* lbl = new QLabel;
            lbl->setText("DATE INVALIDE!");
            lbl->show();
        }

    });

    QObject::connect(butonDelete, &QPushButton::clicked, [this] {
        if(tabel->selectionModel()->selectedIndexes().isEmpty()) {
            return;
        }
        auto row = tabel->selectionModel()->selectedIndexes().at(0).row();
        auto id = tabel->model()->data(tabel->model()->index(row, 0), Qt::DisplayRole).toInt();
        try {
            service.sterge(id);
        }
        catch (exception&) {
            QLabel* lbl = new QLabel;
            lbl->setText("DATE INVALIDE!");
            lbl->show();
        }
        this->repaint();
        reload_GUI();
    });
}

void GUI::reload_GUI() {
//    tabel->clear();
//
//    int i = 0;
//    for(auto & m : service.getAll()) {
//        tabel->setItem(i, 0, new QTableWidgetItem(QString::number(m.get_id())));
//        tabel->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(m.get_titlu())));
//        tabel->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(m.get_artist())));
//        tabel->setItem(i, 3, new QTableWidgetItem(QString::number(m.get_rank())));
//        i++;
//    }
    model->set_melodii(service.getAll(), service.rank_fr());
}

void GUI::paintEvent(QPaintEvent *ev) {
    QPainter p{this};
    p.setPen(Qt::darkRed);
    int rank = 0;
    for(auto &c : service.rank_fr()) {
        int x = (rank + 1) * 10;
        p.drawLine(x, p.device()->height(), x, p.device()->height() - c * 5);
        rank++;
    }
}