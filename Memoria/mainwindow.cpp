#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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

void MainWindow::on_pushButton_released()
{
    QFile file("//home//juno//Desktop//hello.txt");

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info", file.errorString());

    }

    QTextStream in(&file);

    ui -> textBrowser ->setText(in.readAll());
}
