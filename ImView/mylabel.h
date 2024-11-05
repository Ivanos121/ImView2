#ifndef MYLABEL_H
#define MYLABEL_H

#include "qevent.h"
#include <QLabel>


class MyLabel : public QLabel {
    Q_OBJECT
public:
    MyLabel(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void clicked();
};

#endif // MYLABEL_H
