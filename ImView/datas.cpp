#include "datas.h"
#include "qtextedit.h"
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
#include "multilinedelegate.h"
#include "resizedelegate.h"

datas::datas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::datas)
{
    ui->setupUi(this);

    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(QFileInfo("../data/base_db/mydb.db").absoluteFilePath());

    table();
}

datas::~datas()
{
    delete ui;
}

//void datas::on_pushButton_clicked()
//{
//    zapis();
//    table();
//}

void datas::table()
{
    model = new QSqlTableModel;
    model->setTable("dvigatels");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    QSortFilterProxyModel *proxy1=new QSortFilterProxyModel();
    proxy1->setSourceModel(model);

    QStandardItemModel *modd=new QStandardItemModel();

    for (int z =0; z< proxy1->rowCount(); ++z)
    {
        for (int y =0; y< proxy1->columnCount(); ++y)
        {
            QStandardItem *item= new QStandardItem();
            item->setText(proxy1->index(z,y).data().toString());
            item->setTextAlignment(Qt::AlignCenter);
            modd->setItem(z,y,item);
        }
    }

    ui->tableView->setModel(modd);
    //ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true); //скрытие колонки id
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //выделение строки
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //выделение одной строки


    modd->setHeaderData(1, Qt::Horizontal, "Марка двигателя", Qt::DisplayRole);
    modd->setHeaderData(2, Qt::Horizontal, "Номинальная мощность двигателя, кВтeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", Qt::DisplayRole);
    modd->setHeaderData(3, Qt::Horizontal, "Номинальная частота вращения, об/мин", Qt::DisplayRole);
    modd->setHeaderData(4, Qt::Horizontal, "Номинальное напряжение фазы, В", Qt::DisplayRole);
    modd->setHeaderData(5, Qt::Horizontal, "Номинальный коэффициент мощности", Qt::DisplayRole);
    modd->setHeaderData(6, Qt::Horizontal, "Номинальный коэффициент полезного действия", Qt::DisplayRole);
    modd->setHeaderData(7, Qt::Horizontal, "Кратность максимального момента", Qt::DisplayRole);
    modd->setHeaderData(8, Qt::Horizontal, "Номинальное напряжение питания", Qt::DisplayRole);
    modd->setHeaderData(9, Qt::Horizontal, "Синхронная частота вращения, об/мин", Qt::DisplayRole);

    QHeaderView *header=ui->tableView->horizontalHeader();
    for(int i=1;i<=8;i++)
    {
        header->setSectionResizeMode(i,QHeaderView::ResizeToContents);
    }

    ui->tableView->setWordWrap(true);
    ui->tableView->setTextElideMode(Qt::ElideMiddle);
    ui->tableView->resizeRowsToContents();

    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->rowHeight(0));
    ui->tableView->verticalHeader()->hide();



    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


   TextEditDelegate* textEditdelegate = new TextEditDelegate(this); //создание делегата для создания комбобоксов
   for(int i=1;i<=8;i++)
   {
        ui->tableView->setItemDelegateForColumn(i, textEditdelegate);
   }
   ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter | (Qt::Alignment)Qt::TextWordWrap);
   ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void datas::zapis()
{
    QSqlQuery query=QSqlQuery(sdb);
    query.prepare("INSERT INTO dvigatels (id, name, pn, n, un, cosf, kpd, mk, n0) "
                  "VALUES (:id, :name, :pn, :n, :un, :cosf, :kpd, :mk, :n0)");
    query.bindValue(":id", QVariant(QVariant::String));
    query.bindValue(":name", QString(base.name));
    query.bindValue(":pn",QString("%1").arg(base.P_nom, 0, 'f', 3));
    query.bindValue(":n",QString("%1").arg(base.n_nom, 0, 'f', 3));
    query.bindValue(":un",QString("%1").arg(base.U_fnom, 0, 'f', 3));
    query.bindValue(":cosf",QString("%1").arg(base.cosf_nom, 0, 'f', 3));
    query.bindValue(":kpd",QString("%1").arg(base.kpd_nom, 0, 'f', 3));
    query.bindValue(":mk",QString("%1").arg(base.muk, 0, 'f', 3));
    query.bindValue(":n0",QString("%1").arg(base.n_0, 0, 'f', 3));
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
        QMessageBox::critical(this, "Ошибка!", "Выберите необходимую строку");
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
//    zapis();
//    table();

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







