#include "mylabel.h"

#include <QDesktopServices>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
    QLabel::mousePressEvent(event);
}
