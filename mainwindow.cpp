#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_endButton_clicked()
{
this->close();
}
void MainWindow::on_startButton_clicked()
{
        TodayInterface * Today = new(TodayInterface);
        this->close();
        Today ->show();

}
