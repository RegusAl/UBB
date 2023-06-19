#include "GUI.h"

void GUI::init_GUI() {

    this->setLayout(layout);

    model = new MyTableModel(service.getAll());
    tabel->setModel(model);

//    model = new MyListModel(service.getAll());
//    lista->setModel(model);



    layout->addWidget(tabel);
    layout->addWidget(new QLabel("ID"));
    layout->addWidget(editId);
    layout->addWidget(new QLabel("Nume"));
    layout->addWidget(editNume);
    layout->addWidget(new QLabel("Tip"));
    layout->addWidget(editTip);
    layout->addWidget(btnAdaugare);
    layout->addWidget(btnStergere);

}

void GUI::connectSignalSlots() {
    // adaugare
    QObject::connect(btnAdaugare, &QPushButton::clicked, [this] {
        int id = editId->text().toInt();
        string nume = editNume->text().toStdString();
        string tip = editTip->text().toStdString();
        editId->clear();
        editNume->clear();
        editTip->clear();
        service.adaugare(id,nume,tip);
        reload_GUI();
    });
    // selectare item din tabel
    QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [this] {
        if(tabel->selectionModel()->selectedIndexes().isEmpty()) {
            editId->setText("");
            editNume->setText("");
            editTip->setText("");
        } else {
            auto row = tabel->selectionModel()->selectedIndexes().at(0).row();
            auto id = tabel->model()->data(tabel->model()->index(row, 0), Qt::DisplayRole).toString();
            auto nume = tabel->model()->data(tabel->model()->index(row, 1), Qt::DisplayRole).toString();
            auto tip = tabel->model()->data(tabel->model()->index(row, 2), Qt::DisplayRole).toString();
            editId->setText(id);
            editNume->setText(nume);
            editTip->setText(tip);
            reload_GUI();
        }
    });
    // stergere
    QObject::connect(btnStergere, &QPushButton::clicked, [this] {
        if(editId->text().isEmpty() || editNume->text().isEmpty() || editTip->text().isEmpty()) {
            QMessageBox* msgbox = new QMessageBox();
            msgbox->setWindowTitle("Eroare");
            msgbox->setText("Campurile nu sunt valide!");
            msgbox->exec();
        } else {
            service.stergere(editId->text().toInt(), editNume->text().toStdString(), editTip->text().toStdString());
            editId->clear();
            editNume->clear();
            editTip->clear();
            reload_GUI();
        }
    });

}

void GUI::reload_GUI() {
    model->setEntitati(service.getAll());
}
