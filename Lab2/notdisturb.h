#ifndef NOTDISTURB_H
#define NOTDISTURB_H

/*
    K-28
    notdisturb.h
    Purpose: description class NotDisturb
    @author Mariia Kushnirenko
    @version 1.1 20/11/18
*/

#include <QDialog>
#include <QDebug>
namespace Ui {
class NotDisturb;
}

class NotDisturb : public QDialog
{
    Q_OBJECT

public:
    explicit NotDisturb(QWidget *parent = nullptr);
    ~NotDisturb();

    bool not_disturb = false;

    bool can_call();
private:
    Ui::NotDisturb *ui;
};

#endif // NOTDISTURB_H
