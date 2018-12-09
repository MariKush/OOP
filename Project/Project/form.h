#ifndef FORM_H
#define FORM_H

/*
    K-28
    form.h
    Purpose: idescription of class Form functions
    (for box with a gaming field)
    @author Mariia Kushnirenko
    @version 08/12/18
*/


#include <QWidget>
#include "Game.h"
class QHBoxLayout;
class QLabel;
class QLCDNumber;
class QSpinBox;
class QVBoxLayout;

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(bool HardMode, QWidget *parent = nullptr);
    ~Form();
public slots:


private slots:
    void on_NewGame_clicked();

    void on_ExitGame_clicked();

    void on_CnangePhoto_clicked();

    void update_count_of_moves();

private:
    Ui::Form *ui;
    Game* game;
    bool hardMode;
    QHBoxLayout* settingsLayout;
    QHBoxLayout* photoLayout;
    QVBoxLayout* layout;
    QTimer* timer;
    QString WayTo;
};

#endif // FORM_H
