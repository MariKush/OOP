#ifndef RING_H
#define RING_H

/*
    K-28
    ring.h
    Purpose: description class Ring
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/


#include <QDialog>
#include <QMediaPlayer>
#include <QDir>

namespace Ui {
class ring;
}

class Ring : public QDialog
{
    Q_OBJECT

public:
    explicit Ring(QWidget *parent = nullptr);
    ~Ring();
    void call();
    void closeEvent(QCloseEvent *event);
private:
    QMediaPlayer player;
    Ui::ring *ui;
};

#endif // RING_H
