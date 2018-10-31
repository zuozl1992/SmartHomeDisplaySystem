#include "mainpage.h"
#include <QApplication>
#include "networkdev.h"
#include "config.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    NetWorkDev::getObject()->connectToServer(NETWORKIPADDR,NETWORKPORT);

    MainPage w;
    w.show();

    return a.exec();
}
