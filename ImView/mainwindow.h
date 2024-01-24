#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kalibr.h"
#include <QTimer>
#include <QElapsedTimer>
#include <QWebEngineView>
#include <QTreeWidgetItem>
#include <QStandardItem>
#include "plot.h"

#include "qundostack.h"
#include "ui_about_dialog.h"
#include "ui_settings.h"
#include "pushbuttondelegate.h"
//#include "ui_graph_Settings.h"
#include "ui_settinsKanals.h"

//#include "base_tepl.h"
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);

Q_SIGNALS:
    void timeout(QPrivateSignal);

private slots:
    void on_pushButton_clicked();

private:
    Ui::aboutDialog *ui;
};

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_listWidget_itemSelectionChanged();

private:
    Ui::settings *ui;
};

class SettinsKanals : public QDialog
{
    Q_OBJECT

public:
    explicit SettinsKanals(QWidget *parent = nullptr);

private slots:
    //void on_pushButton_clicked();

private:
    Ui::settinsKanals *ui;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void closeEvent (QCloseEvent *event);
    void LoadProject(QString str);
    QVector<QColor> dataLineColors;
    void setcolorincell(int row, int column);

private slots:
    void on_actionabout_triggered();
    void on_actionExit_triggered();
    void on_actionhelp_triggered();
    void onButtonClicked();
    void onButtonClicked2();
    void titleChanged(const QString &title);
    void on_tabWidget_currentChanged(int index);
    void on_action_5_triggered();
    void on_action_9_triggered();
    void on_action_12_triggered();
    void on_action_15_triggered();
    void on_action_16_triggered();
    void on_action_17_triggered();
    void on_action_19_triggered();
    void on_action_20_triggered();
    void on_action_21_triggered();
    void on_action_22_triggered();
    void on_action_23_triggered();
    void on_action_24_triggered();
    void on_action_25_triggered();
    void on_action_31_triggered();
    void on_action_32_triggered();
    void tabClicked();
    void tabClicked_2();
    void tabClicked_3();
    void tabClicked_4();
    void tabClicked_5();
    void tabClicked_6();
    void itemEdit();
    void TimeOut();

    void modelItemChangedSlot(QStandardItem *item);
    void modelItemChangedSlot_2(QStandardItem *item);
    void modelItemChangedSlot_3(QStandardItem *item);
    void modelItemChangedSlot_4(QStandardItem *item);
    void projectFileSelectedSlot(QString projectFile);
    void projectFileSelectedSlot_2(QString projectFile_2);
    void projectFileSelectedSlot_3(QString projectFile_3);
    void projectFileSelectedSlot_4(QString projectFile_4);
    void projectFileSelectedSlot_5(QString projectFile_5);
    void projectFileSelectedSlot_6(QString projectFile_6);
    void on_SaveProgectToFile_clicked();
    void on_pushButton_5_clicked(bool checked);
    void on_LoadProgect_clicked();
    void on_save_tepl_dannie_clicked();
    void on_save_Vent_dannie_clicked();
    void on_load_tepl_dannie_clicked();
    void on_load_Vent_dannie_clicked();
    void LoadTeplDannie(QString str);
    void LoadVentDannie(QString str);
    void on_tepl_result_clicked();
    void on_vent_result_clicked();
    void createUndoStackAndActions();

    void on_radioButton_toggled(bool checked);
    void on_radioButton_2_toggled(bool checked);
    void on_radioButton_3_toggled(bool checked);
    void on_radioButton_4_toggled(bool checked);
    void on_radioButton_5_toggled(bool checked);
    void on_radioButton_6_toggled(bool checked);
    void on_radioButton_7_toggled(bool checked);
    void on_radioButton_8_toggled(bool checked);
    void on_radioButton_9_toggled(bool checked);
    void on_radioButton_10_toggled(bool checked);

    void on_save_electromagn_graph_file_clicked();

    void on_save_electromagn2_file_clicked();

    void on_save_tepl_graph_file_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_radioButton_11_toggled(bool checked);

    void on_radioButton_12_toggled(bool checked);

    void on_radioButton_13_toggled(bool checked);


public:
    Ui::MainWindow *ui;
    AboutDialog *rsc;
    Kalibr *kalibr;
    Settings *rsc2;
    //SettinsKanals *rsc3;
    QString dataSourceFilename;
    QString dirName;
    bool isChanged = false;

    QTimer *timer;
    QUndoStack *undoStack;
    QAction *undoAction;
    QAction *redoAction;
    QProgressBar *progress;
    QWebEngineView * view;
    QLabel *statusbar_label, *statusbar_label_2, *statusbar_label_3, *statusbar_label_4,
         *statusbar_label_5, *statusbar_label_6, *statusbar_label_7, *statusbar_label_8;

    QTreeWidgetItem *treeItem, *child3, *child, *child2;
    QTreeWidgetItem *currentItem;
    int currentColumn;

    QStandardItem *item1,  *item2,  *item3,  *item4,  *item5,  *item6,  *item7,  *item8;
    QStandardItem *item9,  *item10, *item11, *item12, *item13, *item14, *item15, *item16;
    QStandardItem *item17, *item18, *item19, *item20, *item21, *item22, *item23, *item24;
    QStandardItem *item25, *item26, *item27, *item28, *item29, *item30, *item31, *item32;
    QStandardItem *item33, *item34, *item35, *item36, *item37, *item38, *item39, *item40;
    QStandardItem *item41, *item42, *item43, *item44, *item45, *item46, *item47, *item48;
    QStandardItem *item49, *item50, *item51, *item52, *item53, *item54, *item55, *item56;
    QStandardItem *item57, *item58, *item59, *item60, *item61, *item62, *item63, *item64;
    QStandardItem *item65, *item66, *item67, *item68, *item69, *item70, *item71, *item72;
    QStandardItem *item73, *item74, *item75, *item76, *item77, *item78, *item79, *item80;
    QStandardItem *item81, *item82, *item83, *item84, *item85, *item86, *item87, *item88;
    QStandardItem *item89, *item90, *item91, *item92, *item93, *item94, *item95, *item96;
    QStandardItem *item97, *item98, *item99, *item100, *item101, *item102, *item103, *item104;
    QStandardItem *item105,*item106, *item107, *item108, *item109, *item110, *item111, *item112;
    QStandardItem *item113,*item114, *item115, *item116, *item117, *item118, *item119, *item120;
    QStandardItem *item121,*item122,*item123,*item124,*item125,*item126,*item127,*item128;
    QStandardItem *item129,*item130,*item131,*item132,*item133,*item134,*item135,*item136;
};

#endif // MAINWINDOW_H
