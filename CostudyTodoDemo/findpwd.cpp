#include "findpwd.h"
#include "QMessageBox"
#include "global.h"
#include "api_sql.h"
#include "ui_findpwd.h"

FindPwd::FindPwd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FindPwd)
{
    ui->setupUi(this);
    //界面定义
    setWindowTitle("Costudy Todo");
    ui->QLE_email->setPlaceholderText("请输入电子邮箱");

    //界面切换
    connect(ui->AT_login,&QAction::triggered,this,[=](){
        emit this->toLogin();
    });

    connect(ui->QPB_nextStep,&QPushButton::clicked,this,[=](){
        QString email = ui->QLE_email->text();
        if(email == ""){
            QMessageBox::warning(this,"提示","输入不能为空！");
        }
        else if(!Global::isEmail(email)){
            QMessageBox::warning(this,"提示","邮箱格式有误！");
        }
        else{
            QStringList accountInfo = findAccountInfoByEmail(email);
            qDebug()<<accountInfo;
            if(accountInfo[0] == ""){
                QMessageBox::warning(this,"提示","该邮箱尚未绑定！");
            }
            else{
                this->close();
                cp = new ChangePwd(this);
                cp->setGeometry(this->geometry());
                cp->show();
                connect(this,&FindPwd::sendUid,cp,[=](){
                    cp->receiveUid(accountInfo[0]);
                });
                emit this->sendUid(accountInfo[0]);

                connect(cp,&ChangePwd::sendGeo,this,[=](){
                    this->receiveGeo(cp->geometry());
                });

                connect(cp,&ChangePwd::toLogin,this,[=](){
                    emit this->passToLogin();
                });
            }
        }
    });
}

void FindPwd::receiveGeo(const QRect &geo){
    this->pass_cpGeo = geo;
}

FindPwd::~FindPwd()
{
    delete ui;
}
