#ifndef NOTDISTURB_H
#define NOTDISTURB_H

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
