#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QList>

typedef struct
{
    QTcpSocket *socket;
    int braNum;
    char lastChar;
    QByteArray readBuffer;
    QJsonObject sensingData;
    int deviceID;
}ClientInfo;

class NetWorkServer : public QObject
{
    Q_OBJECT
private:
    explicit NetWorkServer(QObject *parent = nullptr);

public:
    static NetWorkServer * getObject();
    //监听对应端口，启动网络服务
    bool startNetWork(quint16 port);

    void sendDataToDevice(int deviceID,QJsonObject obj);
    bool getDataFromDevice(int deviceID,QJsonObject *data);

protected slots:
    void newConnectionSlot();
    void disconnectedSlot();
    void readyReadSlot();


protected:
    int getIndexOfClientList(QTcpSocket *s);
    int getIndexOfClientList(int deviceID);

    QTcpServer *server;
    QList<ClientInfo *> clientList;
};

#endif // NETWORKSERVER_H
