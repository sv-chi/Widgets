#include "win.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//создаем объект приложения
    Win w;//созданем объект управления окном
    w.show();//визуализируем окно
    return a.exec();// запуск цикла обработки приложения
}
