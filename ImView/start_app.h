#ifndef START_APP_H
#define START_APP_H

#include "qsvgwidget.h"
#include <QWidget>

class MainWindow;

namespace Ui {
class Start_app;
}

class Start_app : public QWidget
{
    Q_OBJECT

public:
    explicit Start_app(QWidget *parent = nullptr);
    ~Start_app();
    MainWindow *wf;

public slots:
    void click_open_file();
    void click_open_progect();
    void click_open_progect_2(const QModelIndex &idx);
private:
    Ui::Start_app *ui;
    QSvgWidget *svgwidget;
};

#endif // START_APP_H
