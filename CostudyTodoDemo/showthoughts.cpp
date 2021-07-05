#include "showthoughts.h"
#include "ui_showthoughts.h"
#include<QTextEdit>

ShowThoughts::ShowThoughts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowThoughts)
{
    ui->setupUi(this);

    ui->textEdit->setText("十月五号,.......");//这里导入数据库中心得
}

ShowThoughts::~ShowThoughts()
{

    delete ui;
}

void ShowThoughts::on_return_button_clicked()
{
    this->hide();
}
