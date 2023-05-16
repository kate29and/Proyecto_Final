
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


#include "personaje.h"
#include "fisicas.h"
#include "objetos.h"
#include "Tablero.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void movimiento();

private:
    QGraphicsScene *scene;
    QGraphicsRectItem* personaje;
    Ui::MainWindow *ui;
    QTimer *timer;
    void keyPressEvent(QKeyEvent *ev); //mov precio,propi de qt
    void keyReleaseEvent(QKeyEvent *ev);
    bool D; //controlar movimiento de las barras
    bool W;
    bool S;
    bool A;
};

#endif // MAINWINDOW_H
