#include "datas.h"
#include "qsortfilterproxymodel.h"
#include "qsqlquery.h"
#include "ui_datas.h"
#include "base.h"

#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include "QStandardItemModel"
#include "QStandardItem"
#include <QTableView>
#include <QStyle>
#include <QDesktopWidget>
#include <QPainter>
#include <QIntValidator>
#include <QFileDialog>
#include <QScreen>

datas::datas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::datas)
{
    ui->setupUi(this);

    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(QFileInfo("../data/base_db/mydb.db").absoluteFilePath());

    table();

    ui->widget_2->setVisible(false);
}

datas::~datas()
{
    delete ui;
}

void datas::table()
{
    model = new QSqlTableModel;
    model->setTable("dvigatels");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    QSortFilterProxyModel *proxy1=new QSortFilterProxyModel();
    proxy1->setSourceModel(model);

    modd = new QStandardItemModel();

    for (int z =0; z< proxy1->rowCount(); ++z)
    {
        for (int y =0; y< proxy1->columnCount(); ++y)
        {
            QStandardItem *item= new QStandardItem();

            item->setText(proxy1->index(z,y).data().toString());
            item->setData(proxy1->index(z,y).data().toInt());
            item->setTextAlignment(Qt::AlignCenter);
            modd->setItem(z,y,item);
        }
    }

    ui->tableView->setModel(modd);
    ui->tableView->setColumnHidden(0, true); //скрытие колонки id
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //выделение строки
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //выделение одной строки

    modd->setHeaderData(1, Qt::Horizontal, tr("Марка двигателя"), Qt::DisplayRole);
    modd->setHeaderData(2, Qt::Horizontal, tr("Номинальная мощность двигателя, Вт"), Qt::DisplayRole);
    modd->setHeaderData(3, Qt::Horizontal, tr("Номинальная частота вращения, об/мин"), Qt::DisplayRole);
    modd->setHeaderData(4, Qt::Horizontal, tr("Номинальное напряжение фазы, В"), Qt::DisplayRole);
    modd->setHeaderData(5, Qt::Horizontal, tr("Номинальный коэффициент мощности"), Qt::DisplayRole);
    modd->setHeaderData(6, Qt::Horizontal, tr("Номинальный коэффициент полезного действия"), Qt::DisplayRole);
    modd->setHeaderData(7, Qt::Horizontal, tr("Кратность максимального момента"), Qt::DisplayRole);
    modd->setHeaderData(8, Qt::Horizontal, tr("Синхронная частота вращения, об/мин"), Qt::DisplayRole);
    modd->setHeaderData(9, Qt::Horizontal, tr("Класс изоляции"), Qt::DisplayRole);

    QHeaderView *header=ui->tableView->horizontalHeader();

    for(int i=1;i<=9;i++)
    {
        header->setSectionResizeMode(i,QHeaderView::ResizeToContents);
    }

    for(int i=1;i<=9;i++)
    {
        ui->tableView->horizontalHeader()->setSectionsClickable(i);

    }

    ui->tableView->resizeRowsToContents();
    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter | (Qt::Alignment)Qt::TextWordWrap);
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setFixedHeight(100);
    ui->tableView->setSortingEnabled(true);

}

void datas::zapis()
{
    QSqlQuery query=QSqlQuery(sdb);
    query.prepare("INSERT INTO dvigatels (id, name, pn, n, un, cosf, kpd, mk, n0, ki) "
                  "VALUES (:id, :name, :pn, :n, :un, :cosf, :kpd, :mk, :n0, :ki)");
    query.bindValue(":id", QVariant(QVariant::String));
    query.bindValue(":name", QString(base.name));
    query.bindValue(":pn",QString("%1").arg(base.P_nom, 0, 'f', 3));
    query.bindValue(":n",QString("%1").arg(base.n_nom, 0, 'f', 3));
    query.bindValue(":un",QString("%1").arg(base.U_fnom, 0, 'f', 3));
    query.bindValue(":cosf",QString("%1").arg(base.cosf_nom, 0, 'f', 3));
    query.bindValue(":kpd",QString("%1").arg(base.kpd_nom, 0, 'f', 3));
    query.bindValue(":mk",QString("%1").arg(base.muk, 0, 'f', 3));
    query.bindValue(":n0",QString("%1").arg(base.n_0, 0, 'f', 3));
    query.bindValue(":ki",QString("%1").arg(base.ki));
    if(!query.exec()){
        qDebug() << query.lastError().databaseText();
        qDebug() << query.lastError().driverText();
        return;
    }

}

void datas::on_deleteDannie_clicked()
{
    QItemSelectionModel *selectModel = ui->tableView->selectionModel();
    if(selectModel->selectedRows().isEmpty())
    {
        QMessageBox::critical(this, tr("Ошибка!"), tr("Выберите необходимую строку"));
    }
    else
    {
    QSqlQuery query=QSqlQuery(sdb);
    int rowNumber = ui->tableView->selectionModel()->selection().indexes()[0].row();
    query.prepare("DELETE FROM dvigatels WHERE id=:id");
    query.bindValue(":id", ui->tableView->model()->index(rowNumber, 0).data().toString());
    query.exec();
    table();
    }
}

void datas::on_saveDannie_clicked()
{
    model->database().transaction();
        if(model->submitAll())
            model->database().commit();
        else
            model->database().rollback();
}

void datas::on_enterDannie_clicked()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    isdn=new ischodn_dannie(this);
    isdn->wf = this;
    isdn->exec();
    isdn->setGeometry(
    QStyle::alignedRect(
    Qt::LeftToRight,
    Qt::AlignCenter,
    isdn->size(),
    screen->geometry()));
}







