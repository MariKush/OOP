#include "ring.h"
#include "ui_ring.h"
#include<QDebug>
ring::ring(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ring)
{
    ui->setupUi(this);
    QString path = QDir::currentPath();

    path=path.left(path.lastIndexOf(QChar('/')));
    path+="/Lab2/files/sound1.mp3";
    qDebug()<<path;
    player.setMedia(QUrl(path));
}

ring::~ring()
{
    delete ui;
}

void ring::call()
{
    show();
    player.play();
}

void ring::closeEvent(QCloseEvent *event)
{
    this->player.stop();

}
