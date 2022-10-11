#ifndef win_h
#define win_h
#include <QtGui>
#include <QMainWindow>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class Counter:public QLineEdit//класс счетчик
{
Q_OBJECT

public:
Counter(const QString & contents, QWidget *parent=0):
    QLineEdit(contents,parent){}//конструктор

signals:
void tick_signal();//сигнал

public slots:// добавление 1 (слот)
void add_one()
{
QString str=text();//получаем строку
int r=str.toInt();//преобразовываем в int
if (r!=0 && r%5 ==0) emit tick_signal();//вызываем сигнал
r++;//увеличиваем на 1
str.setNum(r);//обновляем содержимое строки
setText(str);//устанавливаем текст
}
};

class Win: public QWidget
{
Q_OBJECT

protected:
QLabel *label1,*label2;//метки
Counter *edit1,*edit2;//счетчики
QPushButton *calcbutton;//кнопка увеличения
QPushButton *exitbutton;//кнопка выхода

public:
Win(QWidget *parent = 0);//конструктор
};

#endif
