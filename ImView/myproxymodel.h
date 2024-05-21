#ifndef MYPROXYMODEL_H
#define MYPROXYMODEL_H

#include <QIdentityProxyModel>
#include <QDebug>

class MyProxyModel : public QIdentityProxyModel
{
    Q_OBJECT

public:
    MyProxyModel(QObject* parent = 0);

public slots:
    QVariant data(const QModelIndex &index, int role);
};
#endif // MYPROXYMODEL_H
