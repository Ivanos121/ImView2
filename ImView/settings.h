#ifndef SETTINGS_H
#define SETTINGS_H


#include <QDialog>

class MainWindow;

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

    MainWindow *wf;

private slots:
    void on_pushButton_clicked();

private:
    Ui::settings *ui;    
    settings *set;


};

#endif // SETTINGS_H
