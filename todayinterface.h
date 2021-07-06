#ifndef TODAYINTERFACE_H
#define TODAYINTERFACE_H

#include"clockpage.h"
#include <QMainWindow>
#include<QTreeWidgetItem>
#include<QMainWindow>
#include"mainwindow.h"
#include"thoughts.h"
#include"addtask.h"


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class TodayInterface; }
QT_END_NAMESPACE


class TodayInterface : public QWidget
{
    Q_OBJECT

public:
    TodayInterface(QWidget *parent = 0);
    ~TodayInterface();
    void QTreeWidgetTest();
    void LearnTasks(QTreeWidgetItem*,QString);//加学习任务
    void ReviewTasks(QTreeWidgetItem*,QString);//加复习任务
    void LearnAttributes(QTreeWidgetItem*parent,QString);//在表中加任务属性
    void ReviewAttributes(QTreeWidgetItem*parent,QString);
    Thoughts *t;
    AddTask*a;


private slots:
    void on_return_Button_clicked();

    void on_addTask_Button_clicked();

    void on_deleteTask_Button_clicked();

    void on_editThought_Button_clicked();

    void on_studyRecord_Button_clicked();

    void on_startTask_Button_clicked();

private:
    Ui::TodayInterface *ui;


};

#endif // TODAYINTERFACE_H
