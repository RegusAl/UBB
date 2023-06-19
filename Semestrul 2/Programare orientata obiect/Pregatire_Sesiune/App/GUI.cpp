#include "GUI.h"

void GUI::init_GUI() {

    model = new MyTableModel(service.getAll());
    tabel->setModel(model);

    this->setLayout(layout);
    layout->addWidget(tabel);
    layout->addWidget(new QLabel("ID"));
    layout->addWidget(editId);
    layout->addWidget(new QLabel("Titlu"));
    layout->addWidget(editTitlu);
    layout->addWidget(new QLabel("Tip"));
    layout->addWidget(editTip);
    layout->addWidget(new QLabel("Pret"));
    layout->addWidget(editPret);
    layout->addWidget(btnAdaugare);
}

void GUI::reload_GUI() {
    model->setProduse(service.getAll());
}

void GUI::connectSignalSlots() {
    QObject::connect(btnAdaugare, &QPushButton::clicked, [this] {
       int id = editId->text().toInt();
       string titlu = editTitlu->text().toStdString();
       string tip = editTip->text().toStdString();
       double pret = editPret->text().toDouble();
       editId->clear();
       editTitlu->clear();
       editTip->clear();
       editPret->clear();
       service.adaugare(id, titlu, tip, pret);
       reload_GUI();
    });

    QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [this] {
        if(tabel->selectionModel()->selectedIndexes().isEmpty()) {
            editTitlu->setText("");
            return;
        } else {
            auto row = tabel->selectionModel()->selectedIndexes().at(0).row();
            auto id = tabel->model()->data(tabel->model()->index(row, 0), Qt::DisplayRole).toString();
            editId->setText(id);
            auto titlu = tabel->model()->data(tabel->model()->index(row, 1), Qt::DisplayRole).toString();
            editTitlu->setText(titlu);
            auto tip = tabel->model()->data(tabel->model()->index(row, 2), Qt::DisplayRole).toString();
            editTip->setText(tip);
            auto pret = tabel->model()->data(tabel->model()->index(row, 3), Qt::DisplayRole).toString();
            editPret->setText(pret);
        }

    });

}
