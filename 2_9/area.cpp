#include "area.h"

Area::Area(QWidget *parent):QWidget(parent)
{
setFixedSize(QSize(300,200));//указываем границы
myline=new MyLine(80,100,50);//создаем линию
myrect=new MyRect(220,100,50);//создаем прямоугольник
alpha=0;
}
//метод включения таймера
void Area::showEvent(QShowEvent *)
{
myTimer=startTimer(50); // создать таймер
}
//метод отрисовки перемещающихся фигур;
void Area::paintEvent(QPaintEvent *)
{
QPainter painter(this);
painter.setPen(Qt::red);//устанавливаем цвет
myline->move(alpha,&painter);//поворачиваем линию
myrect->move(alpha*(-0.5),&painter);//поворачиваем прямогуольник
}
//метод перерисовки Холста;
void Area::timerEvent(QTimerEvent *event)
{
if (event->timerId() == myTimer) // если наш таймер
{
alpha=alpha+0.2;
update(); // обновить внешний вид
}
else
QWidget::timerEvent(event); // иначе передать для стандартной
// обработки
}
//метод выключения таймера
void Area::hideEvent(QHideEvent *)
{
killTimer(myTimer); // уничтожить таймер
}

Area::~Area()
{
delete myline;
delete myrect;
}
