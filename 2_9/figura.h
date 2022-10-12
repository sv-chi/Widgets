#ifndef FIGURA_H
#define FIGURA_H

#include <QtGui>

class Figura//класс родитель для фигур
{
protected:
int x,y,halflen,dx,dy,r;//определение переменных координат и размера фигуры
virtual void draw(QPainter *Painter)=0;//виртуальная функция для рисования фигур
public:
Figura(int X,int Y,int Halflen):
x(X),y(Y),halflen(Halflen){}//конструктор размера и положения объекта
void move(float Alpha,QPainter *Painter);
};

class MyLine:public Figura//класс линии
{
protected:
void draw(QPainter *Painter);//метод рисования линии
public:
MyLine(int x,int y,int halflen):Figura(x,y,halflen){}//конструктор размера и позиции
};

class MyRect:public Figura//класс прямоугольника
{
protected:
void draw(QPainter *Painter);//метод рисования квадрата
public:
MyRect(int x,int y,int halflen):Figura(x,y,halflen){}//конструктор размера и позиции
};


#endif // FIGURA_H
