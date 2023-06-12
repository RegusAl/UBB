#pragma once
#include "domain.h"
#include "service.h"

#include <QAbstractTableModel>
#include <QBrush>
#include <Qt>

using std::vector;

class MyTableModel : public QAbstractTableModel {
private:
    vector<Produs> produse;
    int nr;
public:
    MyTableModel(const vector<Produs> produse, int nr) : produse(produse), nr(nr) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return produse.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 5;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if(role == Qt::BackgroundRole) {
            auto p = produse[index.row()];
            int pret = p.get_pret();
            int row = index.row();
            if(pret <= nr) {
                QBrush bg(Qt::darkRed);
                return bg;
            }
        }

        if(role==Qt::DisplayRole) {
            Produs p = produse[index.row()];
            if(index.column()==0) {
                return QString::number(p.get_id());
            }
            if(index.column()==1) {
                return QString::fromStdString(p.get_nume());
            }
            if(index.column()==2) {
                return QString::fromStdString(p.get_tip());
            }
            if(index.column()==3) {
                return QString::number(p.get_pret());
            }
            if(index.column()==4) {
                return QString::number(p.get_vocale());
            }
        }
        return QVariant{};

    }

    void setProduse(vector<Produs> produse, int nr) {
        this->produse = produse;
        this->nr = nr;
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount(), columnCount());
        emit layoutChanged();
        emit dataChanged(topLeft, bottomRight);
    }
};

