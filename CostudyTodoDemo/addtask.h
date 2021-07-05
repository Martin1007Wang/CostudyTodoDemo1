#ifndef ADDTASK_H
#define ADDTASK_H

#include <QWidget>
#include"choosestar.h"

namespace Ui {
class AddTask;
}

class AddTask : public QWidget
{
    Q_OBJECT

public:
    explicit AddTask(QWidget *parent = nullptr);
    ~AddTask();
    ChooseStar *c;
private slots:
    void on_return_Button_clicked();

    void on_ack_Button_clicked();

private:
    Ui::AddTask *ui;

};

#endif // ADDTASK_H
