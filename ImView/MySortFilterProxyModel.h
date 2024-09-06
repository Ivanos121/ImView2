#ifndef MYSORTFILTERPROXYMODEL_H
#define MYSORTFILTERPROXYMODEL_H

#include "qnamespace.h"
#include "qvariant.h"

#include <QSortFilterProxyModel>

class MySortFilterProxyModel: public QSortFilterProxyModel
{
    Q_OBJECT

public:
    MySortFilterProxyModel(QObject *parent = nullptr);

protected:
    virtual bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;
};

#endif // MYSORTFILTERPROXYMODEL_H
