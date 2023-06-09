#pragma once
#include "service.h"

#include <Qt>
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QTableWidgetItem>
#include <QString>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class GUI:public QWidget {
private:
    Service& service;

    QTableWidget* tabel = new QTableWidget;
    QVBoxLayout* mainLayout = new QVBoxLayout;

    QLineEdit* titluMelodie = new QLineEdit;
    QPushButton* butonUpdate = new QPushButton;
    QPushButton* butonDelete = new QPushButton;

    QSlider* sliderRank = new QSlider(Qt::Horizontal);

    void init_GUI();
    void reload_GUI();
    void connect_slots();
    void paintEvent(QPaintEvent* ev) override;

public:
    GUI(Service& service) : service(service) {
        init_GUI();
        connect_slots();
    };
};