#include "mysvgwidget.h"
#include <QHBoxLayout>
#include "start_app.h"
#include "ui_start_app.h"

MySvgWidget::MySvgWidget(QWidget *parent) : QSvgWidget(parent)
{


}

void MySvgWidget::enterEvent(QEvent *event)
{
    QSvgWidget::enterEvent(event);
    QWidget *widget = new QWidget();
    QSvgWidget *svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96_id_select.svg");
    QHBoxLayout *layout = new QHBoxLayout(widget);
    layout->addWidget(svgwidget);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(0,0,0,0);
    //(static_cast<Start_app*>(this->parent()))->ui->tableWidget_2->setCellWidget(0, 0, widget);
}

void MySvgWidget::leaveEvent(QEvent *event)
{
    QSvgWidget::leaveEvent(event);
    QWidget *widget = new QWidget();
    QSvgWidget *svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96_id.svg");
    QHBoxLayout *layout = new QHBoxLayout(widget);
    layout->addWidget(svgwidget);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(0,0,0,0);
    //(static_cast<Start_app*>(this->parent()))->ui->tableWidget_2->setCellWidget(0, 0, widget);
}


