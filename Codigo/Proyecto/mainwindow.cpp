#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 780, 400);

    QBrush backgroundBrush(Qt::black); // Crea un pincel con el color negro
    scene->setBackgroundBrush(backgroundBrush);

    A = false; // movi
    D = false;
    W = false;
    S = false;
    timer = new QTimer();
    timer->start(33);
    personaje = new QGraphicsRectItem(0, 355, 20, 20);
    QBrush brush(Qt::darkCyan);
    personaje->setBrush(brush);
    scene->addItem(personaje);
    crearMapa();
    ui->lcdNumber->display(puntuacion);
  //  arrowObj.inicializar();


   // time = new QTimer(this);
    //connect(time, &QTimer::timeout, this, &MainWindow::movimiento);

    //connect(timer,SIGNAL(timeout()),this,SLOT(movimiento()));
    connect(timer,&QTimer :: timeout, this, &MainWindow::movimiento);
    connect(ui->lcdNumber, SIGNAL(overflow()), this, SLOT(on_lcdNumber_overflow()));

   // objeto->mover();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;

}
void MainWindow::crearMapa(void)
{
    string myText = "";
    ifstream Mundo;
    Mundo.open("mapa.txt");



    for(int i=0;getline (Mundo, myText) ;i++) {
        cout<<myText<<endl;
        for(unsigned int j=0 ; j< myText.size(); j++) {
            Mapa[i][j]=myText[j];
        }
    }

    Mundo.close();
    Bloque.clear();
    Obje.clear();
    fle.clear();
    Coins.clear();

    for(int i=0 ; i<17 ; i++){
        for(int j=0 ; j<31 ; j++){
            if(Mapa[i][j]=='+'){
                Bloque.push_back(new Tablero(j*25,i*25,1));
                scene->addItem(Bloque.last());
            }
            else if(Mapa[i][j]=='*'){
                Coins.push_back(new Coin(j*25,i*25,1));
                scene->addItem(Coins.last());
            }
            else if(Mapa[i][j]=='-'){
                fle.push_back(new Arrow(j*20,i*20));
                scene->addItem(fle.last());
            }
            else if(Mapa[i][j]=='/'){
                Obje.push_back(new Objetos(j*20,i*20));
                scene->addItem(Obje.last());


            }
           /* else if(Mapa[i][j]=='/'){
                personaje=new QGraphicsRectItem(0,355,20,20);
                QBrush brush(Qt::darkGreen);
                personaje->setBrush(brush);
                scene->addItem(personaje);
            }*/

        }
    }
}
void MainWindow::movimiento(){
    bool colisionConBarra = true;

    QList<QGraphicsItem *> Colisiones = scene->collidingItems(personaje);
    if (!Colisiones.isEmpty()) {
        for (auto K : Colisiones) {
            Tablero *barra = dynamic_cast<Tablero *>(K);
            Coin *con = dynamic_cast<Coin *>(K);
            if (barra) {
                if (barra->getMuroTipe() == 1 && A == true) {
                    personaje->setPos(personaje->x() - 2, personaje->y());
                }
                if (barra->getMuroTipe() == 1 && D == true) {
                    float u = 10.0; // Velocidad inicial hacia la derecha
                    float a = 2.0; // Aceleración hacia la derecha
                    float t = 0.33; // Intervalo de tiempo (33 milisegundos)

                    float displacement = u * t + (0.5 * a * t * t);
                    personaje->setPos(personaje->x() + displacement, personaje->y());
                }
                if (barra->getMuroTipe() == 1 && W == true) {
                    personaje->setPos(personaje->x(), personaje->y() - 2);
                }
                if (con && !barra->getMuroTipe() == 1) {
                    colisionConBarra = false;
                }
            }

                if (barra == nullptr) {
                    if (barra->getMuroTipe() != 1 && S == true) {
                        personaje->setPos(personaje->x(), personaje->y() + 2);
                    }
                   /* if (colisionConBarra) {
                        personaje->setPos(personaje->x(), personaje->y() + 2);
                        colisionConBarra = true;
                    }*/
                }

            Objetos *obj = dynamic_cast<Objetos *>(K);
            if (obj) {
                MainWindow::on_lcdNumber_overflow();
                scene->removeItem(obj);
                Obje.removeOne(obj);
            }
            Arrow *arro = dynamic_cast<Arrow *>(K);
            if (arro) {
                arro->movimiento1();
            }
        }
    }



    // objeto->mover(); // Llama al método mover() de la instancia objeto

}

/*void MainWindow::movimiento()
{

    bool colisionConBarra = false;


    QList<QGraphicsItem *> Colisiones = scene->collidingItems(personaje);
    if(!Colisiones.isEmpty()){
        for(auto K:Colisiones){
            Tablero *barra=dynamic_cast<Tablero *>(K);
            Coin *con=dynamic_cast<Coin *>(K);
            if(barra){
                if(barra->getMuroTipe()==1 && A==true )
                {
                    personaje->setPos(personaje->x()-2,personaje->y());
                }

                if(barra->getMuroTipe()==1 && D==true)
                {
                    float u = 10.0; // Velocidad inicial hacia la derecha
                    float a = 2.0; // Aceleración hacia la derecha
                    float t = 0.33; // Intervalo de tiempo (33 milisegundos)

                    float displacement = u * t + (0.5 * a * t * t);
                    personaje->setPos(personaje->x() + displacement, personaje->y());

                }
                if(barra->getMuroTipe()==1 && W==true)
                {
                    personaje->setPos(personaje->x(),personaje->y()-2);


                }
                if (con && !barra->getMuroTipe() == 1)
                {
                    colisionConBarra = true;


                   /* if (!colisionConBarra) {
                        personaje->setPos(personaje->x(), personaje->y() + 2);
                    }
                }

            }
            else if(!barra){
                colisionConBarra = true;

                    personaje->setPos(personaje->x(),personaje->y()+2);


                /*if (colisionConBarra) {
                    personaje->setPos(personaje->x(), personaje->y() + 2);
                    colisionConBarra=false;

                }
            }
            Objetos *obj = dynamic_cast<Objetos *>(K);
            if(obj){
            MainWindow::on_lcdNumber_overflow();
            scene->removeItem(obj);
            Obje.removeOne(obj);
            }
            Arrow *arro = dynamic_cast<Arrow *>(K);
            if(arro){

            arro->movimiento1();
            }
            /*else if(!barra) {
                if(!barra->getMuroTipe()==0 && A==False )
                {
                    personaje->setPos(personaje->x(),personaje->y()+2);
                 }}



        }


    }
 /*  if (colisionConBarra) {
        personaje->setPos(personaje->x(), personaje->y() + 2);
        colisionConBarra=false;

    }

 //objeto->mover(); // Llama al método mover() de la instancia objeto
}*/


void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A) //si ev == a el estandar de qt
    {
        A=true;
    }

    else if(ev->key()==Qt::Key_W)
    {
        W=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        D=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        S=true;
    }
    else if(ev->key()==Qt::Key_L)
    {
        L=true;
    }

}
void MainWindow::keyReleaseEvent(QKeyEvent *ev){
    if(ev->key()==Qt::Key_A)
    {
        A=false;
    }

    else if(ev->key()==Qt::Key_W)
    {
        W=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        D=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        S=false;
    }
    else if(ev->key()==Qt::Key_L)
    {
        L=true;
    }

}
void MainWindow::on_lcdNumber_overflow()
{
    puntuacion--;
    ui->lcdNumber->display(puntuacion);

}
