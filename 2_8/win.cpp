#include "win.h"

Win::Win(QWidget *parent):QWidget(parent)
{ // создаём объекты для интерфейса
    setWindowTitle("Счетчик");
this->setWindowTitle("Счетчик");//устанавливаем заголовок окна
label1 = new QLabel("Cчет по 1",this);//прибавляем по 1
label2 = new QLabel("Cчет по 5",this);//прибавляем по 5
//создаем поля редактирования
edit1 = new Counter("0",this);
edit2 = new Counter("0",this);
//создаем кнопки
calcbutton=new QPushButton("+1",this);
exitbutton=new QPushButton("Выход",this);
//создаем разметку и добавляем туда метки
QHBoxLayout *layout1 = new QHBoxLayout();
layout1->addWidget(label1);
layout1->addWidget(label2);
// добавляем элементы в BoxLayout
QHBoxLayout *layout2 = new QHBoxLayout();
layout2->addWidget(edit1);
layout2->addWidget(edit2);

QHBoxLayout *layout3 = new QHBoxLayout();
layout3->addWidget(calcbutton);
layout3->addWidget(exitbutton);

QVBoxLayout *layout4 = new QVBoxLayout(this);
layout4->addLayout(layout1);
layout4->addLayout(layout2);
layout4->addLayout(layout3);

// связь сигнала нажатия кнопки и слота закрытия окна
connect(calcbutton,SIGNAL(clicked(bool)),edit1,SLOT(add_one()));
connect(edit1,SIGNAL(tick_signal()),edit2,SLOT(add_one()));
connect(exitbutton,SIGNAL(clicked(bool)),this,SLOT(close()));
}
