#include "Game.h"
#include "mainwindow.h"
#include <QtGlobal>
#include <QGridLayout>
#include <QPoint>
#include <QPushButton>
#include <QTime>
#include "QMessageBox"
#include <cstdlib>
#include <QDir>
#include <QDebug>

void Game::ChangePhoto(QString s)
{
    for(int i=0;i<15;i++)
    {
        px[i]=new QPixmap(s+QString::number(i+1)+".jpg");
        qDebug()<<s+QString::number(i+1)+".jpg";
    }
}

Game::Game(QString s, QWidget*)
{
    grid = new QGridLayout(this);
    grid->setHorizontalSpacing(1);
    grid->setVerticalSpacing(1);
    grid->setContentsMargins(2, 2, 2, 2);

    QTime midnight(0, 0, 0);
    srand(midnight.msecsTo(QTime::currentTime()));
    FileDir=QDir::currentPath();
    FileDir=FileDir.left(FileDir.lastIndexOf(QChar('/')))+"/Project/";
    // pictures
    for(int i=0;i<15;i++)
    {
        px[i]=new QPixmap(s+QString::number(i+1)+".jpg");
    }
    //
    int n;

    do
    {
        numbers.clear();

        for(int i = 0; i < 15; i++)
        {
            do
                n = rand() % 15 + 1;
            while(numbers.contains(n));
            numbers << n;
        }

        n = 0;

        for(int i = 2; i <= 15; i++)
            for(int j = 0; j < numbers.indexOf(i); j++)
            {
                if(numbers[j] < i)
                {
                    ++n;
                }
            }
    } while(n%2 == 1);

    do
        path.setY(rand() % 4);
    while(n%2 != path.y()%2);

    path.setX(rand() % 4);

    n = 0;

    for(int y = 0; y < 4; ++y) // line
        for(int x = 0; x < 4; ++x) // column
        {
            if(path.x() == x && path.y() == y)
                continue;

            createButton(nullptr, numbers[n++], x, y);
        }
    setLayout(grid);
}

void Game::move()
{

    int x, y, rs, cs;
    QPushButton* clickedBtn = static_cast<QPushButton*>(sender());
    grid->getItemPosition(grid->indexOf(clickedBtn), &y, &x, &rs, &cs);

    if((path.x() == x && (path.y() == y+1 || path.y() == y-1))
    || (path.y() == y && (path.x() == x+1 || path.x() == x-1))) // Can you move the button?
    {
        countMoves++;
        emit Smove();
        // we remove the button from the old place
        grid->removeWidget(clickedBtn);
        // and add it to a free cell
        createButton(clickedBtn, 0, path.x(), path.y());
        // and we update the coordinates of a free cell
        path = QPoint(x, y);
        checkGameOver(); // Checking for the end of the game
    }
}

void Game::checkGameOver()
{
    Q_ASSERT(grid->count() == numbers.size());

    int i=1, n=0;

    for(int y = 0; y < grid->rowCount(); ++y) // line
    for(int x = 0; x < grid->columnCount(); ++x) // column
    {
        if(grid->itemAtPosition(y, x) == nullptr)
            continue;
        n = numbers.indexOf(i++);
        if(buttons[n] != (QPushButton*)grid->itemAtPosition(y, x)->widget())
            return;
    }

    // check whether the last cell is free
    if(path.y() == grid->rowCount()-1 && path.x() == grid->columnCount()-1)
    { // the game is over
        // block all buttons
        for(QList<QPushButton*>::const_iterator it = buttons.begin(); it != buttons.end(); ++it)
            (*it)->setDisabled(true);
        QMessageBox::information(this, "message", "THE VICTORY!!!");
    }
}

void Game::createButton(QPushButton* b, int no, int x, int y) // Create a button
{
    QPushButton* btn = b;
    if(!btn)
    {
        btn = new QPushButton();//(QString("%1").arg(no));
        buttons << btn;
        connect(btn, SIGNAL(clicked()), this, SLOT(move()));
        btn->setFixedSize(150,150);

        QIcon ButtonIcon(*px[no-1]);
        btn->setIcon(ButtonIcon);
        btn->setIconSize(QSize(150,150));

    }
    grid->addWidget(btn, y, x);
}
