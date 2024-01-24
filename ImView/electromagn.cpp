#include "electromagn.h"
#include "ui_electromagn.h"
#include "base.h"
#include "model_el.h"
#include "nabludatel.h"
#include "nabludatel_part.h"
#include "plot.h"
#include "datasource_file.h"
#include "datasourcedigitosc.h"
#include "ui_mainwindow.h"
#include "tepl_struct.h"

#include <iostream>
#include <fstream>
#include <QLinearGradient>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QScrollArea>


DataSource_file dataSource_file;
Model_el Model_el;
QPoint p1,p2;
QCursor curs;
Tepl_struct tepl_struct;

struct MomentInterpPoint
{
    double pos;
    double M;
};

MomentInterpPoint momentInterpArray[9] = {{0.0, 1.14}, {10.0, 1.47}, {20.0, 3.26}, {30.0, 7.0},
                                          {40.0, 13.3}, {50.0, 19.5}, {60.0, 25.2}, {70.0, 28.8},
                                          {80.0, 31.1}};

static double getPosValue(double M)
{
    double pos_interpolated;

    for (int i = 0; i < 8; i++)
    {
        if (momentInterpArray[i].M <= M)
        {
            pos_interpolated = (momentInterpArray[i+1].pos - momentInterpArray[i].pos) /
                    (momentInterpArray[i+1].M - momentInterpArray[i].M) *
                    (M - momentInterpArray[i].M) + momentInterpArray[i].pos;
        }
    }
    return pos_interpolated;
}

electromagn::electromagn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::electromagn),
    dataSource(nullptr)
{
    ui->setupUi(this);
    ui->plot->t_max = 10.0;
    ui->plot->U_max = 500.0;
    ui->plot->margin_bottom = 40;
    ui->plot->margin_left = 100;
    ui->plot->reset();
    time=new QElapsedTimer();
    this->showMaximized();

   // connect(wf->ui->horizontalSlider, &QSlider::valueChanged, this, &electromagn::realtimeSlot);
}


electromagn::~electromagn()
{
    delete ui;
}

