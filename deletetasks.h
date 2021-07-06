#ifndef DELETETASKS_H
#define DELETETASKS_H

#include <QWidget>

namespace Ui {
class DeleteTasks;
}

class DeleteTasks : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteTasks(QWidget *parent = nullptr);
    ~DeleteTasks();

private:
    Ui::DeleteTasks *ui;
};

#endif // DELETETASKS_H
