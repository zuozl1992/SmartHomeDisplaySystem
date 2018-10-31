#include "mainpage.h"
#include "ui_mainpage.h"
#include "networkprotocol.h"
#include <QDebug>

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->setWindowTitle("智能家居客户端");
    this->setWindowIcon(QIcon(":/logo.ico"));
    connect(NetWorkProtocol::getObject(),
            SIGNAL(newSensingData(int,QJsonObject)),
            this,
            SLOT(newSensingDataSlot(int,QJsonObject)));
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_btnTest_clicked()
{
    NetWorkProtocol::getObject()->requestSensingData(1001);
//    NetWorkProtocol::getObject()->setAir(1001,2,Dehumidification,Three,19);
//    NetWorkProtocol::getObject()->setHeart(1001,2,20);
}

void MainPage::newSensingDataSlot(int id, QJsonObject data)
{
    if(id == 1001)
    {
        qDebug() << data;
    }
}
