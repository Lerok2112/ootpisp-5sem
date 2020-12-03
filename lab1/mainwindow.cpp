#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);

    // Создаем виджет
    wgt = new QPaintWidget(this);

    // И кладём его в лайаут
    ui.verticalLayout->addWidget(wgt);
}

MainWindow::~MainWindow()
{
}
