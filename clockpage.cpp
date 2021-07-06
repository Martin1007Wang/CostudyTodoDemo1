#include "clockpage.h"
#include "ui_clock.h"

ClockPage::ClockPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Clock)
{
    ui->setupUi(this);
    timeSet=ui->timeEdit->time();
    ui->lineEdit->setText(timeSet.toString());
    hasSetTime = false;
    btnStartHasClicked = false;
    isStop = false;
}

ClockPage::~ClockPage()
{
    delete ui;
}

void ClockPage::on_TimeEdit_usetTimeChanged(const QTime &time)
{
    ui->lineEdit->setText(time.toString());
    setSecond = time.hour()*3600+time.minute()*60;
    hasSetTime = true;
    btnStartHasClicked = false;
}

void ClockPage::on_btnStart_clicked()
{
    isStop = false;
    if(btnStartHasClicked)
    {

    }
    else
    {
        if(hasSetTime)
        {
            timerId = startTimer(1000);
            btnStartHasClicked =true;
        }
        else
        {
            QMessageBox::information(this,"提示","请先设置时间");
        }
    }
}

void ClockPage::timerEvent(QTimerEvent *)
{
    if(isStop)
    {

    }
    else
    {
        setSecond -=1;
        timeSet.setHMS(setSecond/3600,(setSecond - (setSecond-setSecond/3600*3600)/60),setSecond-setSecond/60*60);
        ui->lineEdit->setText(timeSet.toString());

        if (setSecond = 0)
        {
            QMessageBox::information(this,"提示","时间到");
            killTimer(timerId);
        }
    }
}

void ClockPage::on_btnStop_clicked()
{
    if(btnStartHasClicked)
    {
        isStop = true;
    }
    else
    {
        QMessageBox::information(this,"提示","未开始计时");
    }
}

void ClockPage::on_btnReset_clicked()
{
    if(btnStartHasClicked)
    {
        killTimer(timerId);
        timeSet.setHMS(0,0,0);
        ui->lineEdit->setText(timeSet.toString());

        QTime time(0,0,0);
        ui->timeEdit->setTime(time);
        hasSetTime= false;
        btnStartHasClicked = false;
    }
    else
    {
        QMessageBox::information(this,"提示","未开始计时");
    }

}
