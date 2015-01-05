#include "step_fighter.h"
#include "ui_step_fighter.h"
#include "graphicfield.h"
Step_fighter::Step_fighter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Step_fighter)
{
    ui->setupUi(this);
}

Step_fighter::~Step_fighter()
{
    delete ui;
}

void Step_fighter::on_pushButton_2_clicked()
{
    GraphicField *fild=new GraphicField();
    ui->graphicsView->setScene(fild);
}
