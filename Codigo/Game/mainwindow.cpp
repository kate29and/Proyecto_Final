#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1481,911);
//    scene->setSceneRect(-350,-400,1481,911);


    ui->graphicsView->setScene(scene);
    hero=nullptr;
    ftm=nullptr;

    connect(ui->pB_start, &QPushButton::clicked,
            this, &MainWindow::onStart);
    ui->graphicsView->scale(1.3,1.3);//escala
    scene->setSceneRect(0,0,3700,925);

    salto= new QTimer();
    connect(salto,SIGNAL(timeout()),this,SLOT(saltar()));

    salto1= new QTimer();
    connect(salto1,SIGNAL(timeout()),this,SLOT(onUpdate( )));
    salto2= new QTimer();
    connect(salto1,SIGNAL(timeout()),this,SLOT(onUpdate1( )));
    connect(ui->lcdNumber, SIGNAL(overflow()), this, SLOT(on_lcdNumber_overflow()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A){
        hero->orientacion(2);
        hero->left();
    }else if(event->key()==Qt::Key_D){
        hero->orientacion(3);
        hero->right();
    }else if(event->key()==Qt::Key_W){
        QRectF nextRect = hero->boundingRect();
        nextRect.moveLeft(nextRect.left() - 1); // Calcular la siguiente posición
        if (!hero->collidesWithWall(nextRect)) {
            hero->orientacion(2);
            hero->up();
        }


    }else if(event->key()==Qt::Key_S){
        QRectF nextRect = hero->boundingRect();
        nextRect.moveRight(nextRect.right() + 1); // Calcular la siguiente posición
        if (!hero->collidesWithWall(nextRect)) {
            hero->orientacion(3);
            hero->down();
        }

    }else if(event->key()==Qt::Key_E ){
        salto1->start(10);
        jmp = false;
        cai = true;

    }else if(event->key()==Qt::Key_Q ){
         salto2->start(10);
         jmp = false;
         cai = true;

    }else if(event->key()==Qt::Key_Space){
        salto->start(10);

    }
    if (hero->collidesWithItem(ftm)) {
        MainWindow::on_lcdNumber_overflow();
        scene->removeItem(ftm);
        Reliquias.removeOne(ftm);
    }

    if(!scene->views().isEmpty()){
    scene->views().first()->centerOn(hero);
    }
}


void MainWindow::onStart()
{
    hero = new Sprite();
    scene->addItem(hero);
    //scene->setBackgroundBrush(QBrush(QImage(":/fondo.webp").scaled(1920,1080)));//podemos usar la escala y omitirla, probar.
    crearMapa();

    timer = new QTimer;
    timer->start(1);

    QGraphicsLineItem linea(0,0,350,350);
    scene->addItem(&linea);

    salto= new QTimer();
    connect(salto,SIGNAL(timeout()),this,SLOT(saltar()));

    salto1= new QTimer();
     connect(salto1,SIGNAL(timeout()),this,SLOT(onUpdate()));

    salto2= new QTimer();
    connect(salto2,SIGNAL(timeout()),this,SLOT(onUpdate1()));


    ui->pB_start->hide();
}


/*void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // ...

    if (event->key() == Qt::Key_A) {
    // Verificar colisión con el muro antes de mover hacia la izquierda
    QRectF nextRect = hero->boundingRect();
    nextRect.moveLeft(nextRect.left() - 1); // Calcular la siguiente posición
    if (!hero->collidesWithWall(nextRect)) {
        hero->orientacion(2);
        hero->left();
    }
    }
    else if (event->key() == Qt::Key_D) {
    // Verificar colisión con el muro antes de mover hacia la derecha
    QRectF nextRect = hero->boundingRect();
    nextRect.moveRight(nextRect.right() + 1); // Calcular la siguiente posición
    if (!hero->collidesWithWall(nextRect)) {
        hero->orientacion(3);
        hero->right();
    }
    }

    // ...
}*/


void MainWindow::saltar()
{
    hero->CalcularVelocidad();
    hero->CalcularPosicion();
    hero->ActualizarVelocidad();
}

void MainWindow::onUpdate()
{
    if (!jmp) {
    jmp = true;
    cai = false;
    hero->setPos(hero->x()+10, hero->y() - 50); // Mover el objeto hacia arriba
    QTimer::singleShot(250, [this]() {
        hero->setPos(hero->x()+10, hero->y() + 50); // Mover el objeto hacia abajo después de un tiempo

    });
    }
}

void MainWindow::onUpdate1()
{
    if (!jmp) {
    jmp = true;
    cai = false;
    hero->setPos(hero->x()-10, hero->y() - 50); // Mover el objeto hacia arriba
    QTimer::singleShot(250, [this]() {
        hero->setPos(hero->x()-10, hero->y() + 50); // Mover el objeto hacia abajo después de un tiempo

    });
    }
}
/*void MainWindow::saltar1()
{
    if (hero->isJumping) {
    hero->currentHeight += hero->jumpSpeed;
    if (hero->currentHeight >= hero->jumpHeight) {
            hero->currentHeight = hero->jumpHeight;
            hero->isJumping = false;
            // Aquí puedes agregar cualquier animación o efecto de sonido cuando el salto se completa
    }

    // Calcula la nueva posición vertical del sprite
    qreal newY = hero->pos().y() - hero->jumpSpeed;
    hero->setPos(hero->pos().x(), newY);
    }
}*/

void MainWindow::crearMapa()
{
    string myText = "";
    ifstream MyReadFile("mapa.txt");

    int i=0;
    while (getline (MyReadFile, myText)) {
        for(int j=0 ; j<int(myText.size()) ; j++){
            Mapa[i][j]=myText[j];
        }
        i+=1;
    }

    MyReadFile.close();

   Muros.clear();
    Reliquias.clear();

    for(int i=0 ; i<28 ; i++){
        for(int j=0 ; j<123 ; j++){
            if(Mapa[i][j]=='+'){
                Muros.push_back(new Muro(j*30,i*30,1));
                scene->addItem(Muros.last());
            }else if(Mapa[i][j]=='p'){
                Reliquias.push_back(new Reliquia(j * 30, i * 30));
                scene->addItem(Reliquias.last());
            }

        }
    }
}
void MainWindow::on_lcdNumber_overflow()
{
    puntuacion--;
    ui->lcdNumber->display(puntuacion);

}
