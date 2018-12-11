/*
    K-28
    mainwindow.cpp
    Purpose: implementation of class MainWindow functions
    @author Mariia Kushnirenko
    @version 1.1 20/11/18
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
    QString path = QDir::currentPath();

    path=path.left(path.lastIndexOf(QChar('/')));
    path+="/Lab2/files";
    general_ring.FileDialog.setDirectory(path);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
    Open and set title in timer window

    @param -
    @return -
*/
void MainWindow::on_gotoTimer_clicked()
{
    timers->show();
    timers->setWindowTitle("Timer");
}

/*
    Open and set title in alarm window

    @param -
    @return -
*/
void MainWindow::on_gotoAlarm_clicked()
{
    alarms->show();
    alarms->setWindowTitle("Alarm");
}

/*
    Call, if the do not disturb function is not enabled, for a given time period
    @param -
    @return -
*/
void MainWindow::call_ring()
{
    if (not_disturb_MW.can_call())
        general_ring.call();
}

/*
    When you click on the check mark, change status does not disturb
    @param -
    @return -
*/
void MainWindow::on_checkBox_stateChanged()
{
    not_disturb_MW.not_disturb = !not_disturb_MW.not_disturb;
}

/*
    Opens a window to set the "do not disturb" period
    @param -
    @return -
*/
void MainWindow::on_not_disturb_setting_clicked()
{
    not_disturb_MW.show();
}

/*
    for choose music (open directory with mp3 files)
    @param -
    @return -
*/
void MainWindow::on_SetMusic_clicked()
{
    general_ring.player.setMedia(QUrl(general_ring.FileDialog.getOpenFileName(this,tr("Chose music"),"" , "*.mp3")));
}
