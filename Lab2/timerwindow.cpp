/*
    K-28
    timerwindow.cpp
    Purpose: implementation of class TimerWindow functions
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/

#include "timerwindow.h"
#include "ui_timerwindow.h"

TimerWindow::TimerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerWindow)
{
    ui->setupUi(this);
}

TimerWindow::~TimerWindow()
{
    delete ui;
}
