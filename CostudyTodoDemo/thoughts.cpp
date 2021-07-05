#include "thoughts.h"
#include "ui_thoughts.h"
#include"todayinterface.h"
#include"showthoughts.h"

Thoughts::Thoughts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Thoughts)
{
    ui->setupUi(this);


}

Thoughts::~Thoughts()
{
    delete ui;
}

void Thoughts::on_return_Button_clicked()
{
    this->hide();


}

void Thoughts::on_history_Button_clicked()
{
    s=new ShowThoughts;
    s->setWindowTitle("历史心得");
    s->show();
}

void Thoughts::on_ackAddReviewTasks_Button_clicked()//确认添加今日所学
{

    QString text1=ui->lineEdit->text().trimmed();//获取用户输入的任务，遍历将输入的任务都加入数据库



}








