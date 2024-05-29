#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);

    ui->stackedWidget->addWidget(ui->comboBox);
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->addItem(tr("Русский язык"));
    ui->comboBox->addItem(tr("English language"));
    ui->comboBox->setCurrentIndex(1);

}

settings::~settings()
{
    delete ui;
}

void settings::on_pushButton_clicked()
{

}

