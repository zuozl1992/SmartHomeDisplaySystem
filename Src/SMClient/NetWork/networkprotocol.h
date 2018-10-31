#ifndef NETWORKPROTOCOL_H
#define NETWORKPROTOCOL_H

#include <QObject>
#include <QJsonObject>
typedef enum {
    Heating,
    Refrigeration,
    Dehumidification,
    AirSupply
}Modules;

typedef enum {
    Auto,
    One,
    Two,
    Three,
    Four,
    Five
}Fun;

class NetWorkProtocol : public QObject
{
    Q_OBJECT
private:
    explicit NetWorkProtocol(QObject *parent = nullptr);

public:
    static NetWorkProtocol *getObject();
    //请求设备传感数据
    void requestSensingData(int id);

    void setAir(int id,int index,Modules modules,Fun fun,int te);

    void setHeart(int id,int index,int te);

    void setLed(int id,int index,int b);

    void setCurtains(int id,int index,int pos);

signals:
    void newSensingData(int id,QJsonObject data);

protected slots:
    void readDataSlot(const QByteArray &data);

protected:
    void handleData(const QJsonObject &obj);
    void sendData(const QJsonObject &obj);

    int braNum = 0;
    char lastChar = ' ';
    QByteArray readBuffer;
};

#endif // NETWORKPROTOCOL_H
