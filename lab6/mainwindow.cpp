#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "factory.h"

/*Абстрактная фабрика — это порождающий паттерн проектирования, который решает проблему создания целых семейств связанных продуктов,
без указания конкретных классов продуктов. */
//Абстрактная фабрика задаёт интерфейс создания всех доступных типов продуктов, а каждая конкретная реализация фабрики порождает продукты одной из вариаций.

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ConcreteFactory *factory = new ConcreteFactory(); //создаём конкретную фабрику
    //пораждаем конкретные товары фабрики
    AbstractMyList *myList = factory->CreateMyList();
    AbstractMyButton *myButton = factory->CreateMyButton();
    AbstractMyInput *myInput = factory->CreateMyInput();
    AbstractMyLanguage *myLanguage = factory->CreateMyLanguage();

    QLabel *label2 = new QLabel();
    label2->setText(QString("Продукт фабрики Список"));
    ui->layout->addWidget(label2);
    ui->layout->addWidget(myList->UsefulFunctionMyList());
    ui->layout->addWidget(myButton->UsefulFunctionMyButton());
    ui->layout->addWidget(myInput->UsefulFunctionMyInput());
    QTextCodec::setCodecForLocale(myLanguage->UsefulFunctionMyLanguage());
    QLabel *label = new QLabel();
    label->setText(QString("Продукт фабрики Язык отображения"));
     ui->layout->addWidget(label);


    delete myList;
    delete myButton;
    delete myInput;
    delete myLanguage;
}

MainWindow::~MainWindow()
{
    delete ui;
}

