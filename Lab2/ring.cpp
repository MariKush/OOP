/*
    K-28
    ring.cpp
    Purpose: implementation of class Ring functions
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/


#include "ring.h"
#include "ui_ring.h"
#include<QDebug>
Ring::Ring(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ring)
{
    ui->setupUi(this);
    QString path = QDir::currentPath();

    path=path.left(path.lastIndexOf(QChar('/')));
    path+="/Lab2/files/Rington.mp3";
    qDebug()<<path;
    player.setMedia(QUrl(path));
}

Ring::~Ring()
{
    delete ui;
}

void Ring::call()
{
    show();
    player.play();
}

void Ring::closeEvent(QCloseEvent *event)
{
    this->player.stop();

}
