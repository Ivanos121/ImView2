#ifndef MULTILINEDELEGATE_H
#define MULTILINEDELEGATE_H

#include <QItemDelegate>

class MultilineDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    using QItemDelegate::QItemDelegate;

public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
};

#endif
