#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(13,0,780,450);

    A=false; //movi
    S=false;
    D=false;
    W=false;

    personaje=new QGraphicsRectItem(-30,-30,60,60);//añade
    scene->addItem(personaje);//existe en escena
    personaje->setPos(200,200);
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(movimiento()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::movimiento()
{

    if(A )
    {
        personaje->setPos(personaje->x()-2,personaje->y()+1);
    }
    if(S )
    {
        personaje->setPos(personaje->x()+2,personaje->y());
    }
    if(W)
    {
        personaje->setPos(personaje->x(),personaje->y()-2);
    }
    if(D)
    {
        personaje->setPos(personaje->x(),personaje->y()+2);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A) //si ev == a el estandar de qt
    {
        A=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        S=true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        W=true;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        D=true;
    }

}
void MainWindow::keyReleaseEvent(QKeyEvent *ev){
    if(ev->key()==Qt::Key_A)
    {
        A=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        S=false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        W=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        D=false;
    }

}
