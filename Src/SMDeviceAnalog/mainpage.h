#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>

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
    void on_btnOpenSerial_clicked();
    void newAirConditionerControlSlot(int index,int model,int te,int fun);
    void newLedControlSlot(int index,int b);
    void newHeaterControlSlot(int index,int te);
    void newCurtainsControlSlot(int index,int pos);

    void on_btnAirOpen_clicked();

    void on_btnAirAdd_clicked();

    void on_btnAirSub_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_btnAirOpen_2_clicked();

    void on_btnAirOpen_3_clicked();

    void on_btnAirOpen_4_clicked();

    void on_btnAirAdd_2_clicked();

    void on_btnAirAdd_3_clicked();

    void on_btnAirAdd_4_clicked();

    void on_btnAirSub_2_clicked();

    void on_btnAirSub_3_clicked();

    void on_btnAirSub_4_clicked();

    void on_btnnext_clicked();

    void on_btnper_clicked();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
