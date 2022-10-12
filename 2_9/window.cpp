#include "window.h"
#include "ui_window.h"

Window::Window()
{
setWindowTitle("Обработка событий");//устанавливаем заголовок
area = new Area( this );//создаем холст
btn = new QPushButton("Завершить", this);//создаем кнопку
QVBoxLayout *layout = new QVBoxLayout(this);//задаем вертикальную разметку
layout->addWidget(area);//добавляем в разметку холст
layout->addWidget(btn);//добавляем кнопку
connect(btn, SIGNAL(clicked(bool)),this,SLOT(close())); //создаем сигнал при нажатии на кнопку закрытия
};

