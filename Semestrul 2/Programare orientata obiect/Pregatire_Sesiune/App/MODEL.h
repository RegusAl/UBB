#include "domain.h"
#include "repository.h"

#include "Qt"
#include "QAbstractTableModel"

class MyTableModel: public QAbstractTableModel {
    vector<Produs> produse;
public:
    MyTableModel(const vector<Produs> produse) : produse(produse) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return produse.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if(role == Qt::DisplayRole) {
            Produs p = produse[index.row()];
            if(index.column() == 0) {
                return QString::number(p.get_id());
            }
            if(index.column() == 1) {
                return QString::fromStdString(p.get_titlu());
            }
            if(index.column() == 2) {
                return QString::fromStdString(p.get_tip());
            }
            if(index.column() == 3) {
                return QString::number(p.get_pret());
            }
        }
        return QVariant{};
    }

    void setProduse(const vector<Produs> p) {
        produse = p;
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount(), columnCount());
        emit layoutChanged();
        emit dataChanged(topLeft, bottomRight);
    }
};