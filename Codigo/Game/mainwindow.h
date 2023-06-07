#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <QVector>
#include <QList>
#include <QTimer>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <string>
#include <fstream>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>

#include <QPainter>
#include "muro.h"
#include "Reliquia.h"
#include "sprite.h"
#include "fantasma.h"
#include "movimiento.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void moveFantasma_1();
    void crearMapa();
    void cambiarMapa();
    bool collidesWithWall(const QRectF& rect);
    void on_lcdNumber_overflow();


public slots:
    void onStart();
    void onUpdate();
    void onUpdate1();
    void saltar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    QTimer *timer;
    QTimer *salto;
    QTimer *salto1;
    QTimer *salto2;

    bool jmp;
    bool rot;
    bool cai;
    int puntuacion=3;
    Sprite *hero;
    Reliquia *ftm;
    int Mapa[28][123];
    QVector<Reliquia *> Reliquias;
    QVector<Muro *> Muros;

    QGraphicsLineItem *puerta1;
    QGraphicsLineItem *puerta2;
};
#endif // MAINWINDOW_H
