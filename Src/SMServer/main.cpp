#include <QCoreApplication>
#include <QDebug>
#include "networkserver.h"
#include "networkuserserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bool ok = NetWorkServer::getObject()->startNetWork(10086);
    bool ok2 = NetWorkUserServer::getObject()->startNetWork(10010);

    if(ok)
        qDebug() << "Device server start..";
    else
        qDebug() << "Device server start error!";

    if(ok2)
        qDebug() << "User server start..";
    else
        qDebug() << "User server start error!";

    return a.exec();
}
