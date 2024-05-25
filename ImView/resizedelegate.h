#ifndef DELEGATE_H
#define DELEGATE_H

#include <QItemDelegate>

class TextEditDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    TextEditDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void    drawDisplay(QPainter *painter, const QStyleOptionViewItem &option,
                        const QRect &rect, const QString &text) const;
};

#endif
