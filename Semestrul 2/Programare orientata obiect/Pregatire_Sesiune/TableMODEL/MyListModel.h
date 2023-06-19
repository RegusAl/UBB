#include "domain.h"

#include "QAbstractListModel"

class MyListModel : public QAbstractListModel {
private:
    vector<Entitate> entitati;

public:
    MyListModel(const vector<Entitate> entitatati) : entitati(entitatati) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return entitati.size();
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if(role == Qt::DisplayRole) {
            Entitate e = entitati[index.row()];
            return QString::number(e.getId()) + QString::fromStdString(e.getNume());
        }
        return QVariant{};
    }

    void setEntitati(vector<Entitate> e) {
        entitati = e;
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount(), 0);
        emit layoutChanged();
        emit dataChanged(topLeft, bottomRight);
    }
};