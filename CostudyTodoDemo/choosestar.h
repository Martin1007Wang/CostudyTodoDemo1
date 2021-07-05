#ifndef CHOOSESTAR_H
#define CHOOSESTAR_H
#include<QMessageBox>

#include <QWidget>

namespace Ui {
class ChooseStar;
}

class ChooseStar : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseStar(QWidget *parent = nullptr);
    ~ChooseStar();

private slots:
    void on_return_Button_clicked();

    void on_ack_Button_clicked();

private:
    Ui::ChooseStar *ui;
};

#endif // CHOOSESTAR_H
