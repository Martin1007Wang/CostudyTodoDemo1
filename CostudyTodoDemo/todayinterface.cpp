#include "todayinterface.h"
#include "ui_todayinterface.h"
//#include"ui_addtasks.h"
#include<QStringList>
#include"thoughts.h"
#include<QWidget>
#include<QMainWindow>

TodayInterface::TodayInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TodayInterface)
{


    ui->setupUi(this);

    this->setWindowTitle("今日任务");
    QTreeWidgetTest();

}

TodayInterface::~TodayInterface()
{
    delete ui;

}


void TodayInterface::on_return_Button_clicked()
{

    this->close();
}

void TodayInterface::QTreeWidgetTest()
{
    ui->treeWidget_1->setColumnCount(1);//设置任务列数
     ui->treeWidget_2->setColumnCount(1);
    ui->treeWidget_1->setHeaderLabels(QStringList()<<"学习任务");
    ui->treeWidget_2->setHeaderLabels(QStringList()<<"复习任务");


    QTreeWidgetItem*learnitem=new QTreeWidgetItem(ui->treeWidget_1);
    LearnTasks(learnitem,"数学练习");
    LearnAttributes(learnitem,"书82到83页");
    LearnAttributes(learnitem,"二星");


    QTreeWidgetItem*reviewitem=new QTreeWidgetItem(ui->treeWidget_2);
    ReviewTasks(reviewitem,"复习单词");
    ReviewAttributes(reviewitem,"第3单元");
    ReviewAttributes(reviewitem,"三星");//这里都要用到数据库里的数据，展示任务及其星级只要重复调用这4*2个函数
}

void TodayInterface::LearnTasks(QTreeWidgetItem*item,QString learnTask)
{

    item->setText(0,learnTask);//添加学习任务

    ui->treeWidget_1->addTopLevelItem(item);

}
void TodayInterface::ReviewTasks(QTreeWidgetItem*item,QString reviewTask)
{
    item->setText(0,reviewTask);//添加复习任务
    ui->treeWidget_2->addTopLevelItem(item);

}


void TodayInterface::LearnAttributes(QTreeWidgetItem*parent,QString learnTaskRemark)
{
    QTreeWidgetItem*learnAttribute=new QTreeWidgetItem();
    learnAttribute->setText(0,learnTaskRemark);//学习任务备注

    parent->addChild(learnAttribute);
}
void TodayInterface::ReviewAttributes(QTreeWidgetItem*parent,QString reviewTaskRemark)
{
       QTreeWidgetItem*reviewAttribute=new QTreeWidgetItem();
      reviewAttribute->setText(0,reviewTaskRemark);//复习任务备注

      parent->addChild(reviewAttribute);
}






void TodayInterface::on_addTask_Button_clicked()
{
        a=new AddTask;
        a->setWindowTitle("添加任务");
        a->show();//打开增加任务界面


}

void TodayInterface::on_deleteTask_Button_clicked()
{
        //获取鼠标信息，删除特定任务
}

void TodayInterface::on_editThought_Button_clicked()
{


     t=new Thoughts;
     t->setWindowTitle("学习心得");
     t->show();//打开学习心得页面

}

void TodayInterface::on_studyRecord_Button_clicked()
{
        //打开学习记录可视化界面
}

void TodayInterface::on_startTask_Button_clicked()
{
        //获取鼠标信息，开始特定任务
}
