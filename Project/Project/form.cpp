#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>

Form::Form(bool HardMode, QWidget *parent):game(NULL),
    QWidget(parent),
    ui(new Ui::Form)
{
    this->hardMode=HardMode;
    QDir dir=QDir::current();
    dir.cdUp();
    dir.cd("Project");
    dir.cd("paris");
    WayTo=dir.absolutePath()+"/";

    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    settingsLayout = new QHBoxLayout;
    photoLayout = new QHBoxLayout;

    settingsLayout->addWidget(ui->NewGame);
    settingsLayout->addWidget(ui->CnangePhoto);
    settingsLayout->addWidget(ui->ExitGame);

    layout->setContentsMargins(2, 2, 2, 2);
    layout->addLayout(settingsLayout);
    on_NewGame_clicked();

    setLayout(layout);

    connect(this->game, SIGNAL(Smove()), this, SLOT(update_count_of_moves()));
}

void Form::update_count_of_moves()
{
    ui->countMoves->setText(QString::number(game->countMoves)+" moves");
}


Form::~Form()
{
    delete ui;
}

void Form::on_NewGame_clicked()
{
    if(game) //delete the old field
    {
        layout->removeWidget(game);
        delete game;
    }

    game = new Game(WayTo, this); //draw a new field
    photoLayout->addWidget(game);
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

    game->hide();
    game->show();

    resize(sizeHint());
}

void Form::on_ExitGame_clicked()
{
    MainWindow *f = new MainWindow();
    f->show();
    this->close();
}

void Form::on_CnangePhoto_clicked()
{
    QString FileName =QFileDialog::getOpenFileName(this, tr("Open File"),"C:/Users/Dell-admin/Desktop/pictures","*.jpg");
    if (FileName.isEmpty())return;
    QImage* original=new QImage(FileName);
    FileName=FileName.right(FileName.length()-FileName.lastIndexOf(QChar('/'))-1);
    FileName=FileName.left(FileName.lastIndexOf(QChar('.')));
    int min=qMin(original->width(), original->height());
    min=min-min%4;//make kratne 4
    int LSSize=min/4;//LittleSquareSize
    QImage* SquareImage=new QImage;
    *SquareImage=original->copy(0, 0,min,min);
    delete original;
    QDir(game->FileDir).mkdir(FileName);
    WayTo=game->FileDir+FileName+"/";
    SquareImage->save(WayTo+"0.jpg");

    for (int i=1;i<16;i++)
    {
        QImage* LittleSquare=new QImage;
        *LittleSquare=SquareImage->copy(((i-1)%4)*LSSize,(i-1)/4*LSSize,
                                        LSSize, LSSize);
        LittleSquare->save(WayTo+QString::number(i)+".jpg");
    }

    on_NewGame_clicked();

}
