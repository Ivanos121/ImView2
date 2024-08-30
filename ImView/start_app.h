#ifndef START_APP_H
#define START_APP_H

#include "qabstractitemmodel.h"
#include "qsvgwidget.h"
#include "qtablewidget.h"
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

public slots:
    void click_open_file();
    void click_open_progect();
    void click_open_progect_2(const QModelIndex &idx);
    QString strippedName(const QString &fullFileName);
public:
    Ui::Start_app *ui;
    QSvgWidget *svgwidget;
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void showEvent(QShowEvent *) override;
private slots:
    void openRecentFile(int row, int column);
    //void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
};

#endif // START_APP_H
