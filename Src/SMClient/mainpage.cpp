#include "mainpage.h"
#include "ui_mainpage.h"
#include "networkprotocol.h"

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->setWindowTitle("智能家居客户端");
    this->setWindowIcon(QIcon(":/logo.ico"));
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_btnTest_clicked()
{
//    NetWorkProtocol::getObject()->requestSensingData(1001);
//    NetWorkProtocol::getObject()->setAir(1001,2,Dehumidification,Three,19);
//    NetWorkProtocol::getObject()->setHeart(1001,2,20);
}
