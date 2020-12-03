#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmath.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //выравниваем таблицу под значения
    GenerateRandomNumbers(ui->tableWidget);  //заполняем рандомными значениями таблицу

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GenerateRandomNumbers(QTableWidget *&table)
{
    QTableWidgetItem *item;
    for (int row = 0; row < table->rowCount(); ++row) {
        for (int col = 0; col < table->columnCount(); ++col) {
            item=new QTableWidgetItem(tr("%1").arg(70*my_rand(3)));
            table->setItem(row,col,item);
        }
    }
}

void MainWindow::on_pushButton_3_clicked()  //квадрат знаечния
{
     QTableWidgetItem *item=ui->tableWidget->currentItem();
    ui->label->setText(QString( "%1" ).arg((qPow (item->text().toDouble(),2))));
}

void MainWindow::on_pushButton_4_clicked()    //куб значения
{
    QTableWidgetItem *item=ui->tableWidget->currentItem();
   ui->label->setText(QString( "%1" ).arg((qPow (item->text().toDouble(),3))));
}

void MainWindow::on_pushButton_clicked()  //координаты
{
    ui->label->setText("("+QString( "%1" ).arg(ui->tableWidget->currentRow()+1)+","+QString( "%1" ).arg(ui->tableWidget->currentColumn()+1)+")");


}

int MainWindow::get_index(){
    int index=0;
    double val;
    double val2=ui->tableWidget->currentItem()->text().toDouble();
    QTableWidgetItem *item;

    for (int t = 0; t < ui->tableWidget->rowCount(); t++){
         for (int i = 0; i < ui->tableWidget->columnCount(); i++){
        item=ui->tableWidget->item(t,i);
        val=item->text().toDouble();
        index++;
        if(val2==val) return index;
    }
}return index;}

void MainWindow::on_pushButton_2_clicked()  //порядковый номер
{
    //int a = (ui->tableWidget->currentRow()+1)*(ui->tableWidget->currentColumn()+1);
   ui->label->setText(QString( "%1" ).arg(get_index()));
}

double MainWindow::my_rand(int accuracy) {
    double a = 0;
    a = (qrand() % int (qPow(10, accuracy) + 1))/qPow(10, accuracy);
    return a; }
