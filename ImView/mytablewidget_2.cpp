#include "mytablewidget_2.h"
#include <QMouseEvent>

MyTableWidget_2::MyTableWidget_2(QWidget *parent) : QTableWidget(parent)
{

}

void MyTableWidget_2::enterEvent(QEvent *event)
{
    QTableWidget::enterEvent(event);
    QIcon hoverIcon("/home/elf/ImView2/data/img/system_icons/IM_96x96_elm_select.svg");  // Замените на путь к иконке при наведении
    item(1, 2)->setIcon(hoverIcon);
}

void MyTableWidget_2::leaveEvent(QEvent *event)
{
    QTableWidget::leaveEvent(event);
    QIcon icon("/home/elf/ImView2/data/img/system_icons/IM_96x96_elm.svg");  // Замените на путь к вашему изображению
    item(1, 2)->setIcon(icon);
}


