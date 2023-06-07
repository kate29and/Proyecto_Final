
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QGraphicsRectItem>
#include <iostream>
#include <fstream>
#include <string.h>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QPushButton>

#include <QDebug>
#include <QVector>
#include <QList>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QGraphicsView>
#include "Personaje.h"
#include "Fisicas.h"
#include "Objetos.h"
#include "Tablero.h"
#include "Arrow.h"
#include "Coin.h"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

    bool D; //controlar movimiento de las barras
    bool W;
    bool S;
    bool A;
    bool L;

public:
    MainWindow(QWidget *parent = nullptr);
    QVector<Tablero *> Bloque;
    QVector<Objetos *> Obje;
     QVector<Arrow *> fle;
    QVector<Coin *> Coins;



    ~MainWindow();
    void movimiento();
    void crearMapa(void);
    char Mapa[17][31];
    void on_lcdNumber_overflow();
    void keyPressEvent(QKeyEvent *ev); //mov precio,propi de qt
    void keyReleaseEvent(QKeyEvent *ev);
public slots:
    void onStart(void);
    void onUpdate();
    void saltar();


private:
    Objetos *objeto; // Declarar la variable objeto
    QTimer   *salto;

    QGraphicsScene *scene;
  //  QGraphicsRectItem* personaje;

    Ui::MainWindow *ui;
    QTimer *timer;
    int puntuacion=3;
    Arrow *arr;
    Personaje *personaje;

};

#endif // MAINWINDOW_H
