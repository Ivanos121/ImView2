#ifndef MYSORTFILTERPROXYMODEL_H
#define MYSORTFILTERPROXYMODEL_H

#include "qnamespace.h"
#include "qvariant.h"

#include <QSortFilterProxyModel>
class MySortFilterProxyModel Q_DECL_FINAL : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    MySortFilterProxyModel(QObject *parent)
        : QSortFilterProxyModel(parent)
    {
    }

protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const Q_DECL_OVERRIDE
    {
        QVariant leftData = sourceModel()->data(left);
        QVariant rightData = sourceModel()->data(right);
        // Do custom logic in here, e.g.:
        return QString::localeAwareCompare(leftData.toString(), rightData.toString()) < 0;
    }
};

#endif // MYSORTFILTERPROXYMODEL_H
