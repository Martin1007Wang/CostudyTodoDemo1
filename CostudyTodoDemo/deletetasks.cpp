#include "deletetasks.h"
#include "ui_deletetasks.h"

DeleteTasks::DeleteTasks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteTasks)
{
    ui->setupUi(this);
}

DeleteTasks::~DeleteTasks()
{
    delete ui;
}
