#include "Win.h"
#include <QApplication>

int main(int argc, char *argv[])
{
QApplication app(argc, argv);//создаем объект приложения
Win win(0);//сзданем объект управления окном
win.show();//визуализация окна
return app.exec();//запуск цикла обработки приложения
}

