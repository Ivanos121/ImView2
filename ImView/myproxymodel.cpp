#include "myproxymodel.h"

MyProxyModel::MyProxyModel(QObject *parent) :QIdentityProxyModel(parent)
{

}

QVariant data(const QModelIndex &index, int role)
{
    if (role == Qt::TextAlignmentRole) {
        return Qt::AlignCenter;
    }
    return MyProxyModel::data(index, role);
}
