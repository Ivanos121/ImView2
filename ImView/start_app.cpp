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
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView :: SingleSelection);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();

    //Настрока меню быстрого открытия файлов
    recentFileActs[0] = ui->tableWidget->item(0,1);
    recentFileActs[1] = ui->tableWidget->item(1,1);
    recentFileActs[2] = ui->tableWidget->item(2,1);
    recentFileActs[3] = ui->tableWidget->item(3,1);
    recentFileActs[4] = ui->tableWidget->item(4,1);
    recentFileActs[5] = ui->tableWidget->item(5,1);
    recentFileActs[6] = ui->tableWidget->item(6,1);
    recentFileActs[7] = ui->tableWidget->item(7,1);

    for (int i = 0; i < MaxRecentFiles; i++)
    {
        connect(recentFileActs[i], &QTableWidgetItem::setSelected, this, &Start_app::openRecentFile);
    }

    svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96.svg");
    svgwidget->setMaximumSize(100,100);


    for(int row = 0; row<ui->tableWidget->rowCount()-2; row++)
    {
        for(int column = 0; column<ui->tableWidget->columnCount(); column++)
        {
            ui->tableWidget->setItem(row, column, new QTableWidgetItem());
        }
    }

    // for (int i=0; i<ui->tableWidget->rowCount()-2; i++)
    // {
    //     if (ui->tableWidget->item(i, 0) != 0)
    //     {
    //         svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96.svg");
    //         svgwidget->setMaximumSize(100,100);
    //         ui->tableWidget->setCellWidget(i, 0, svgwidget);
    //         ui->tableWidget->resizeRowToContents(i);
    //         ui->tableWidget->resizeColumnToContents(i);
    //     }
    // }

    // for (int i=0; i<ui->tableWidget->rowCount()-2; i++)
    // {
    //     QString w1, w2,w3;

    //     w1= "zxc8.imview";

    //     QDateTime currentDateTime = QDateTime::currentDateTime();
    //     QTime currentTime = currentDateTime.time();
    //     QDate currentDate = currentDateTime.date();

    //     w2= QString("%1""%2""%3").arg("Сеанс ",currentTime.toString("hh:mm:ss ").toUtf8().data(),
    //         currentDate.toString("dd.MM.yyyy").toUtf8().data());

    //     w3="/home/elf/ImView2/Output";

    //     if (ui->tableWidget->item(i, 1) != 0)
    //     {
    //         ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString("%1 \n %2 \n %3").arg(w1).arg(w2).arg(w3)));
    //     }
    // }


    for (int i=0; i<ui->tableWidget->rowCount()-2; i++)
    {
         if (ui->tableWidget->item(i, 1) != 0)
        {
            ui->tableWidget->item(i, 1)->setTextAlignment(Qt::AlignLeft);
            ui->tableWidget->item(i, 1)->setTextAlignment(Qt::AlignVCenter);
        }
    }

    for(int row = 0; row<ui->tableWidget->rowCount()-2; row++)
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
    ui->label_2->setStyleSheet("QLabel { color : rgb(0, 0, 0)); }");

    ui->label->setText("<a href=\"whatever\">Справка</a>");
    ui->label->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label->setStyleSheet("QLabel { color : rgb(0, 0, 0)); }");

    ui->label_16->setText("<a href=\"whatever\">Создать</a>");
    ui->label_16->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_16->setStyleSheet("QLabel { color : rgb(0, 0, 0)); }");

    connect(ui->label_2,&QLabel::linkActivated, this, &Start_app::click_open_file);
    connect(ui->tableWidget,&QTableWidget::itemActivated,this,&Start_app::click_open_progect);
    connect(ui->tableWidget_2,&QAbstractItemView::clicked,this,&Start_app::click_open_progect_2);

    ui->tableWidget_2->setRowCount(4);
    ui->tableWidget_2->setColumnCount(5);
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->tableWidget->setSelectionBehavior(QAbstractItemView :: SelectRows);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView :: SingleSelection);
    //ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->horizontalHeader()->hide();
    ui->tableWidget_2->verticalHeader()->hide();
    //ui->tableWidget_2->resizeRowsToContents();
    ui->tableWidget_2->verticalHeader()->hide();
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    for(int row = 0; row<ui->tableWidget_2->rowCount(); row++)
    {
        for(int column = 0; column<ui->tableWidget_2->columnCount(); column++)
        {
            ui->tableWidget_2->setItem(row, column, new QTableWidgetItem());
        }
        //ui->tableWidget_2->setRowHeight(row, 300);
    }

    for (int i=0; i<ui->tableWidget_2->columnCount(); i++)
    {
        if (ui->tableWidget_2->item(1, i) != 0)
        {
            ui->tableWidget_2->item(1, i)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_2->item(1, i)->setTextAlignment(Qt::AlignVCenter);
        }
        if (ui->tableWidget_2->item(3, i) != 0)
        {
            ui->tableWidget_2->item(3, i)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_2->item(3, i)->setTextAlignment(Qt::AlignVCenter);
        }

    }

    ui->tableWidget_2->setItem(1, 0, new QTableWidgetItem("Идентификация параметров "));
    ui->tableWidget_2->setItem(1, 2, new QTableWidgetItem("Электромагнитная модель"));
    ui->tableWidget_2->setItem(1, 4, new QTableWidgetItem("Тепловая модель"));
    ui->tableWidget_2->setItem(3, 0, new QTableWidgetItem("Вентиляционная модель"));
    ui->tableWidget_2->setItem(3, 2, new QTableWidgetItem("Прогноз температур"));
    ui->tableWidget_2->setItem(3, 4, new QTableWidgetItem("Остаточный тепловой ресурс"));

    QWidget *widget = new QWidget();
    svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96_id.svg");
    //svgwidget->setMaximumSize(300,300);
    QHBoxLayout *layout = new QHBoxLayout(widget);
    layout->addWidget(svgwidget);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(0,0,0,0);
    ui->tableWidget_2->setCellWidget(0, 0, widget);
    //ui->tableWidget_2->resizeRowToContents(0);
    //ui->tableWidget_2->resizeColumnToContents(0);
    ui->tableWidget_2->item(1, 0)->setTextAlignment(Qt::AlignCenter);

    QWidget *widget2 = new QWidget();
    svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96_elm.svg");
    //svgwidget->setMaximumSize(300,300);
    QHBoxLayout *layout2 = new QHBoxLayout(widget2);
    layout2->addWidget(svgwidget);
    layout2->setAlignment(Qt::AlignCenter);
    layout2->setContentsMargins(0,0,0,0);
    ui->tableWidget_2->setCellWidget(0, 2, widget2);
    //ui->tableWidget_2->resizeColumnToContents(1);
    //ui->tableWidget_2->resizeRowToContents(0);
    ui->tableWidget_2->item(1, 2)->setTextAlignment(Qt::AlignCenter);


    QWidget *widget3 = new QWidget();
    svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96_tm.svg");
    //svgwidget->setMaximumSize(300,300);
    QHBoxLayout *layout3 = new QHBoxLayout(widget3);
    layout3->addWidget(svgwidget);
    layout3->setAlignment(Qt::AlignCenter);
    layout3->setContentsMargins(0,0,0,0);
    ui->tableWidget_2->setCellWidget(0, 4, widget3);
    //ui->tableWidget_2->resizeColumnToContents(2);
    ui->tableWidget_2->item(1, 4)->setTextAlignment(Qt::AlignCenter);

    QWidget *widget4 = new QWidget();
    svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96_vm.svg");
    //svgwidget->setMaximumSize(300,300);
    QHBoxLayout *layout4 = new QHBoxLayout(widget4);
    layout4->addWidget(svgwidget);
    layout4->setAlignment(Qt::AlignCenter);
    layout4->setContentsMargins(0,0,0,0);
    ui->tableWidget_2->setCellWidget(2, 0, widget4);
    //ui->tableWidget_2->resizeRowToContents(2);
    ui->tableWidget_2->item(3, 0)->setTextAlignment(Qt::AlignCenter);


    QWidget *widget5 = new QWidget();
    svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96_vm.svg");
    //svgwidget->setMaximumSize(300,300);
    QHBoxLayout *layout5 = new QHBoxLayout(widget5);
    layout5->addWidget(svgwidget);
    layout5->setAlignment(Qt::AlignCenter);
    layout5->setContentsMargins(0,0,0,0);
    ui->tableWidget_2->setCellWidget(2, 2, widget5);
    ui->tableWidget_2->item(3, 2)->setTextAlignment(Qt::AlignCenter);

    QWidget *widget6 = new QWidget();
    svgwidget = new QSvgWidget("/home/elf/ImView2/data/img/system_icons/IM_96x96_tr.svg");
    //svgwidget->setMaximumSize(300,300);
    QHBoxLayout *layout6 = new QHBoxLayout(widget6);
    layout6->addWidget(svgwidget);
    layout6->setAlignment(Qt::AlignCenter);
    layout6->setContentsMargins(0,0,0,0);
    ui->tableWidget_2->setCellWidget(2, 4, widget6);
    ui->tableWidget_2->item(3, 4)->setTextAlignment(Qt::AlignCenter);

    for(int row = 0; row<ui->tableWidget_2->rowCount(); row++)
    {
        if (ui->tableWidget_2->item(row,1) != 0)
        {
            ui->tableWidget_2->item(row,1)->setFlags(Qt::ItemIsDragEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        }
        if (ui->tableWidget_2->item(row,3) != 0)
        {
            ui->tableWidget_2->item(row,3)->setFlags(Qt::NoItemFlags);
        }
    }

    ui->tableWidget_2->item(1,0)->setFlags(Qt::ItemIsDragEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
    ui->tableWidget_2->item(1,2)->setFlags(Qt::NoItemFlags);
    ui->tableWidget_2->item(1,4)->setFlags(Qt::NoItemFlags);
    ui->tableWidget_2->item(3,0)->setFlags(Qt::NoItemFlags);
    ui->tableWidget_2->item(3,2)->setFlags(Qt::NoItemFlags);
    ui->tableWidget_2->item(3,4)->setFlags(Qt::NoItemFlags);


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

    QString str = save_progect.progect_1.path_1 + "/" + save_progect.progect_1.name_1;
    wf->LoadProject(str);
}

void Start_app::click_open_progect_2(const QModelIndex& idx)
{
    int x = idx.row();
    int y = idx.column();

    if((x==0)&&(y==0))
    {
        QMessageBox::critical(this,tr("Ахтунг"),tr("Открывается идентификация"));
    }

    int c = 0,d = 2;
    if((c == x) && (d == y))
    {
        QMessageBox::critical(this,tr("Ахтунг"),tr("Открывается эл магн модель"));
    }

    int e = 0,f = 4;
    if((e == x) && (f == y))
    {
        QMessageBox::critical(this,tr("Ахтунг"),tr("Открывается тепл модель"));
    }

    int g = 2, h = 0;
    if((g == x) && (h == y))
    {
        QMessageBox::critical(this,tr("Ахтунг"),tr("Открывается вент модель"));
    }

    int m = 2, n = 2;
    if((m == x) && (n == y))
    {
        QMessageBox::critical(this,tr("Ахтунг"),tr("Открывается темп прогноз"));
    }

    int o = 2, p = 4;
    if((o == x) && (p == y))
    {
        QMessageBox::critical(this,tr("Ахтунг"),tr("Открывается темп ресурс"));
    }
}

void Start_app::resizeEvent(QResizeEvent *event)
{
    for(int row = 0; row<ui->tableWidget_2->rowCount(); row++)
    {
        if ((row == 1) || (row == 3))
        {
            ui->tableWidget_2->setRowHeight(row, 30);
        }
        else
        {
            int max_height = (height() - 60 - ui->label_3->height() - ui->label_16->height() - 60) / 2;
            int height = ui->tableWidget_2->columnWidth(0);
            if (height > max_height)
            {
                height = max_height;
            }
            ui->tableWidget_2->setRowHeight(row, height);
        }
    }
}

void Start_app::openRecentFile()
{
    QTableWidgetItem *item = qobject_cast<QTableWidgetItem *>(sender());
    if (item)
    {
        QString fileName = item->data(Qt::DisplayRole).toString();
        wf->loadFile(fileName);
    }
}

void Start_app::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    setWindowFilePath(curFile);

    QSettings settings("BRU", "IM View");
    QStringList files = settings.value("recentFileList").toStringList();
    files.removeAll(fileName);
    files.prepend(fileName);
    while (files.size() > MaxRecentFiles)
        files.removeLast();

    settings.setValue("recentFileList", files);

    foreach (QWidget *widget, QApplication::topLevelWidgets())
    {
        MainWindow *mainWin = qobject_cast<MainWindow *>(widget);
        if (mainWin)
            mainWin->updateRecentFileActions();
    }
}

void Start_app::updateRecentFileActions()
{
    QSettings settings("BRU", "IM View");
    QStringList files = settings.value("recentFileList").toStringList();

    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);

    for (int i = 0; i < numRecentFiles; ++i) {
        QString text = tr("&%1 %2").arg(i + 1).arg(strippedName(files[i]));
        recentFileActs[i]->setText(text);
        recentFileActs[i]->setData(Qt::UserRole, files[i]);
        //recentFileActs[i]->setVisible(true);
    }
    // for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
    //     recentFileActs[j]->setVisible(false);

    // recentFileActs[MaxRecentFiles-1]->setVisible(numRecentFiles > 0);
}

QString Start_app::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
