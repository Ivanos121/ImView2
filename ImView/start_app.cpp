#include "start_app.h"
#include "mainwindow.h"
#include "save_progect.h"
#include "ui_start_app.h"

#include <QDesktopServices>
#include <QFileDialog>
#include <QSettings>
#include <QSvgWidget>
#include <QUrl>

Save_progect save_progect;

Start_app::Start_app(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Start_app)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(2);
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->tableWidget->setSelectionBehavior(QAbstractItemView :: SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView :: SingleSelection);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();

    svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96.svg");
    svgwidget->setMaximumSize(100,100);


    for(int row = 0; row<ui->tableWidget->rowCount(); row++)
    {
        for(int column = 0; column<ui->tableWidget->columnCount(); column++)
        {
            ui->tableWidget->setItem(row, column, new QTableWidgetItem());
        }
    }

    for (int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        if (ui->tableWidget->item(i, 0) != 0)
        {
            svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96.svg");
            svgwidget->setMaximumSize(100,100);
            ui->tableWidget->setCellWidget(i, 0, svgwidget);
            ui->tableWidget->resizeRowToContents(i);
            ui->tableWidget->resizeColumnToContents(i);
        }
    }

    for (int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QString w1, w2,w3;

        w1= "zxc.imview";

        QDateTime currentDateTime = QDateTime::currentDateTime();
        QTime currentTime = currentDateTime.time();
        QDate currentDate = currentDateTime.date();

        w2= QString("%1""%2""%3").arg("Сеанс ",currentTime.toString("hh:mm:ss ").toUtf8().data(),
            currentDate.toString("dd.MM.yyyy").toUtf8().data());

        w3="../Output";

        if (ui->tableWidget->item(i, 1) != 0)
        {            
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString("%1 \n %2 \n %3").arg(w1).arg(w2).arg(w3)));
        }
    }


    for (int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        //ui->tableWidget->resizeRowToContents(i);
        if (ui->tableWidget->item(i, 1) != 0)
        {
            ui->tableWidget->item(i, 1)->setTextAlignment(Qt::AlignLeft);
            ui->tableWidget->item(i, 1)->setTextAlignment(Qt::AlignVCenter);
        }
    }

    for(int row = 0; row<ui->tableWidget->rowCount(); row++)
    {
        if (ui->tableWidget->item(row,0) != 0)
        {
            ui->tableWidget->item(row,0)->setFlags(Qt::NoItemFlags);
        }
        if (ui->tableWidget->item(row,1) != 0)
        {
            ui->tableWidget->item(row,1)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        }
    }
    ui->label_2->setText("<a href=\"whatever\">Открыть файл сохранения</a>");
    ui->label_2->setTextInteractionFlags(Qt::TextBrowserInteraction);
    connect(ui->label_2,&QLabel::linkActivated, this, &Start_app::click_open_file);
    connect(ui->tableWidget,&QTableWidget::itemActivated,this,&Start_app::click_open_progect);

}

Start_app::~Start_app()
{
    delete ui;
}

void Start_app::click_open_file()
{
   // QDesktopServices::openUrl(QUrl("http://www.example.com/"));
    wf->open_file();
}

void Start_app::click_open_progect()
{
    QSettings settings( "BRU", "IM View");
    //settings.setValue( "name_1", "zxc8.imview");
    //settings.setValue( "path_1", "../Output");
    //settings.setValue( "id", 0);
    //QMessageBox::critical(this, tr("ghbdtn"),tr("ddddd"));
    QList<QString> name = { "name_1", "name_2", "name_3", "name_4", "name_5", "name_6", "name_7", "name_8", "name_9", "name_10" };
    QList<QString> path = { "path_1", "path_2", "path_3", "path_4", "path_5", "path_6", "path_7", "path_8", "path_9", "path_10" };
    QList<QString> id = { "id_1", "id_2", "id_3", "id_4", "id_5", "id_6", "id_7", "id_8", "id_9", "id_10" };

    for (int i = 0; i < name.size(); ++i)
    {
        if (name.at(i) == "name_1")
        save_progect.progect_1.name_1 = settings.value( "name_1", "").toString();
    }

    for (int i = 0; i < path.size(); ++i)
    {
        if (path.at(i) == "path_1")
            save_progect.progect_1.path_1 = settings.value( "path_1", "").toString();
    }
    for (int i = 0; i < id.size(); ++i)
    {
        if (id.at(i) == "id_1")
            save_progect.progect_1.id_1 = settings.value( "id_1", "").toInt();
    }

    QString str = save_progect.progect_1.name_1;

    QFile file;
    file.setFileName(save_progect.progect_1.name_1);
    QDir::setCurrent(save_progect.progect_1.path_1);
    file.open(QIODevice::ReadOnly);

    wf->LoadProject(str);


}
