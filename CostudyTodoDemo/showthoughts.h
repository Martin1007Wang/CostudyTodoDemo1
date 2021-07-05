#ifndef SHOWTHOUGHTS_H
#define SHOWTHOUGHTS_H

#include <QWidget>

namespace Ui {
class ShowThoughts;
}

class ShowThoughts : public QWidget
{
    Q_OBJECT

public:
    explicit ShowThoughts(QWidget *parent = nullptr);
    ~ShowThoughts();
    void on_return_button_clicked();

private:
    Ui::ShowThoughts *ui;
};

#endif // SHOWTHOUGHTS_H
