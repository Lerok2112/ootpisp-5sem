#ifndef QPAINTWIDGET_H
#define QPAINTWIDGET_H

#include <QWidget>
#include <QTimer>
#include <cmath>

class QPaintWidget : public QWidget
{
    Q_OBJECT

    int offset;
    int offset2;
    double S;
    QTimer *paintTimer;
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void updatePixmap();
public:
    QPaintWidget(QWidget *parent = 0);
    ~QPaintWidget();
};

#endif // QPAINTWIDGET_H
