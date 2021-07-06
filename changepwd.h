#ifndef CHANGEPWD_H
#define CHANGEPWD_H

#include <QMainWindow>

namespace Ui {
class ChangePwd;
}

class ChangePwd : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangePwd(QWidget *parent = nullptr);
    ~ChangePwd();

private:
    Ui::ChangePwd *ui;
    QString uid;

signals:
    void sendGeo(const QRect &geo);
    void toLogin();

public slots:
    void receiveUid(const QString &uid);
};

#endif // CHANGEPWD_H
