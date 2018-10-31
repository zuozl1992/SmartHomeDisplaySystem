#include "networkprotocol.h"
#include "networkdev.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "config.h"
#include <QDebug>

NetWorkProtocol::NetWorkProtocol(QObject *parent) : QObject(parent)
{
    readBuffer.clear();

    connect(NetWorkDev::getObject(),
            SIGNAL(readData(QByteArray)),
            this,
            SLOT(readDataSlot(QByteArray)));
}

NetWorkProtocol *NetWorkProtocol::getObject()
{
    static NetWorkProtocol nwp;
    return &nwp;
}

void NetWorkProtocol::requestSensingData(int id)
{
    QJsonObject obj;
    obj.insert("type","requestData");
    obj.insert("id",id);
    sendData(obj);
}

void NetWorkProtocol::setAir(int id, int index, Modules modules, Fun fun, int te)
{
    QJsonObject obj;
    obj.insert("type","openAir");
    obj.insert("id",id);
    obj.insert("index",index);
    obj.insert("te",te);
    obj.insert("modle",modules);
    obj.insert("fun",fun);
    sendData(obj);
}

void NetWorkProtocol::setHeart(int id, int index, int te)
{
    QJsonObject obj;
    obj.insert("type","openHeart");
    obj.insert("id",id);
    obj.insert("index",index);
    obj.insert("te",te);
    sendData(obj);
}

void NetWorkProtocol::setLed(int id, int index, int b)
{
    QJsonObject obj;
    obj.insert("type","openLed");
    obj.insert("id",id);
    obj.insert("index",index);
    obj.insert("b",b);
    sendData(obj);
}

void NetWorkProtocol::setCurtains(int id, int index, int pos)
{
    QJsonObject obj;
    obj.insert("type","openCurtains");
    obj.insert("id",id);
    obj.insert("index",index);
    obj.insert("pos",pos);
    sendData(obj);
}

void NetWorkProtocol::readDataSlot(const QByteArray &data)
{
    for(qint64 i = 0; i < data.length(); i++)
    {
        if(readBuffer.length() > 0 && data.at(i) == '{'
                && lastChar != ':' && lastChar != '['
                && lastChar != ',')
        {
            //接收到开头，之前的数据不完整丢弃
            readBuffer.clear();
            readBuffer.append(data.at(i));
            lastChar = data.at(i);
            braNum = 1;
            continue;
        }
        if(data.at(i) == '{')
        {
            braNum++;
            readBuffer.append(data.at(i));
            lastChar = '{';
            continue;
        }
        else if(data.at(i) == '}')
        {
            braNum--;
            readBuffer.append(data.at(i));
            lastChar = '}';
            if(braNum == 0)
            {
                //一条完整数据
                QJsonObject obj = QJsonDocument::fromJson(readBuffer)
                        .object();
                //数据处理
                handleData(obj);
                //数据清空
                readBuffer.clear();
                braNum = 0;
            }
            continue;
        }
        else
        {
            readBuffer.append(data.at(i));
            if(data.at(i) != ' ' && data.at(i) != '\n'
               && data.at(i) != '\t' && data.at(i) != 0x0a)
                lastChar = data.at(i);
            continue;
        }
    }
}

void NetWorkProtocol::handleData(const QJsonObject &obj)
{
    QString type = obj.value("type").toString();
    if(type == "sensingData")   //传感数据
    {
        int id = obj.value("id").toInt();
        emit newSensingData(id,obj);
    }

}

void NetWorkProtocol::sendData(const QJsonObject &obj)
{
    NetWorkDev::getObject()->sendData(QJsonDocument(obj).toJson());
}
