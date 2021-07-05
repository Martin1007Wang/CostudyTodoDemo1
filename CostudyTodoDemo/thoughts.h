#ifndef THOUGHTS_H
#define THOUGHTS_H

#include <QWidget>

#include"showthoughts.h"
namespace Ui {
class Thoughts;
}

class Thoughts : public QWidget
{
    Q_OBJECT

public:
    explicit Thoughts(QWidget *parent = 0);
    ~Thoughts();

private slots:
    void on_return_Button_clicked();

    void on_history_Button_clicked();

    void on_ackAddReviewTasks_Button_clicked();

private:
    Ui::Thoughts *ui;
    ShowThoughts *s;


};

#endif // THOUGHTS_H
