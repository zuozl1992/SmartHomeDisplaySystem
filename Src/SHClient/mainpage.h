#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QJsonObject>

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();

private slots:
    void on_btnTest_clicked();
    void newSensingDataSlot(int id,QJsonObject data);

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
