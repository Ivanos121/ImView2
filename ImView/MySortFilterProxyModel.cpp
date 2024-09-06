#include "MySortFilterProxyModel.h"
#include <QDateTime>

MySortFilterProxyModel::MySortFilterProxyModel(QObject *parent) : QSortFilterProxyModel(parent)
{

}

bool MySortFilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QVariant leftData = sourceModel()->data(left);
    QVariant rightData = sourceModel()->data(right);
    // Do custom logic in here, e.g.:
    return (leftData.toDouble() < rightData.toDouble());
    //return QString::localeAwareCompare(leftData.toString(), rightData.toString()) < 0;
}
