#ifndef MYLABEL_H
#define MYLABEL_H

#include "qevent.h"
#include <QLabel>


class MyLabel : public QLabel {
    Q_OBJECT
public:
    MyLabel(const QString &text, QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // MYLABEL_H
