#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "factory.h"
#include "builder.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    AbstractMyList *myList = ConcreteFactory::GetInstance()->CreateMyList();
    AbstractMyButton *myButton = ConcreteFactory::GetInstance()->CreateMyButton();
    AbstractMyInput *myInput = ConcreteFactory::GetInstance()->CreateMyInput();
    AbstractMyLanguage *myLanguage = ConcreteFactory::GetInstance()->CreateMyLanguage();

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


    RobotBuilder* builder = new Robot_2_Builder();
    Engineer eng(builder);
    eng.Construct();

    robot = builder->GetResult();

    ui->robInfo->setText(robot->GetInformation());

    delete myList;
    delete myButton;
    delete myInput;
    delete myLanguage;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete robot;
}

