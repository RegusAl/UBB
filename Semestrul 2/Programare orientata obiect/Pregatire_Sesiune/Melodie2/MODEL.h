#pragma once

#include <QAbstractTableModel>
#include "domain.h"
#include "service.h"

class MyTableModel : public QAbstractTableModel {
    vector<Melodie> melodii;
public:
    MyTableModel(const vector<Melodie> melodii) : melodii(melodii) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return melodii.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if(role == Qt::DisplayRole) {
            Melodie m = melodii[index.row()];
            if(index.column()==0) {
                return QString::number(m.get_id());
            }
            else if(index.column() == 1) {
                return QString::fromStdString(m.get_titlu());
            }
            else if(index.column() == 2) {
                return QString::fromStdString(m.get_artist());
            }
            else if(index.column() == 3) {
                return QString::fromStdString(m.get_gen());
            }
        }
        return QVariant{};
    }

    void set_melodii(const vector<Melodie> mel) {
        melodii = mel;
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount(), columnCount());
        emit layoutChanged();
        emit dataChanged(topLeft, bottomRight);
    }
};

