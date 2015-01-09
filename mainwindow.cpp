#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    //Автоматический тест
    FT=new force_test();
    FT->showNormal();
}

void MainWindow::on_pushButton_2_clicked()
{
    //Пошаговаaя игра
    SF=new Step_fighter();
    SF->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    //Игра с человеком
    UG=new UserGame();
    UG->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    //Воспроизведение
    VP=new vidoplayer();
    VP->show();
}
