#include "Win.h"

Win::Win(QWidget *parent):QWidget(parent)
{
setWindowTitle("Возведение в квадрат");// задаем заголовок окна

frame = new QFrame(this);//выделяем память для рамки
frame->setFrameShadow(QFrame::Raised);//устанавдиваем тень
frame->setFrameShape(QFrame::Panel);//вид

inputLabel = new QLabel("Введите число:",this);//текст для поля ввода числа
inputEdit = new QLineEdit("",this);// вводим число
StrValidator *v=new StrValidator(inputEdit);//валидатор
inputEdit->setValidator(v);//устанавливаем валидатор на ввод
outputLabel = new QLabel("Результат:",this);//текст к полю для вывода результата
outputEdit = new QLineEdit("",this);//выводим результат
//кнопки
nextButton = new QPushButton("Следующее",this);// кнопка следующего вычисления
exitButton = new QPushButton("Выход",this);//кнопка выхода

// компоновка приложения выполняется согласно рисунку 2
QVBoxLayout *vLayout1 = new QVBoxLayout(frame);//создаём объект
//добавляем поля в QVBoxLayout
vLayout1->addWidget(inputLabel);
vLayout1->addWidget(inputEdit);
vLayout1->addWidget(outputLabel);
vLayout1->addWidget(outputEdit);
vLayout1->addStretch();

QVBoxLayout *vLayout2 = new QVBoxLayout();//создаём объект
//добавляем поля в QVBoxLayout
vLayout2->addWidget(nextButton);
vLayout2->addWidget(exitButton);
vLayout2->addStretch();

QHBoxLayout *hLayout = new QHBoxLayout(this);//создаём объект
//добавляем поля в QVBoxLayout
hLayout->addWidget(frame);
hLayout->addLayout(vLayout2);

begin();
//сигналы
connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(close()));//когда нажата кнопка вызода закрываем окно
connect(nextButton,SIGNAL(clicked(bool)),this,SLOT(begin()));//когда нажата кнопка возведения в квадрат
connect(inputEdit,SIGNAL(returnPressed()),this,SLOT(calc()));//когда изменен инпут
}
void Win::begin()
{
inputEdit->clear();//очищаем ввод
nextButton->setEnabled(false);// отключаем кнопку
nextButton->setDefault(false);//возвращает значение по умолчанию
inputEdit->setEnabled(true);//активируем поле, включаем ввод
outputLabel->setVisible(false);//скрываем вывод
outputEdit->setVisible(false);//виджет невидим
outputEdit->setEnabled(false);//отлючаем ввод в данное поле
inputEdit->setFocus();//ставим фокус
}
void Win::calc()
{
bool Ok=true;
float r,a;
QString str=inputEdit->text();//получаем строку
a=str.toDouble(&Ok);// преобразуем в double
if (Ok)
{
r=a*a;//возводим в квадрат
str.setNum(r);//устанавливаем в строку
outputEdit->setText(str);//вывод результата
inputEdit->setEnabled(false);//отлючаем ввод в данное поле
outputLabel->setVisible(true);//включаем кнопки и вывод
outputEdit->setVisible(true);//виджет видим
nextButton->setDefault(true);//
nextButton->setEnabled(true);//активируем кнопку
nextButton->setFocus();//ставим фокус
}
else if (!str.isEmpty())
{
       //вывод сообщения об ошибке
QMessageBox msgBox(QMessageBox::Information, "Возведение в квадрат.", "Введено неверное значение.", QMessageBox::Ok);
msgBox.exec();
}
}
