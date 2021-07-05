#include "register.h"
#include "ui_register.h"
#include "global.h"
#include "api_sql.h"
#include <QMessageBox>

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    //定义窗口
    setWindowTitle("Costudy Todo");
    setFixedSize(430,300);
    ui->QLE_uid->setMaxLength(10);
    ui->QLE_uid->setPlaceholderText("请输入用户名");
    ui->QLE_pwd->setMaxLength(20);
    ui->QLE_pwd->setPlaceholderText("请输入英文字母和数字组成的密码");
    ui->QLE_pwd->setEchoMode(QLineEdit::Password);
    ui->QLE_rpwd->setMaxLength(20);
    ui->QLE_rpwd->setPlaceholderText("请重复输入密码");
    ui->QLE_rpwd->setEchoMode(QLineEdit::Password);
    ui->QLE_email->setPlaceholderText("请输入电子邮箱");

    connect(ui->AT_tologin,&QAction::triggered,this,[=](){
        emit this->toLogin();
    });

    connect(ui->QPB_nextStep,&QPushButton::clicked,this,[=](){
        //接受前端数据
        QString uid = ui->QLE_uid->text();
        QString pwd = ui->QLE_pwd->text();
        QString rpwd = ui->QLE_rpwd->text();
        QString email = ui->QLE_email->text();

        //检验数据输入
        if(uid==""){
            QMessageBox::warning(this,"提示","用户名不能为空！");
        }
        else if(!Global::isUid(uid)){
            QMessageBox::warning(this,"提示","用户名输入格式有误！");
        }
        else if(pwd==""){
            QMessageBox::warning(this,"提示","密码不能为空！");
        }
        else if(!Global::isPwd(pwd)){
            QMessageBox::warning(this,"提示","密码输入格式有误！");
        }
        else if(rpwd==""){
            QMessageBox::warning(this,"提示","请重复输入密码！");
        }
        else if(pwd!=rpwd){
            QMessageBox::warning(this,"提示","密码不相同！");
        }
        else if(email==""){
            QMessageBox::warning(this,"提示","请输入邮箱！");
        }
        else if(!Global::isEmail(email)){
            QMessageBox::warning(this,"提示","邮箱格式不正确！");
        }
        //执行注册
        else{
            QStringList accountInfo = findAccountInfoById(uid);
            if(accountInfo[0] == uid){
                QMessageBox::warning(this,"提示","用户名已存在！");
            }
            else{
                QStringList fieldList,valueList;
                fieldList<<"uid"<<"pwd"<<"email";
                valueList<<uid<<pwd<<email;
                if(insertOne("account",fieldList,valueList)){
                    this->ui->QLE_uid->setText("");
                    this->ui->QLE_pwd->setText("");
                    this->ui->QLE_rpwd->setText("");
                    this->ui->QLE_email->setText("");
                    QMessageBox::warning(this,"提示","注册成功！");
                    emit this->toLogin();
                }
                else{
                    this->ui->QLE_uid->setText("");
                    this->ui->QLE_pwd->setText("");
                    this->ui->QLE_rpwd->setText("");
                    this->ui->QLE_email->setText("");
                    QMessageBox::warning(this,"错误","注册失败，请重试！");
                }
            }
        }





    });



}

Register::~Register()
{
    delete ui;
}
