#ifndef DATAS_H
#define DATAS_H

#include <QWidget>
#include "QSqlTableModel"
#include "QSqlDatabase"
#include "ischodn_dannie.h"
#include <QButtonGroup>
#include <QDialog>

class MainWindow;

namespace Ui {
class datas;
}

class datas : public QWidget
{
    Q_OBJECT

public:
    explicit datas(QWidget *parent = nullptr);
    ~datas();

public slots:
    void on_enterDannie_clicked();
    void on_deleteDannie_clicked();
    void on_saveDannie_clicked();

private slots:





public:
    Ui::datas *ui;
    void zapis();
    void table();
    MainWindow *wf;
private:
    QSqlDatabase sdb;
    QString dataSourceFilename;
    ischodn_dannie *isdn;
    QSqlTableModel *model;

};

#endif // DATAS_H
