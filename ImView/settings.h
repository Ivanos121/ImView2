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


private:
    Ui::settings *ui;
    MainWindow *wf;


};

#endif // SETTINGS_H
