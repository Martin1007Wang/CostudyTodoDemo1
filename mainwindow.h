#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"todayinterface.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

private slots:
    void on_startButton_clicked();
    void on_endButton_clicked();
};

#endif // MAINWINDOW_H
