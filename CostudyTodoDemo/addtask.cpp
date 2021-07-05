#include "addtask.h"
#include "ui_addtask.h"

AddTask::AddTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTask)
{
    ui->setupUi(this);
}

AddTask::~AddTask()
{
    delete ui;
}

void AddTask::on_return_Button_clicked()
{
    this->hide();
    ui->ack_Button;
}

void AddTask::on_ack_Button_clicked()//确定添加任务
{
    //获取是否提醒的信息
    if(ui->remind->isChecked())
    {
        c=new ChooseStar;
        c->setWindowTitle("任务优先级");
        c->show();//打开选择星级的窗口
    }
    //获取加入的任务信息，并录入数据库
    QString topic=ui->newTaskTitle->text().trimmed();
    QString remark=ui->newTaskRemark->text().trimmed();

}
