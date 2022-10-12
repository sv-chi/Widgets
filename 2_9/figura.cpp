#include <math.h>
#include "figura.h"
void Figura::move(float Alpha,QPainter *Painter)//функция для поворота фигур
{
dx=halflen*cos(Alpha);//вычисляем отступ для координат, координата вращения по оси x
dy=halflen*sin(Alpha);//координата вращения по оси y
draw(Painter);// вызываем перерисовку
}
void MyLine::draw(QPainter *Painter)
{
Painter->drawLine(x+dx,y+dy,x-dx,y-dy);//рисуем линию после вращения
}
void MyRect::draw(QPainter *Painter)//рисуем прямоугольник на холсте (его стороны после вращения)
{
Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
