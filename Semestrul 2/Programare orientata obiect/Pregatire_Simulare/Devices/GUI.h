#pragma once

#include "service.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QModelIndexList>

#include <vector>


class GUI : public QWidget {
private:
    Service &service;



    QListWidget *listaDeviceuri;

    QPushButton* btnSortareModel;
    QPushButton* btnSortarePret;
    QPushButton* btnNesortat;

    QLineEdit* ModelAn;


    void init();
    void connectSignalSlots();
    void reload(vector<Device> deviceuri);

public:
    GUI(Service& srv) : service{srv} {
        init();
        connectSignalSlots();
        reload(srv.getAll());
    }
};