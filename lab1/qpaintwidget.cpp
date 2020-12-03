#include "qpaintwidget.h"
#include <QPainter>
#include <QPainterPath>
#include <QDebug>

QPaintWidget::QPaintWidget(QWidget *parent)
    : QWidget(parent)
{
    offset = 0; //смещение по X
    offset2=0;  //смещение по Y
    S=0;
    paintTimer = new QTimer(this);
    paintTimer->start(100);
    connect(paintTimer, SIGNAL(timeout()), this, SLOT(updatePixmap()));
}

void QPaintWidget::paintEvent(QPaintEvent *)
{
    QPainter text(this); //новый объект для рисования
    text.setFont(QFont("Bodoni", 15)); //шрифт
    text.setPen(Qt::red); //цвет кисти
    text.rotate(90.0); //поворот на 90 гр
    text.setRenderHint(QPainter::Antialiasing, true);  //сглаживание
    text.drawText(QPoint(30,0),"Лабораторная работа 8");

    QPainter sinus(this);    //рисуем синусоиду
    sinus.setPen(QPen(Qt::blue, 3));
    sinus.drawLine(25,150,500,150);
    double S=0;
    double pi = 3.1416;
    for(int i=0;i<150;i++)
        {
            QPointF p1( 40 + S * 10, 150- 100 * sin(S));
            S += pi/10;
            QPointF p2( 40 + S * 10,150- 100 * sin(S));
            sinus.setRenderHint(QPainter::Antialiasing, true);  //сглаживание
            sinus.drawLine(p1, p2);
        }

    QPainter painter(this); // Создаём новый объект рисовальщика
    painter.setRenderHint(QPainter::Antialiasing);  //сглаживаение
    painter.translate(offset, offset2); //смещаем
    painter.setPen(QPen(Qt::black,3,Qt::SolidLine)); // Настройки рисования
    painter.setBrush(QBrush(Qt::green, Qt::DiagCrossPattern));
    painter.drawEllipse(QRect(15,40,50,50));  //круг
    painter.drawRect(QRect(5,90,70,40));       //квадрат
}

void QPaintWidget::updatePixmap()
{
    double pi = 3.1416;
    offset=(S * 10);
    offset2=(80 - 100 * sin(S));
    S += pi/10;
    offset=(S * 10);
    offset2=(80 - 100 * sin(S));
    if (offset >= 400 ) {offset =0; S=0;}
    if ( offset2>=200) {offset2 =0; S=0;}
    qDebug() << offset << offset2;
    repaint();
}

QPaintWidget::~QPaintWidget()
{

}
