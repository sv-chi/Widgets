#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
QApplication appl(argc, argv);//создаем объект приложения
Window win;//создаем объект упраления окном
win.show();//визуализируем окна
return appl.exec();//запускаем цикл обработки приложения
}
