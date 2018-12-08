#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "form.h"
#include "ui_form.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Exit", "Do you really want to leave the game?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        close();
    }
}

void MainWindow::on_pushButton_start_clicked()
{
    Form *f = new Form(ui->HardMode->checkState());
    f->show();
    this->close();
}


void MainWindow::on_pushButton_history_clicked()
{
    QMessageBox::information(this, "History",
                             "The puzzle was invented by Noyes Palmer Chapman,"
                             "a postmaster in Canastota, New York, who is said "
                             "to have shown friends, as early as 1874, "
                             "a precursor puzzle consisting of 16 numbered blocks "
                             "that were to be put together in rows of four, each summing to 34."
                             );
}
