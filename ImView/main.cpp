#include "mainwindow.h"

#include <QApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QIcon>
#include <QuaZip-Qt5-1.4/quazip/JlCompress.h>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("ImView");
    QCoreApplication::setApplicationName("ImView");

    if(QGuiApplication::platformName() == QLatin1String("xcb"))
    {
        QGuiApplication::setWindowIcon(QIcon("/home/elf/ImView2/data/img/icons/IM_24_blue.png"));
    }
    else if(QGuiApplication::platformName() == QLatin1String("wayland"))
    {
        QGuiApplication::setDesktopFileName("org.imvew.IMView.desktop");
    }


    QTranslator qtLanguageTranslator;
    QSettings settings( "BRU", "IM View");
    settings.beginGroup( "language interface" );
    QString lokal = settings.value( "QtLanguage_", "").toString();
    settings.endGroup();

    qtLanguageTranslator.load(QString("QtLanguage_") + lokal);
    qApp->installTranslator(&qtLanguageTranslator);

    MainWindow w;
    QDir dir("/tmp/imview");
    if (dir.exists())
    {
        dir.removeRecursively();
    }
    if (argc == 2)
    {
        QString filename(argv[1]);
        w.LoadProject(filename);
    }

    w.show();

    return a.exec();
}
