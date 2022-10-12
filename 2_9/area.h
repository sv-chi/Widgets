#ifndef AREA_H
#define AREA_H
#include "figura.h"
#include <QWidget>

class Area : public QWidget
{
int myTimer; // идентификатор таймера
float alpha; // угол поворота
public:
Area(QWidget *parent = 0);// конструктор
~Area();//деструктор
MyLine *myline;// класс линии
MyRect *myrect;// класс квадрата
protected:
//обработчики событий
void paintEvent(QPaintEvent *event);//событие перерисовки, рисование пошагово перемещающихся фигур;
void timerEvent(QTimerEvent *event);//событие таймера, инициация перерисовки Холста
void showEvent(QShowEvent *event);// событие начала
void hideEvent(QHideEvent *event);// событие конца
};
#endif // AREA_H
