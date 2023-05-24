#include "GUI.h"

void GUI::init() {

    QVBoxLayout* lyMain = new QVBoxLayout;
    this->setLayout(lyMain);

    this->listaDeviceuri = new QListWidget();
    listaDeviceuri->clear();
    for(auto d : service.getAll()) {
        auto item = new QListWidgetItem(QString::fromStdString(d.getTip() + " " + d.getModel() + " ( " + to_string(d.getPret())) + " )");
        this->listaDeviceuri->addItem(item);
    }

    btnSortareModel = new QPushButton("Sortare Model");
    btnSortarePret = new QPushButton("Sortare Pret");
    btnNesortat = new QPushButton("Nesortat");

    ModelAn = new QLineEdit;

    lyMain->addWidget(listaDeviceuri);
    lyMain->addWidget(btnSortareModel);
    lyMain->addWidget(btnSortarePret);
    lyMain->addWidget(btnNesortat);
    lyMain->addWidget(ModelAn);

}

void GUI::connectSignalSlots() {

    QObject::connect(btnSortareModel, &QPushButton::clicked, [&]() {
       reload(service.sortareModel());
    });

    QObject::connect(btnSortarePret, &QPushButton::clicked, [&]() {
        reload(service.sortarePret());
    });

    QObject::connect(btnNesortat, &QPushButton::clicked, [&]() {
       reload(service.getAll());
    });

    QObject::connect(this->listaDeviceuri, &QListWidget::itemSelectionChanged, [&]() {
        ModelAn->clear();
        QModelIndexList selection = this->listaDeviceuri->selectionModel()->selectedRows();
        QModelIndex index = selection.at(0);
        int indexBun = index.row();
        auto device = service.getAll()[indexBun];
        ModelAn->insert(QString::fromStdString(device.getModel() + " este din anul " + to_string(device.getAn())));
    });

}

void GUI::reload(vector<Device> deviceuri) {
    listaDeviceuri->clear();
    for(auto d : deviceuri) {
        auto item = new QListWidgetItem(QString::fromStdString(d.getTip() + " " + d.getModel() + " ( " + to_string(d.getPret())) + " )");
        if(d.getCuloare()=="rosu") {
            item->setBackground(QColor("red"));
        } else if(d.getCuloare()=="albastru") {
            item->setBackground(QColor("blue"));
        } else if(d.getCuloare()=="negru") {
            item->setBackground(QColor("black"));
        } else if(d.getCuloare()=="galben") {
            item->setBackground(QColor("yellow"));
        }
        this->listaDeviceuri->addItem(item);
    }


}
