/*
    K-28
    form.cpp
    Purpose: implementation of class Form functions
    (for box with a gaming field)
    @author Mariia Kushnirenko
    @version 08/1218
*/

#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>


/*
    Designer class Form

    @param bool HardMode - for set hard mode
    @return -
*/
Form::Form(bool HardMode, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Form),
    game(NULL)
{
    ui->setupUi(this);

    this->hardMode=HardMode;

    //set the default image
    QDir dir=QDir::current();
    dir.cdUp();
    dir.cd("Project");
    dir.cd("paris");
    WayTo=dir.absolutePath()+"/";

    layout = new QVBoxLayout(this);
    settingsLayout = new QHBoxLayout;
    photoLayout = new QHBoxLayout;

    //add settings buttoms in Layout
    settingsLayout->addWidget(ui->NewGame);
    settingsLayout->addWidget(ui->CnangePhoto);
    settingsLayout->addWidget(ui->ExitGame);

    layout->addLayout(settingsLayout);

    on_NewGame_clicked();

    //fixing the size of the field
    this->setMaximumHeight(this->height());
    this->setMaximumWidth(this->width());

    setLayout(layout);
}


Form::~Form()
{
    delete ui;
}


/*
    Updating the number of moves

    @param -
    @return -
*/
void Form::update_count_of_moves()
{
    ui->countMoves->setText(QString::number(game->countMoves)+" moves");
}


/*
    Create new game

    @param -
    @return -
*/
void Form::on_NewGame_clicked()
{
    //delete the old field
    if(game)
    {
        photoLayout->removeWidget(game);
        if (!hardMode)
            photoLayout->removeWidget(ui->originalPhoto);
        layout->removeWidget(ui->countMoves);
        layout->removeItem(photoLayout);

        delete game;
    }

    //draw a new field
    game = new Game(WayTo, this);
    connect(this->game, SIGNAL(Smove()), this, SLOT(update_count_of_moves()));
    update_count_of_moves();
    photoLayout->addWidget(game);

    //installing a hint (original photo) for easy mode
    if (!hardMode)
    {
        QPixmap img(WayTo+"0.jpg");
        img=img.scaled(600,600);
        ui->originalPhoto->setPixmap(img);
        photoLayout->addWidget(ui->originalPhoto);
    }

    layout->addLayout(photoLayout);
    layout->addWidget(ui->countMoves);
    layout->update();

    game->show();

    resize(sizeHint());
}


/*
    Back to the mainwindow

    @param -
    @return -
*/
void Form::on_ExitGame_clicked()
{
    MainWindow *f = new MainWindow();
    f->show();
    this->close();
}

/*
    On CnangePhoto clicked

    @param -
    @return -
*/
void Form::on_CnangePhoto_clicked()
{
    //opens a folder with pictures
    QString FileName =QFileDialog::getOpenFileName(this, tr("Open File"),"C:/Users/Dell-admin/Desktop/pictures","*.jpg");
    if (FileName.isEmpty())return;

    QImage* original=new QImage(FileName);
    FileName=FileName.right(FileName.length()-FileName.lastIndexOf(QChar('/'))-1);
    FileName=FileName.left(FileName.lastIndexOf(QChar('.')));

    int min=qMin(original->width(), original->height());
    min=min-min%N;//make kratne N

    QImage* SquareImage=new QImage;
    *SquareImage=original->copy(0, 0,min,min);
    delete original;

    QDir(game->FileDir).mkdir(FileName);
    WayTo=game->FileDir+FileName+"/";
    SquareImage->save(WayTo+"0.jpg");

    int LSSize=min/N;//LittleSquareSize

    //creating N*N-1 small photos and save their
    for (int i=1;i<N*N;i++)
    {
        QImage* LittleSquare=new QImage;
        *LittleSquare=SquareImage->copy(((i-1)%N)*LSSize, (i-1)/N*LSSize, LSSize, LSSize);
        LittleSquare->save(WayTo+QString::number(i)+".jpg");
    }

    on_NewGame_clicked();

}
