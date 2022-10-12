#ifndef window_h
#define window_h
#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QtGui>
#include <QVBoxLayout>
#include "area.h"
class Window : public QWidget
{
protected:
Area *area; // область отображения рисунка
QPushButton *btn;//объект кнопки завершения
public:
Window();//конструктор
};
#endif // WINDOW_H
