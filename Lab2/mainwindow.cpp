/*
    K-28
    mainwindow.cpp
    Purpose: implementation of class MainWindow functions
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(alarms, SIGNAL(alarm_ring()),this, SLOT(call_ring()));
    connect(timers, SIGNAL(timer_ring()),this, SLOT(call_ring()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_gotoTimer_clicked()//open timer window
{
    timers->show();
    timers->setWindowTitle("Timer");
}

void MainWindow::on_gotoAlarm_clicked()
{
    alarms->show();
    alarms->setWindowTitle("Alarm");
}

void MainWindow::call_ring()
{
    general_ring.call();
}
