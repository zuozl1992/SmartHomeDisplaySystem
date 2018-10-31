#include <QCoreApplication>
#include "serialportdev.h"
#include "serialportprotocol.h"
#include "networkdev.h"
#include "networkprotocol.h"
#include "config.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SerialPortDev::getObject();
    SerialPortProtocol::getObject();
    bool ok = SerialPortDev::getObject()->openSerial(
                USARTNAME,
                USARTBAUDRATE);

    if(ok)
        qDebug() << "SerialPort open successful!";

    NetWorkDev::getObject();
    NetWorkDev::getObject()->connectToServer(NETWORKIPADDR,NETWORKPORT);
    NetWorkProtocol::getObject();

    return a.exec();
}
