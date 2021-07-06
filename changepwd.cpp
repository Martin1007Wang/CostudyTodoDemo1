//#include "changepwd.h"
//#include "global.h"
//#include "api_sql.h"
//#include <QMessageBox>
//#include "ui_changepwd.h"

//ChangePwd::ChangePwd(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::ChangePwd)
//{
//    ui->setupUi(this);
//    ui->setupUi(this);
//    //窗口定义
//    setWindowTitle("航班售票系统");
//    setWindowIcon(QIcon(":/source/titleIcon.png"));
//    setFixedSize(430,300);
//    ui->QLE_pwd->setPlaceholderText("请重复输入密码");
//    ui->QLE_rpwd->setPlaceholderText("请重复输入密码");
//    ui->QLE_pwd->setEchoMode(QLineEdit::Password);
//    ui->QLE_pwd->setMaxLength(20);
//    ui->QLE_rpwd->setMaxLength(20);
//    ui->QLE_rpwd->setEchoMode(QLineEdit::Password);

//    connect(ui->QPB_confirm,&QPushButton::clicked,this,[=](){
//        QString pwd = ui->QLE_pwd->text();
//        QString rpwd = ui->QLE_rpwd->text();
//        if(pwd==""){
//            QMessageBox::warning(this,"提示","密码不能为空！");
//        }
//        else if(!Global::isPwd(pwd)){
//            QMessageBox::warning(this,"提示","密码输入格式有误！");
//        }
//        else if(rpwd==""){
//            QMessageBox::warning(this,"提示","请重复输入密码！");

//        }
//        else if(pwd!=pwd){
//            QMessageBox::warning(this,"提示","密码不相同！");
//        }
//        else{
//            if(changePwdByUid(this->uid,pwd)){
//                QMessageBox::warning(this,"提示","修改密码成功！");
//                emit this->sendGeo(this->geometry());
//                emit this->toLogin();
//                this->close();
//            }
//            else{
//                ui->QLE_pwd->setText("");
//                ui->QLE_rpwd->setText("");
//                QMessageBox::warning(this,"提示","修改失败，请重试！");
//            }
//        }
//    });
//}

//void ChangePwd::receiveUid(const QString &uid){
//    this->uid = uid;
//}

//ChangePwd::~ChangePwd()
//{
//    delete ui;
//}
