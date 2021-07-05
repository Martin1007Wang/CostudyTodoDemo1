#include "choosestar.h"
#include "ui_choosestar.h"
#include<QMessageBox>

ChooseStar::ChooseStar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseStar)
{
    ui->setupUi(this);
}

ChooseStar::~ChooseStar()
{
    delete ui;
}

void ChooseStar::on_return_Button_clicked()
{
    this->hide();
}

void ChooseStar::on_ack_Button_clicked()
{
    //获取优先级信息
    if(ui->onestar->isChecked())
    {
        //用一星初始化任务属性
        this->hide();
    }
    else if(ui->twostars->isChecked())
    {
        //用二星初始化任务属性
        this->hide();
    }
     else if(ui->threestars->isChecked())
    {
        //用三星初始化任务属性
        this->hide();
    }
    else
    {
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("请选择任务星级"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }


}
