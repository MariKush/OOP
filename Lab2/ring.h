#ifndef RING_H
#define RING_H

#include <QDialog>
#include <QMediaPlayer>
#include <QDir>

namespace Ui {
class ring;
}

class ring : public QDialog
{
    Q_OBJECT

public:
    explicit ring(QWidget *parent = nullptr);
    ~ring();
    void call();
    void closeEvent(QCloseEvent *event);
private:
    QMediaPlayer player;
    Ui::ring *ui;
};

#endif // RING_H
