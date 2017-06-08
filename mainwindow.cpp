#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QDebug>
#include <QFile>
#include <QTextStream>

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

    // should do check for 4 decimal spaces
    if (static_cast<int>(overallPartHeight) % static_cast<int>(stepUpHeight) != 0) {
      qDebug() << "step up height must divide overall part height";
      return;
    }

    // number of steps
    quint8 steps = static_cast<int>(overallPartHeight) / static_cast<int>(stepUpHeight);

    // number of cylinders per step
    quint8 cylindersNum;

    // width-wise line
    float a1;
    float b1;
    float currentWidth;
    if (lowerRectWidth < upperRectWidth) {
        a1 = overallPartHeight / (upperRectWidth - lowerRectWidth);
        b1 = 0;
    } else if (lowerRectWidth > upperRectWidth) {
        a1 = -overallPartHeight / (lowerRectWidth - upperRectWidth);
        b1 = overallPartHeight;
    } else if (upperRectWidth == lowerRectWidth) {
        currentWidth = lowerRectWidth;
    }

    // length-wise line
    float a2;
    float b2;
    float currentLength;
    if (lowerRectLength < upperRectLength) {
        a2 = overallPartHeight / (upperRectLength - lowerRectLength);
        b2 = 0;
    } else if (lowerRectLength > upperRectLength) {
        a2 = -overallPartHeight / (lowerRectLength - upperRectLength);
        b2 = overallPartHeight;
    } else if (upperRectLength == lowerRectLength) {
        currentLength = lowerRectLength;
    }

    // y = ax + b
    float x1;
    float x2;
    float y;
    int i;
    for (i = 0; i < steps; i++) {
        qDebug() << "step";
        if (upperRectWidth > lowerRectWidth) {
            y = i * stepUpHeight;
        } else if (upperRectWidth < lowerRectWidth) {
            y = (steps - i) * stepUpHeight;
        }
        qDebug() << y;
        if (upperRectWidth != lowerRectWidth) {
            x1 = (y - b1) / a1;
            currentWidth = fmin(lowerRectWidth, upperRectWidth) + x1;
        }
        if (upperRectLength != lowerRectLength) {
            x2 = (y - b2) / a2;
            currentLength = fmin(lowerRectLength, upperRectLength) + x2;
        }
        qDebug() << currentWidth << currentLength;
    }
}
