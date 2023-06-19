#include "domain.h"

#include <QAbstractTableModel>

class MyTableModel : public QAbstractListModel {
private:
    vector<Entitate> entitati;
public:

    MyTableModel(const vector<Entitate> entitati) : entitati(entitati) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return entitati.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 3;
    }

    QVariant data(const QModelIndex& index = QModelIndex(), int role = Qt::DisplayRole) const override {
        if(role == Qt::DisplayRole) {
            Entitate e = entitati[index.row()];
            if(index.column() == 0) {
                return QString::number(e.getId());
            }
            if(index.column() == 1) {
                return QString::fromStdString(e.getNume());
            }
            if(index.column() == 2) {
                return QString::fromStdString(e.getTip());
            }
        }
        return QVariant{};
    }

    void setEntitati(vector<Entitate> e) {
        entitati = e;
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount(), columnCount());
        emit layoutChanged();
        emit dataChanged(topLeft, bottomRight);
    }
};