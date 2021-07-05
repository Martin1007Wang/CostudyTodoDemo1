#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

signals:
    void toLogin();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
