#ifndef START_APP_H
#define START_APP_H

#include "qabstractitemmodel.h"
#include "qsvgwidget.h"
#include "qtablewidget.h"
#include "qwebengineview.h"
#include "mylabel.h"
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
    enum { MaxRecentFiles = 8 };
    QTableWidgetItem *recentFileActs[MaxRecentFiles];
    QString curFile;
    QWebEngineView * view;
    MyLabel * mylabel;

public slots:
    void click_open_file();
    void click_open_progect();
    void click_open_progect_2(const QModelIndex &idx);
    QString strippedName(const QString &fullFileName);
    void titleChanged(const QString &title);


public:
    Ui::Start_app *ui;
    QSvgWidget *svgwidget;

protected:
    virtual void resizeEvent(QResizeEvent *) override;
    virtual void showEvent(QShowEvent *) override;
private slots:

    void openRecentFile(int row, int column);
    //void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    void click_open_help();
    void click_open_metod_one();
    void click_open_metod_two();

    void click_open_metod_three();
    void click_open_metod_four();
    void click_open_metod_five();
    void selectImage();
    void click_open_metod_six();
    void click_open_metod_seven();
    void click_open_metod_eight();
    void click_open_metod_nine();
    void click_open_metod_ten();
    void click_open_metod_eleven();
    void click_open_metod_twelv();
};

#endif // START_APP_H
