#pragma once

#include <QAbstractTableModel>

#include "domain.h"

class MyTableModel : public QAbstractTableModel {
    vector<Melodie> melodii;
    vector<int>  ranks;
public:
    MyTableModel(const vector<Melodie> melodii, const vector<int> ranks) : melodii(melodii), ranks(ranks) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return melodii.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 5;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if(role == Qt::DisplayRole) {
            Melodie c = melodii[index.row()];
            if(index.column()==0) {
                return QString::number(c.get_id());
            }
            else if(index.column()==1) {
                return QString::fromStdString(c.get_titlu());
            }
            else if(index.column()==2) {
                return QString::fromStdString(c.get_artist());
            }
            else if(index.column()==3) {
                return QString::number(c.get_rank());
            }
            else if(index.column()==1) {
                return QString::number(ranks[c.get_rank()]);
            }
        }
        return QVariant{};
    }

    void set_melodii(const vector<Melodie> melodi, vector<int> fr) {
        melodii = melodi;
        ranks = fr;
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount(), columnCount());
        emit layoutChanged();
        emit dataChanged(topLeft, bottomRight);
    }


};