void electromagn::realtimeDataSlot()
{
    //double a1=0,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18;
    double b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0,b9=0,b10=0,b11=0,b12=0,b13=0,b14=0,b15=0,b16=0,b17=0,b18=0;

    key = time->elapsed()/1000.0;

    //Внутренний источник данных

    if(wf->item80->text() == "Внутренний источник данных")
    {
        base.Mc_n = wf->item132->text().toDouble();
        base.Um = wf->item130->text().toDouble();
        wf->ui->horizontalSlider->setValue(base.Mc_n);
        wf->ui->horizontalSlider_2->setValue(base.Um) ;

        for (int i = 0; i < 1000; i++)
        {
            Model_el.rasch();
        }

        //Считывание значения времени цикла Тц
        Model_el.Tc=wf->item22->text().toDouble();

        //Считывание значения времени работы tp
        Model_el.tp=wf->item24->text().toDouble();

        //Считывание значения времени работы Mc
        //Model_el.Mc=wf->item90->text().toDouble();

        //Считывание коэффициента изменения амплитуды напряжения фазы А

        if(wf->ui->tableWidget->item(4,4)!=0)
        {
            b1=wf->ui->tableWidget->item(4,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды напряжения фазы В

        if(wf->ui->tableWidget->item(5,4)!=0)
        {
            b2=wf->ui->tableWidget->item(5,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды напряжения фазы С

        if(wf->ui->tableWidget->item(6,4)!=0)
        {
            b3=wf->ui->tableWidget->item(6,4)->text().toDouble();
        }

        //Считывание коэффициента смещения напряжения фазы А

        if(wf->ui->tableWidget->item(4,3)!=0)
        {
            b4=wf->ui->tableWidget->item(4,3)->text().toDouble();
        }

        //Считывание коэффициента смещения напряжения фазы В

        if(wf->ui->tableWidget->item(5,3)!=0)
        {
            b5=wf->ui->tableWidget->item(5,3)->text().toDouble();
        }

        //Считывание коэффициента смещения напряжения фазы С

        if(wf->ui->tableWidget->item(6,3)!=0)
        {
            b6=wf->ui->tableWidget->item(6,3)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды тока фазы А

        if(wf->ui->tableWidget->item(7,4)!=0)
        {
            b7=wf->ui->tableWidget->item(7,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды тока фазы В

        if(wf->ui->tableWidget->item(8,4)!=0)
        {
            b8=wf->ui->tableWidget->item(8,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды тока фазы С

        if(wf->ui->tableWidget->item(9,4)!=0)
        {
            b9=wf->ui->tableWidget->item(9,4)->text().toDouble();
        }

        //Считывание коэффициента смещения тока фазы А

        if(wf->ui->tableWidget->item(7,3)!=0)
        {
            b10=wf->ui->tableWidget->item(7,3)->text().toDouble();
        }

        //Считывание коэффициента смещения тока фазы В

        if(wf->ui->tableWidget->item(8,3)!=0)
        {
            b11=wf->ui->tableWidget->item(8,3)->text().toDouble();
        }

        //Считывание коэффициента смещения тока фазы С

        if(wf->ui->tableWidget->item(9,3)!=0)
        {
            b12=wf->ui->tableWidget->item(9,3)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды скорости вращения

        if(wf->ui->tableWidget->item(10,4)!=0)
        {
            b13=wf->ui->tableWidget->item(10,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды момента на валу

        if(wf->ui->tableWidget->item(11,4)!=0)
        {
            b14=wf->ui->tableWidget->item(11,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды момента Mc

        if(wf->ui->tableWidget->item(12,4)!=0)
        {
            b17=wf->ui->tableWidget->item(12,4)->text().toDouble();
        }

        //Считывание коэффициента смещения скорости вращения

        if(wf->ui->tableWidget->item(10,3)!=0)
        {
            b15=wf->ui->tableWidget->item(10,3)->text().toDouble();
        }

        //Считывание коэффициента смещения момента на валу

        if(wf->ui->tableWidget->item(11,3)!=0)
        {
            b16=wf->ui->tableWidget->item(11,3)->text().toDouble();
        }

        //Считывание коэффициента смещения момента Mc

        if(wf->ui->tableWidget->item(12,3)!=0)
        {
            b18=wf->ui->tableWidget->item(12,3)->text().toDouble();
        }

        key = Model_el.t;

        //вывод на qcustomPlot графика напряжения Ua после преобразования 2 в 3

        if(wf->ui->tableWidget->model()->index(4,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(0, key, b4+b1*(Model_el.u_dev_a));
        }

        //вывод на qcustomPlot графика напряжения Ub после преобразования 2 в 3

        if(wf->ui->tableWidget->model()->index(5,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(1, key, b5+b2*(Model_el.u_dev_b));
        }

        //вывод на qcustomPlot графика напряжения Uc после преобразования 2 в 3

        if(wf->ui->tableWidget->model()->index(6,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(2, key, b6+b3*(Model_el.u_dev_c));
        }

        //вывод на qcustomPlot графика напряжения Ia после преобразования 2 в 3

        if(wf->ui->tableWidget->model()->index(7,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(3, key, b10+b7*(Model_el.i_dev_a));
        }

        //вывод на qcustomPlot графика напряжения Ib после преобразования 2 в 3

        if(wf->ui->tableWidget->model()->index(8,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(4, key, b11+b8*(Model_el.i_dev_b));
        }

        //вывод на qcustomPlot графика напряжения Ic после преобразования 2 в 3

        if(wf->ui->tableWidget->model()->index(9,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(5, key, b12+b9*(Model_el.i_dev_c));
        }

        //вывод на qcustomPlot графика скорости omega

        if(wf->ui->tableWidget->model()->index(10,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(6, key, b15+b13*Model_el.omega);
        }

        //вывод на qcustomPlot момента на валу M

        if(wf->ui->tableWidget->model()->index(7,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(7, key, b16+b14*Model_el.M);
        }

        //вывод на qcustomPlot момента Mс

        if(wf->ui->tableWidget->model()->index(8,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(8, key, b17+b18*Model_el.Mc);
        }

        //Занесение итоговых данных в таблицу
        if (wf->ui->tableWidget_2->item(0, 2) != 0)
        {
            wf->ui->tableWidget_2->item(0, 2)->setText(QString::number(Model_el.i_dev_a,'f',3));
        }

        if (wf->ui->tableWidget_2->item(1, 2) != 0)
        {
            wf->ui->tableWidget_2->item(1, 2)->setText(QString::number(Model_el.u_dev_a,'f',3));
        }

        if (wf->ui->tableWidget_2->item(2, 2) != 0)
        {
            wf->ui->tableWidget_2->item(2, 2)->setText(QString::number(Model_el.p_akt_a,'f',3));
        }

        if (wf->ui->tableWidget_2->item(3, 2) != 0)
        {
            wf->ui->tableWidget_2->item(3, 2)->setText(QString::number(Model_el.p_reakt_a,'f',3));
        }

        if (wf->ui->tableWidget_2->item(4, 2) != 0)
        {
            wf->ui->tableWidget_2->item(4, 2)->setText(QString::number(Model_el.p_poln_a,'f',3));
        }

        if (wf->ui->tableWidget_2->item(5, 2) != 0)
        {
            wf->ui->tableWidget_2->item(5, 2)->setText(QString::number(Model_el.cos_f_a,'f',3));
        }

        if (wf->ui->tableWidget_2->item(6, 2) != 0)
        {
            wf->ui->tableWidget_2->item(6, 2)->setText(QString::number(Model_el.i_dev_b,'f',3));
        }

        if (wf->ui->tableWidget_2->item(7, 2) != 0)
        {
            wf->ui->tableWidget_2->item(7, 2)->setText(QString::number(Model_el.u_dev_b,'f',3));
        }

        if (wf->ui->tableWidget_2->item(8, 2) != 0)
        {
            wf->ui->tableWidget_2->item(8, 2)->setText(QString::number(Model_el.p_akt_b,'f',3));
        }

        if (wf->ui->tableWidget_2->item(9, 2) != 0)
        {
            wf->ui->tableWidget_2->item(9, 2)->setText(QString::number(Model_el.p_reakt_b,'f',3));
        }

        if (wf->ui->tableWidget_2->item(10, 2) != 0)
        {
            wf->ui->tableWidget_2->item(10, 2)->setText(QString::number(Model_el.p_poln_b,'f',3));
        }

        if (wf->ui->tableWidget_2->item(11, 2) != 0)
        {
            wf->ui->tableWidget_2->item(11, 2)->setText(QString::number(Model_el.cos_f_b,'f',3));
        }

        if (wf->ui->tableWidget_2->item(12, 2) != 0)
        {
            wf->ui->tableWidget_2->item(12, 2)->setText(QString::number(Model_el.i_dev_c,'f',3));
        }

        if (wf->ui->tableWidget_2->item(13, 2) != 0)
        {
            wf->ui->tableWidget_2->item(13, 2)->setText(QString::number(Model_el.u_dev_c,'f',3));
        }

        if (wf->ui->tableWidget_2->item(14, 2) != 0)
        {
            wf->ui->tableWidget_2->item(14, 2)->setText(QString::number(Model_el.p_akt_c,'f',3));
        }

        if (wf->ui->tableWidget_2->item(15, 2) != 0)
        {
            wf->ui->tableWidget_2->item(15, 2)->setText(QString::number(Model_el.p_reakt_c,'f',3));
        }

        if (wf->ui->tableWidget_2->item(16, 2) != 0)
        {
            wf->ui->tableWidget_2->item(16, 2)->setText(QString::number(Model_el.p_poln_c,'f',3));
        }

        if (wf->ui->tableWidget_2->item(17, 2) != 0)
        {
            wf->ui->tableWidget_2->item(17, 2)->setText(QString::number(Model_el.cos_f_c,'f',3));
        }

        if (wf->ui->tableWidget_2->item(18, 2) != 0)
        {
            wf->ui->tableWidget_2->item(18, 2)->setText(QString::number(Model_el.p_akt,'f',3));
        }

        if (wf->ui->tableWidget_2->item(19, 2) != 0)
        {
            wf->ui->tableWidget_2->item(19, 2)->setText(QString::number(Model_el.p_reakt,'f',3));
        }

        if (wf->ui->tableWidget_2->item(20, 2) != 0)
        {
            wf->ui->tableWidget_2->item(20, 2)->setText(QString::number(Model_el.p_poln,'f',3));
        }

        if (wf->ui->tableWidget_2->item(21, 2) != 0)
        {
            wf->ui->tableWidget_2->item(21, 2)->setText(QString::number(Model_el.cos_f,'f',3));
        }

        if (wf->ui->tableWidget_2->item(22, 2) != 0)
        {
            wf->ui->tableWidget_2->item(22, 2)->setText(QString::number(Model_el.omega,'f',3));
        }
        if (wf->ui->tableWidget_2->item(23, 2) != 0)
        {
            wf->ui->tableWidget_2->item(23, 2)->setText(QString::number(Model_el.M,'f',3));
        }

        if (wf->ui->tableWidget_2->item(24, 2) != 0)
        {
            wf->ui->tableWidget_2->item(24, 2)->setText(QString::number(Model_el.Mc,'f',3));
        }

        //Запись в таблицу энергетических показателей

        if (wf->ui->tableWidget_4->item(0, 2) != 0)
        {
            wf->ui->tableWidget_4->item(0, 2)->setText(QString::number(tepl_struct.P1,'f',3));
        }

        if (wf->ui->tableWidget_4->item(1, 2) != 0)
        {
            wf->ui->tableWidget_4->item(1, 2)->setText(QString::number(tepl_struct.dPel1,'f',3));
        }

        if (wf->ui->tableWidget_4->item(2, 2) != 0)
        {
            wf->ui->tableWidget_4->item(2, 2)->setText(QString::number(tepl_struct.dPct,'f',3));
        }

        if (wf->ui->tableWidget_4->item(3, 2) != 0)
        {
            wf->ui->tableWidget_4->item(3, 2)->setText(QString::number(tepl_struct.dPel2,'f',3));
        }

        if (wf->ui->tableWidget_4->item(4, 2) != 0)
        {
            wf->ui->tableWidget_4->item(4, 2)->setText(QString::number(tepl_struct.dPdob,'f',3));
        }

        if (wf->ui->tableWidget_4->item(5, 2) != 0)
        {
            wf->ui->tableWidget_4->item(5, 2)->setText(QString::number(tepl_struct.dPmech,'f',3));
        }

        if (wf->ui->tableWidget_4->item(6, 2) != 0)
        {
            wf->ui->tableWidget_4->item(6, 2)->setText(QString::number(tepl_struct.P2,'f',3));
        }

        if (wf->ui->tableWidget_4->item(7, 2) != 0)
        {
            wf->ui->tableWidget_4->item(7, 2)->setText(QString::number(tepl_struct.kpd,'f',3));
        }

        if (wf->ui->tableWidget_4->item(8, 2) != 0)
        {
            wf->ui->tableWidget_4->item(8, 2)->setText(QString::number(Model_el.cos_f,'f',3));
        }

        wf->ui->webEngineView->page()->runJavaScript(QString("$(\"#text139\").text('Р1 = %1 Вт');").arg(tepl_struct.P1, 0, 'f', 3));
        wf->ui->webEngineView->page()->runJavaScript(QString("$(\"#text91-3\").text('ΔPel1 = %1 Вт');").arg(tepl_struct.dPel1, 0, 'f', 3));
        wf->ui->webEngineView->page()->runJavaScript(QString("$(\"#text91\").text('ΔPct = %1 Вт');").arg(tepl_struct.dPct, 0, 'f', 3));
        wf->ui->webEngineView->page()->runJavaScript(QString("$(\"#text33\").text('ΔPel2 = %1 Вт');").arg(tepl_struct.dPel2, 0, 'f', 3));
        wf->ui->webEngineView->page()->runJavaScript(QString("$(\"#text53\").text('ΔPdob = %1 Вт');").arg(tepl_struct.dPdob, 0, 'f', 3));
        wf->ui->webEngineView->page()->runJavaScript(QString("$(\"#text259\").text('ΔPmech = %1 Вт');").arg(tepl_struct.dPmech, 0, 'f', 3));
        wf->ui->webEngineView->page()->runJavaScript(QString("$(\"#text75\").text('P2 = %1 Вт');").arg(tepl_struct.P2, 0, 'f', 3));

        std::ofstream fout;
        fout.open(QString(base.electromagnFilename).toStdString(),std::ios::out | std::ios::app);
        fout << QString("%1").arg(key).toStdString() << ";";
        fout << QString("%1").arg(Model_el.u_dev_a).toStdString() << ";";
        fout << QString("%1").arg(Model_el.u_dev_b).toStdString() << ";";
        fout << QString("%1").arg(Model_el.u_dev_c).toStdString() << ";";
        fout << QString("%1").arg(Model_el.i_dev_a).toStdString() << ";";
        fout << QString("%1").arg(Model_el.i_dev_b).toStdString() << ";";
        fout << QString("%1").arg(Model_el.i_dev_c).toStdString() << ";";
        fout << QString("%1").arg(Model_el.omega).toStdString() << ";";
        fout << QString("%1").arg(Model_el.M).toStdString() << ";";
        fout << QString("%1").arg(Model_el.Mc).toStdString() << ";";
        fout << std::endl;
        fout.close();

    }
    else
    {
        //Считывание значения времени цикла Тц
        double Tc = wf->item22->text().toDouble();

        //Считывание значения времени работы tp
        double tp = wf->item24->text().toDouble();

        //Считывание значения времени работы Mc
        //double Mc_n = wf->item90->text().toDouble();
        base.Mc_n = wf->ui->horizontalSlider->value() / 99.0 * 30.0;

        QString S = wf->item20->text();

        double Mc;
        double tt = key;
        bool motorOn = false;

        if(S == "Режим S1")
        {
            Mc = base.Mc_n;
            motorOn = true;
        }

        if(S == "Режим S2")
        {
            if(tt<=tp)
            {
                Mc=base.Mc_n;
                motorOn = true;
            }
            if(tt>tp)
            {
                Mc=0;
                motorOn = false;
            }
        }

        if(S == "Режим S3")
        {
            while(tt>Tc)
            {
                tt-=Tc;
            }
            if(tt<tp)
            {
                Mc=base.Mc_n;
                motorOn = true;
            }
            if(tt>tp)
            {
                Mc=0;
                motorOn = false;
            }
        }

        double pos = getPosValue(Mc);

        char value = (1.0 - pos / 99.0) * 144.0;
        momentPort->write(&value, 1);
        momentPort->flush();

        QByteArray buf;
        buf.resize(12);
        buf.fill(0);
        buf[0] = 0x00; // Transaction identifier
        buf[1] = 0x01; // Transaction identifier

        buf[2] = 0x00; // Protocol identifier
        buf[3] = 0x00; // Protocol identifier

        buf[4] = 0x00; // Packet length
        buf[5] = 0x06; // Packet length

        buf[6] = 0x01; // Slave id

        buf[7] = 0x06; // Code - write register

        buf[8] = 0x00; // Register Address
        buf[9] = 0x00; // Register Address

        if (motorOn)
        {
            buf[10] = 0x00; // Value
            buf[11] = 0x01; // Value
        }
        else
        {
            buf[10] = 0x00; // Value
            buf[11] = 0x02; // Value
        }

        plcSocket.write(buf, buf.length());
        plcSocket.waitForBytesWritten();

        nabludatel->rasch(dataSource);

        //Считывание коэффициента изменения амплитуды напряжения фазы А

        if(wf->ui->tableWidget->item(4,4)!=0)
        {
            b1=wf->ui->tableWidget->item(4,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды напряжения фазы В

        if(wf->ui->tableWidget->item(5,4)!=0)
        {
            b2=wf->ui->tableWidget->item(5,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды напряжения фазы С

        if(wf->ui->tableWidget->item(6,4)!=0)
        {
            b3=wf->ui->tableWidget->item(6,4)->text().toDouble();
        }

        //Считывание коэффициента смещения напряжения фазы А

        if(wf->ui->tableWidget->item(4,3)!=0)
        {
            b4=wf->ui->tableWidget->item(4,3)->text().toDouble();
        }

        //Считывание коэффициента смещения напряжения фазы В

        if(wf->ui->tableWidget->item(5,3)!=0)
        {
            b5=wf->ui->tableWidget->item(5,3)->text().toDouble();
        }

        //Считывание коэффициента смещения напряжения фазы С

        if(wf->ui->tableWidget->item(6,3)!=0)
        {
            b6=wf->ui->tableWidget->item(6,3)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды тока фазы А

        if(wf->ui->tableWidget->item(7,4)!=0)
        {
            b7=wf->ui->tableWidget->item(7,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды тока фазы В

        if(wf->ui->tableWidget->item(8,4)!=0)
        {
            b8=wf->ui->tableWidget->item(8,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды тока фазы С

        if(wf->ui->tableWidget->item(9,4)!=0)
        {
            b9=wf->ui->tableWidget->item(9,4)->text().toDouble();
        }

        //Считывание коэффициента смещения тока фазы А

        if(wf->ui->tableWidget->item(7,3)!=0)
        {
            b10=wf->ui->tableWidget->item(7,3)->text().toDouble();
        }

        //Считывание коэффициента смещения тока фазы В

        if(wf->ui->tableWidget->item(8,3)!=0)
        {
            b11=wf->ui->tableWidget->item(8,3)->text().toDouble();
        }

        //Считывание коэффициента смещения тока фазы С

        if(wf->ui->tableWidget->item(9,3)!=0)
        {
            b12=wf->ui->tableWidget->item(9,3)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды скорости вращения

        if(wf->ui->tableWidget->item(10,4)!=0)
        {
            b13=wf->ui->tableWidget->item(10,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды момента на валу

        if(wf->ui->tableWidget->item(11,4)!=0)
        {
            b14=wf->ui->tableWidget->item(11,4)->text().toDouble();
        }

        //Считывание коэффициента изменения амплитуды момента Mc

        if(wf->ui->tableWidget->item(12,4)!=0)
        {
            b17=wf->ui->tableWidget->item(12,4)->text().toDouble();
        }

        //Считывание коэффициента смещения скорости вращения

        if(wf->ui->tableWidget->item(10,3)!=0)
        {
            b15=wf->ui->tableWidget->item(10,3)->text().toDouble();
        }

        //Считывание коэффициента смещения момента на валу

        if(wf->ui->tableWidget->item(11,3)!=0)
        {
            b16=wf->ui->tableWidget->item(11,3)->text().toDouble();
        }

        //Считывание коэффициента смещения момента Mc

        if(wf->ui->tableWidget->item(12,3)!=0)
        {
            b18=wf->ui->tableWidget->item(12,3)->text().toDouble();
        }


        if(wf->ui->tableWidget->model()->index(4,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(0, key, b4+b1*nabludatel->get_u_dev_a());
        }

        if(wf->ui->tableWidget->model()->index(5,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(1, key, b5+b2*nabludatel->get_u_dev_b());
        }

        if(wf->ui->tableWidget->model()->index(6,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(2, key, b6+b3*nabludatel->get_u_dev_c());
        }

        if(wf->ui->tableWidget->model()->index(7,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(3, key, b10+b7*nabludatel->get_i_dev_a());
        }

        if(wf->ui->tableWidget->model()->index(8,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(4, key, b11+b8*nabludatel->get_i_dev_b());
        }

        if(wf->ui->tableWidget->model()->index(9,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(5, key, b12+b9*nabludatel->get_i_dev_c());
        }

        if(wf->ui->tableWidget->model()->index(10,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(6, key, nabludatel->get_w_sr());
        }

        if(wf->ui->tableWidget->model()->index(11,2).data(Qt::CheckStateRole)==Qt::Checked)
        {
            ui->plot->addPoint(7, key, nabludatel->get_M_sr());
        }

        //Занесение итоговых данных в таблицу
        if (wf->ui->tableWidget_2->item(0, 1) != 0)
        {
            wf->ui->tableWidget_2->item(0, 1)->setText(QString("%1").arg(nabludatel->get_i_dev_a()));
        }

        if (wf->ui->tableWidget_2->item(1, 1) != 0)
        {
            wf->ui->tableWidget_2->item(1, 1)->setText(QString("%1").arg(nabludatel->get_u_dev_a()));
        }

        if (wf->ui->tableWidget_2->item(2, 1) != 0)
        {
            wf->ui->tableWidget_2->item(2, 1)->setText(QString("%1").arg(nabludatel->get_p_akt_a()));
        }

        if (wf->ui->tableWidget_2->item(3, 1) != 0)
        {
            wf->ui->tableWidget_2->item(3, 1)->setText(QString("%1").arg(nabludatel->get_p_reakt_a()));
        }

        if (wf->ui->tableWidget_2->item(4, 1) != 0)
        {
            wf->ui->tableWidget_2->item(4, 1)->setText(QString("%1").arg(nabludatel->get_p_poln_a()));
        }

        if (wf->ui->tableWidget_2->item(5, 1) != 0)
        {
            wf->ui->tableWidget_2->item(5, 1)->setText(QString("%1").arg(nabludatel->get_cos_f_a()));
        }

        if (wf->ui->tableWidget_2->item(6, 1) != 0)
        {
            wf->ui->tableWidget_2->item(6, 1)->setText(QString("%1").arg(nabludatel->get_i_dev_b()));
        }

        if (wf->ui->tableWidget_2->item(7, 1) != 0)
        {
            wf->ui->tableWidget_2->item(7, 1)->setText(QString("%1").arg(nabludatel->get_u_dev_b()));
        }

        if (wf->ui->tableWidget_2->item(8, 1) != 0)
        {
            wf->ui->tableWidget_2->item(8, 1)->setText(QString("%1").arg(nabludatel->get_p_akt_b()));
        }

        if (wf->ui->tableWidget_2->item(9, 1) != 0)
        {
            wf->ui->tableWidget_2->item(9, 1)->setText(QString("%1").arg(nabludatel->get_p_reakt_b()));
        }

        if (wf->ui->tableWidget_2->item(10, 1) != 0)
        {
            wf->ui->tableWidget_2->item(10, 1)->setText(QString("%1").arg(nabludatel->get_p_poln_b()));
        }

        if (wf->ui->tableWidget_2->item(11, 1) != 0)
        {
            wf->ui->tableWidget_2->item(11, 1)->setText(QString("%1").arg(nabludatel->get_cos_f_b()));
        }

        if (wf->ui->tableWidget_2->item(12, 1) != 0)
        {
            wf->ui->tableWidget_2->item(12, 1)->setText(QString("%1").arg(nabludatel->get_i_dev_c()));
        }

        if (wf->ui->tableWidget_2->item(13, 1) != 0)
        {
            wf->ui->tableWidget_2->item(13, 1)->setText(QString("%1").arg(nabludatel->get_u_dev_c()));
        }

        if (wf->ui->tableWidget_2->item(14, 1) != 0)
        {
            wf->ui->tableWidget_2->item(14, 1)->setText(QString("%1").arg(nabludatel->get_p_akt_c()));
        }

        if (wf->ui->tableWidget_2->item(15, 1) != 0)
        {
            wf->ui->tableWidget_2->item(15, 1)->setText(QString("%1").arg(nabludatel->get_p_reakt_c()));
        }

        if (wf->ui->tableWidget_2->item(16, 1) != 0)
        {
            wf->ui->tableWidget_2->item(16, 1)->setText(QString("%1").arg(nabludatel->get_p_poln_c()));
        }

        if (wf->ui->tableWidget_2->item(17, 1) != 0)
        {
            wf->ui->tableWidget_2->item(17, 1)->setText(QString("%1").arg(nabludatel->get_cos_f_c()));
        }

        if (wf->ui->tableWidget_2->item(18, 1) != 0)
        {
            wf->ui->tableWidget_2->item(18, 1)->setText(QString("%1").arg(nabludatel->get_p_akt()));
        }

        if (wf->ui->tableWidget_2->item(19, 1) != 0)
        {
            wf->ui->tableWidget_2->item(19, 1)->setText(QString("%1").arg(nabludatel->get_p_reakt()));
        }
        if (wf->ui->tableWidget_2->item(20, 1) != 0)
        {
            wf->ui->tableWidget_2->item(20, 1)->setText(QString("%1").arg(nabludatel->get_p_poln()));
        }
        if (wf->ui->tableWidget_2->item(21, 1) != 0)
        {
            wf->ui->tableWidget_2->item(21, 1)->setText(QString("%1").arg(nabludatel->get_cos_f()));
        }
        if (wf->ui->tableWidget_2->item(22, 1) != 0)
        {
            wf->ui->tableWidget_2->item(22, 1)->setText(QString("%1").arg(nabludatel->get_w_sr()));
        }
        if (wf->ui->tableWidget_2->item(23, 1) != 0)
        {
            wf->ui->tableWidget_2->item(23, 1)->setText(QString("%1").arg(nabludatel->get_M_sr()));
        }

        if (wf->ui->tableWidget_4->item(0, 2) != 0)
        {
            wf->ui->tableWidget_4->item(0, 2)->setText(QString::number(nabludatel->get_P1(),'f',3));
        }

        if (wf->ui->tableWidget_4->item(1, 2) != 0)
        {
            wf->ui->tableWidget_4->item(1, 2)->setText(QString::number(nabludatel->get_dPel1(),'f',3));
        }

        if (wf->ui->tableWidget_4->item(2, 2) != 0)
        {
            wf->ui->tableWidget_4->item(2, 2)->setText(QString::number(nabludatel->get_dPct(),'f',3));
        }

        if (wf->ui->tableWidget_4->item(3, 2) != 0)
        {
            wf->ui->tableWidget_4->item(3, 2)->setText(QString::number(nabludatel->get_dPel2(),'f',3));
        }

        if (wf->ui->tableWidget_4->item(4, 2) != 0)
        {
            wf->ui->tableWidget_4->item(4, 2)->setText(QString::number(nabludatel->get_dPdob(),'f',3));
        }

        if (wf->ui->tableWidget_4->item(5, 2) != 0)
        {
            wf->ui->tableWidget_4->item(5, 2)->setText(QString::number(nabludatel->get_dPmech(),'f',3));
        }

        if (wf->ui->tableWidget_4->item(6, 2) != 0)
        {
            wf->ui->tableWidget_4->item(6, 2)->setText(QString::number(nabludatel->get_P2(),'f',3));
        }

        if (wf->ui->tableWidget_4->item(7, 2) != 0)
        {
            wf->ui->tableWidget_4->item(7, 2)->setText(QString::number(nabludatel->get_kpd(),'f',3));
        }

        if (wf->ui->tableWidget_4->item(8, 2) != 0)
        {
            wf->ui->tableWidget_4->item(8, 2)->setText(QString::number(nabludatel->get_cos_f(),'f',3));
        }
    }
}

int electromagn::connectMomentPort()
{
    momentPort = new QSerialPort();
    momentPort->setPortName(base.digitMomentParams.portName);

    if (!momentPort->open(QIODevice::ReadWrite))
    {
        return 1;
    }

    momentPort->setBaudRate(base.digitMomentParams.speed);

    switch (base.digitMomentParams.data)
    {
    case QSerialPort::Data8:
        momentPort->setDataBits(QSerialPort::Data8);
        break;
    }

    switch (base.digitMomentParams.parity)
    {
    case QSerialPort::NoParity:
        momentPort->setParity(QSerialPort::NoParity);
        break;
    }

    switch (base.digitMomentParams.stopBits)
    {
    case QSerialPort::OneStop:
        momentPort->setStopBits(QSerialPort::OneStop);
        break;
    }

    switch (base.digitMomentParams.flowControl)
    {
    case QSerialPort::NoFlowControl:
        momentPort->setFlowControl(QSerialPort::NoFlowControl);
        break;
    }

    return 0;
}

void electromagn::connectTcpPort()
{
    plcSocket.connectToHost(base.plcParams.ipAddr, base.plcParams.port);
}

void electromagn::raschet_el()
{
    QSettings settings;

    base.digitMomentParams.portName = settings.value("MomentPort/portName", "ttyMP1").toString();
    base.digitMomentParams.speed = settings.value("MomentPort/portName", 115200).toInt();
    base.digitMomentParams.data = settings.value("MomentPort/data", 8).toInt();
    base.digitMomentParams.parity = settings.value("MomentPort/parity", 1).toInt();
    base.digitMomentParams.stopBits = settings.value("MomentPort/stopBits", 1).toInt();
    base.digitMomentParams.flowControl = settings.value("MomentPort/flowControl", 1).toInt();

    base.plcParams.ipAddr = settings.value("plcPort/ipAddr", "10.0.6.10").toString();
    base.plcParams.port = settings.value("plcPort/port", 502).toInt();

    if(wf->item80->text() == "БВАСv1 + наблюдатель скорости (без датчика скорости)")
    {
        //QMessageBox::critical(this, "Ошибка!", "Выбран первый пункт");
        //БВАС без датчика скорости + наблюдатель скорости
        connectTcpPort();
        if (connectMomentPort() == 1)
        {
            QMessageBox::critical(this, "Ошибка!", "Порт регулятора");
            stop();
            return;
        }

        QSettings settings;

        DataSourceBVAS* dataSourceBVAS = new DataSourceBVAS();

        dataSourceBVAS->setIaZeroLevel(settings.value("calibration/IaZero", 0.0).toDouble());
        dataSourceBVAS->setIbZeroLevel(settings.value("calibration/IbZero", 0.0).toDouble());
        dataSourceBVAS->setIcZeroLevel(settings.value("calibration/IcZero", 0.0).toDouble());

        dataSourceBVAS->setUaZeroLevel(settings.value("calibration/UaZero", 0.0).toDouble());
        dataSourceBVAS->setUbZeroLevel(settings.value("calibration/UbZero", 0.0).toDouble());
        dataSourceBVAS->setUcZeroLevel(settings.value("calibration/UcZero", 0.0).toDouble());

        dataSourceBVAS->setIaCalibrationCoeff(settings.value("calibration/IaCoeff", 1.0).toDouble());
        dataSourceBVAS->setIbCalibrationCoeff(settings.value("calibration/IbCoeff", 1.0).toDouble());
        dataSourceBVAS->setIcCalibrationCoeff(settings.value("calibration/IcCoeff", 1.0).toDouble());

        dataSourceBVAS->setUaCalibrationCoeff(settings.value("calibration/UaCoeff", 1.0).toDouble());
        dataSourceBVAS->setUbCalibrationCoeff(settings.value("calibration/UbCoeff", 1.0).toDouble());
        dataSourceBVAS->setUcCalibrationCoeff(settings.value("calibration/UcCoeff", 1.0).toDouble());

        dataSource = dataSourceBVAS;
        nabludatel = &nabludatel_full;

        dataSource->init();
        nabludatel->init(base.R1, base.R2, base.L1, base.L2, base.Lm);
        connect(dataSource, &DataSource::ready, this, &electromagn::realtimeDataSlot);
        connect(dataSourceBVAS, &DataSourceBVAS::failure, this, &electromagn::bvasFailureSlot);
    }

    if(wf->item80->text() == "БВАСv1 + наблюдатель скорости (с датчиком скорости)")
    {
        connectTcpPort();
        if (connectMomentPort() == 1)
        {
            QMessageBox::critical(this, "Ошибка!", "Порт регулятора");
            stop();
            return;
        }
        //QMessageBox::critical(this, "Ошибка!", "Выбран второй пункт");
        //БВАС с датчиком скорости + наблюдатель частично (момента)
        //БВАС без датчика скорости + наблюдатель скорости
        QSettings settings;

        DataSourceBVASw* dataSourceBVAS = new DataSourceBVASw();

        dataSourceBVAS->setIaZeroLevel(settings.value("calibration/IaZero", 0.0).toDouble());
        dataSourceBVAS->setIbZeroLevel(settings.value("calibration/IbZero", 0.0).toDouble());
        dataSourceBVAS->setIcZeroLevel(settings.value("calibration/IcZero", 0.0).toDouble());

        dataSourceBVAS->setUaZeroLevel(settings.value("calibration/UaZero", 0.0).toDouble());
        dataSourceBVAS->setUbZeroLevel(settings.value("calibration/UbZero", 0.0).toDouble());
        dataSourceBVAS->setUcZeroLevel(settings.value("calibration/UcZero", 0.0).toDouble());

        dataSourceBVAS->setIaCalibrationCoeff(settings.value("calibration/IaCoeff", 1.0).toDouble());
        dataSourceBVAS->setIbCalibrationCoeff(settings.value("calibration/IbCoeff", 1.0).toDouble());
        dataSourceBVAS->setIcCalibrationCoeff(settings.value("calibration/IcCoeff", 1.0).toDouble());

        dataSourceBVAS->setUaCalibrationCoeff(settings.value("calibration/UaCoeff", 1.0).toDouble());
        dataSourceBVAS->setUbCalibrationCoeff(settings.value("calibration/UbCoeff", 1.0).toDouble());
        dataSourceBVAS->setUcCalibrationCoeff(settings.value("calibration/UcCoeff", 1.0).toDouble());

        dataSource = dataSourceBVAS;
        nabludatel = &nabludatel_part;

        dataSource->init();
        nabludatel->init(base.R1, base.R2, base.L1, base.L2, base.Lm);
        connect(dataSource, &DataSource::ready, this, &electromagn::realtimeDataSlot);
        connect(dataSourceBVAS, &DataSourceBVASw::failure, this, &electromagn::bvasFailureSlot);
    }

    if(wf->item80->text() == "БВАСv2 + наблюдатель скорости (без датчика скорости)")
    {
        connectTcpPort();
        if (connectMomentPort() == 1)
        {
            QMessageBox::critical(this, "Ошибка!", "Порт регулятора");
            stop();
            return;
        }
        //QMessageBox::critical(this, "Ошибка!", "Выбран первый пункт");
        //БВАС без датчика скорости + наблюдатель скорости
        QSettings settings;

        DataSourceDigitOsc* dataSourceDigitOsc = new DataSourceDigitOsc();

        base.digitOscParams.portName = settings.value("BVASv2port/portName", "ttyACM0").toString();
        base.digitOscParams.speed = settings.value("BVASv2port/portName", 115200).toInt();
        base.digitOscParams.data = settings.value("BVASv2port/data", 8).toInt();
        base.digitOscParams.parity = settings.value("BVASv2port/parity", 1).toInt();
        base.digitOscParams.stopBits = settings.value("BVASv2port/stopBits", 1).toInt();
        base.digitOscParams.flowControl = settings.value("BVASv2port/flowControl", 1).toInt();

        dataSourceDigitOsc->setIaZeroLevel(settings.value("calibration/IaZero", 0.0).toDouble());
        dataSourceDigitOsc->setIbZeroLevel(settings.value("calibration/IbZero", 0.0).toDouble());
        dataSourceDigitOsc->setIcZeroLevel(settings.value("calibration/IcZero", 0.0).toDouble());

        dataSourceDigitOsc->setUaZeroLevel(settings.value("calibration/UaZero", 0.0).toDouble());
        dataSourceDigitOsc->setUbZeroLevel(settings.value("calibration/UbZero", 0.0).toDouble());
        dataSourceDigitOsc->setUcZeroLevel(settings.value("calibration/UcZero", 0.0).toDouble());

        dataSourceDigitOsc->setIaCalibrationCoeff(settings.value("calibration/IaCoeff", 1.0).toDouble());
        dataSourceDigitOsc->setIbCalibrationCoeff(settings.value("calibration/IbCoeff", 1.0).toDouble());
        dataSourceDigitOsc->setIcCalibrationCoeff(settings.value("calibration/IcCoeff", 1.0).toDouble());

        dataSourceDigitOsc->setUaCalibrationCoeff(settings.value("calibration/UaCoeff", 1.0).toDouble());
        dataSourceDigitOsc->setUbCalibrationCoeff(settings.value("calibration/UbCoeff", 1.0).toDouble());
        dataSourceDigitOsc->setUcCalibrationCoeff(settings.value("calibration/UcCoeff", 1.0).toDouble());

        dataSource = dataSourceDigitOsc;
        nabludatel = &nabludatel_full;

        dataSource->init();
        nabludatel->init(base.R1, base.R2, base.L1, base.L2, base.Lm);
        connect(dataSource, &DataSource::ready, this, &electromagn::realtimeDataSlot);
        connect(dataSourceDigitOsc, &DataSourceDigitOsc::failure, this, &electromagn::bvasFailureSlot);

        wf->statusbar_label_3->setPixmap(QPixmap(":/icons/data/img/icons/osc_blue_24.svg"));
    }

    if(wf->item80->text() == "БВАСv2 + наблюдатель скорости (с датчиком скорости)")
    {
        connectTcpPort();
        if (connectMomentPort() == 1)
        {
            QMessageBox::critical(this, "Ошибка!", "Порт регулятора");
            stop();
            return;
        }
        //QMessageBox::critical(this, "Ошибка!", "Выбран второй пункт");
        //БВАС с датчиком скорости + наблюдатель частично (момента)
        //БВАС без датчика скорости + наблюдатель скорости
        QSettings settings;

        DataSourceDigitOsc* dataSourceDigitOsc = new DataSourceDigitOsc();

        base.digitOscParams.portName = settings.value("BVASv2port/portName", "ttyACM0").toString();
        base.digitOscParams.speed = settings.value("BVASv2port/portName", 115200).toInt();
        base.digitOscParams.data = settings.value("BVASv2port/data", 8).toInt();
        base.digitOscParams.parity = settings.value("BVASv2port/parity", 1).toInt();
        base.digitOscParams.stopBits = settings.value("BVASv2port/stopBits", 1).toInt();
        base.digitOscParams.flowControl = settings.value("BVASv2port/flowControl", 1).toInt();

        dataSourceDigitOsc->setIaZeroLevel(settings.value("calibration/IaZero", 0.0).toDouble());
        dataSourceDigitOsc->setIbZeroLevel(settings.value("calibration/IbZero", 0.0).toDouble());
        dataSourceDigitOsc->setIcZeroLevel(settings.value("calibration/IcZero", 0.0).toDouble());

        dataSourceDigitOsc->setUaZeroLevel(settings.value("calibration/UaZero", 0.0).toDouble());
        dataSourceDigitOsc->setUbZeroLevel(settings.value("calibration/UbZero", 0.0).toDouble());
        dataSourceDigitOsc->setUcZeroLevel(settings.value("calibration/UcZero", 0.0).toDouble());

        dataSourceDigitOsc->setIaCalibrationCoeff(settings.value("calibration/IaCoeff", 1.0).toDouble());
        dataSourceDigitOsc->setIbCalibrationCoeff(settings.value("calibration/IbCoeff", 1.0).toDouble());
        dataSourceDigitOsc->setIcCalibrationCoeff(settings.value("calibration/IcCoeff", 1.0).toDouble());

        dataSourceDigitOsc->setUaCalibrationCoeff(settings.value("calibration/UaCoeff", 1.0).toDouble());
        dataSourceDigitOsc->setUbCalibrationCoeff(settings.value("calibration/UbCoeff", 1.0).toDouble());
        dataSourceDigitOsc->setUcCalibrationCoeff(settings.value("calibration/UcCoeff", 1.0).toDouble());

        dataSource = dataSourceDigitOsc;
        nabludatel = &nabludatel_part;

        dataSource->init();
        nabludatel->init(base.R1, base.R2, base.L1, base.L2, base.Lm);
        connect(dataSource, &DataSource::ready, this, &electromagn::realtimeDataSlot);
        connect(dataSourceDigitOsc, &DataSourceDigitOsc::failure, this, &electromagn::bvasFailureSlot);
    }

    //Внутренний источник данных
    if (wf->item80->text() == "Внутренний источник данных")
    {

        Model_el.init_el(base.R1, base.R2, base.L1, base.L2, base.Lm, wf->item20->text(),
                         Model_el.Tc=wf->item22->text().toDouble(),
                         Model_el.tp=wf->item24->text().toDouble());

      /*  Model_el.init_el(base.R1, base.R2, base.L1, base.L2, base.Lm, wf->item20->text(),
                         Model_el.Tc=wf->item22->text().toDouble(),
                         Model_el.tp=wf->item24->text().toDouble(),
                         Model_el.Mc=wf->item90->text().toDouble());
*/
        connect(&Model_el, &Model_el::ready, this, &electromagn::realtimeDataSlot);
    }

    if (wf->item80->text() == "Чтение данных из файла для наблюдателя скорости")
    {
        QString dataSourceFileName = wf->item82->text();
        base.dataSourceFilename = dataSourceFileName;
        dataSource = new DataSource_file();
        nabludatel = &nabludatel_full;

        dataSource->init();
        nabludatel->init(base.R1, base.R2, base.L1, base.L2, base.Lm);
        connect(dataSource, &DataSource::ready, this, &electromagn::realtimeDataSlot);
    }

    /*ui->plot->clear();
    for (int i = 0; i < dataLineColors.size(); i++)
    {
        ui->plot->addDataLine(dataLineColors[i], 0);
    }*/
    time->start();
}

void electromagn::stop()
{
    if (wf->item80->text() == "Внутренний источник данных")
    {
        Model_el.stop();
        disconnect(&Model_el, &Model_el::ready, this, &electromagn::realtimeDataSlot);
    }
    else
    {
        wf->statusbar_label_3->setPixmap(QPixmap(":/icons/data/img/icons/osc_red_24.svg"));

        if (dataSource != nullptr )
        {
            QByteArray buf;
            buf.resize(12);
            buf.fill(0);
            buf[0] = 0x00; // Transaction identifier
            buf[1] = 0x01; // Transaction identifier

            buf[2] = 0x00; // Protocol identifier
            buf[3] = 0x00; // Protocol identifier

            buf[4] = 0x00; // Packet length
            buf[5] = 0x06; // Packet length

            buf[6] = 0x01; // Slave id

            buf[7] = 0x06; // Code - write register

            buf[8] = 0x00; // Register Address
            buf[9] = 0x00; // Register Address

            buf[10] = 0x00; // Value
            buf[11] = 0x02; // Value

            plcSocket.write(buf, buf.length());
            plcSocket.waitForBytesWritten();
            plcSocket.disconnectFromHost();

            momentPort->close();
            delete momentPort;
            dataSource->stop();
            disconnect(dataSource, &DataSource::ready, this, &electromagn::realtimeDataSlot);
            delete dataSource;
            dataSource = nullptr;
        }
    }
}

void electromagn::on_pushButton_clicked()
{
    base.i_a=wf->ui->tableWidget_2->item(0,1)->text().toDouble();
    base.u_a=wf->ui->tableWidget_2->item(1,1)->text().toDouble();
    base.p_akt_a=wf->ui->tableWidget_2->item(2,1)->text().toDouble();
    base.p_react_a=wf->ui->tableWidget_2->item(3,1)->text().toDouble();
    base.p_poln_a=wf->ui->tableWidget_2->item(4,1)->text().toDouble();
    base.cosf_a=wf->ui->tableWidget_2->item(5,1)->text().toDouble();

    base.i_b=wf->ui->tableWidget_2->item(6,1)->text().toDouble();
    base.u_b=wf->ui->tableWidget_2->item(7,1)->text().toDouble();
    base.p_akt_b=wf->ui->tableWidget_2->item(8,1)->text().toDouble();
    base.p_react_b=wf->ui->tableWidget_2->item(9,1)->text().toDouble();
    base.p_poln_b=wf->ui->tableWidget_2->item(10,1)->text().toDouble();
    base.cosf_b=wf->ui->tableWidget_2->item(11,1)->text().toDouble();

    base.i_c=wf->ui->tableWidget_2->item(12,1)->text().toDouble();
    base.u_c=wf->ui->tableWidget_2->item(13,1)->text().toDouble();
    base.p_akt_c=wf->ui->tableWidget_2->item(14,1)->text().toDouble();
    base.p_react_c=wf->ui->tableWidget_2->item(15,1)->text().toDouble();
    base.p_poln_c=wf->ui->tableWidget_2->item(16,1)->text().toDouble();
    base.cosf_c=wf->ui->tableWidget_2->item(17,1)->text().toDouble();

    base.p_akt=wf->ui->tableWidget_2->item(18,1)->text().toDouble();
    base.p_react=wf->ui->tableWidget_2->item(19,1)->text().toDouble();
    base.p_poln=wf->ui->tableWidget_2->item(20,1)->text().toDouble();
    base.cosf=wf->ui->tableWidget_2->item(21,1)->text().toDouble();
}

void electromagn::addDataLines()
{

}


void electromagn::on_pushButton_2_clicked()
{
    QSettings settings;
    base.dataSourceFilename = QFileDialog::getOpenFileName(this,
                                                           QString::fromUtf8("Открыть файл"),

                                                           settings.value("dataSource/LastPath", "").toString(),
                                                           "txt files (*.txt);;All files (*.*)");
}

void electromagn::bvasFailureSlot()
{
    wf->ui->action_20->setIcon(QIcon(":/system_icons/data/img/system_icons/media-playback-start.svg"));
    wf->ui->action_21->setEnabled(false);
    QMessageBox::critical(this, "Ошибка!", "Ошибка подключения BVAS!");
}

void electromagn::realtimeSlot(int m)
{
    wf->ui->horizontalSlider->setValue(m);
}

