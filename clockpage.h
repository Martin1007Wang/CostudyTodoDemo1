#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTime>
#include<QLineEdit>
#include<QTimerEvent>
#include<qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Clock; }
QT_END_NAMESPACE

class ClockPage : public QMainWindow
{
    Q_OBJECT

public:
    ClockPage(QWidget *parent = nullptr);
    ~ClockPage();
    void on_TimeEdit_usetTimeChanged(const QTime &time);
    void on_btnStart_clicked();
    void on_btnReset_clicked();
    void on_btnStop_clicked();

private:
    Ui::Clock *ui;
    QTime timeSet;
    QLineEdit lineEditGet;
    int setSecond;
    int timerId;
    bool hasSetTime;
    bool btnStartHasClicked;
    bool isStop;
protected:
    void timerEvent(QTimerEvent *);
};
#endif // MAINWINDOW_H
