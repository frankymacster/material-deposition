#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    float upperRectWidth = ui->lineEdit->text().toFloat();
    float upperRectLength = ui->lineEdit_2->text().toFloat();
    float lowerRectWidth = ui->lineEdit_3->text().toFloat();
    float lowerRectLength = ui->lineEdit_4->text().toFloat();
    float overallPartHeight = ui->lineEdit_5->text().toFloat();
    float stepUpHeight = ui->lineEdit_6->text().toFloat();
    float radiusOfMaterial = ui->lineEdit_7->text().toFloat();
    QString pathDirection = ui->comboBox->itemText(ui->comboBox->currentIndex());

    qDebug() << upperRectWidth;
    qDebug() << upperRectLength;
    qDebug() << lowerRectWidth;
    qDebug() << lowerRectLength;
    qDebug() << overallPartHeight;
    qDebug() << stepUpHeight;
    qDebug() << radiusOfMaterial;
    qDebug() << pathDirection;
}
