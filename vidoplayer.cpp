#include "vidoplayer.h"
#include "ui_vidoplayer.h"
#include <fstream>
#include <iostream>
#include <QFileDialog>
vidoplayer::vidoplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vidoplayer),step(0)
{
    ui->setupUi(this);
    fild=new GraphicField(false);
    ui->graphicsView->setScene(fild);
}

vidoplayer::~vidoplayer()
{
    delete ui;
}
void vidoplayer::play(const char *fn)
{
    step=0;
    move.clear();
    std::ifstream in(fn);
    do{
        char tmp[3];
        int x,y;
        in>>tmp>>x>>y;
        move.push_back( point(x,y));
        std::cout<<"---\n";
    }
    while(!in.eof());
    ma=new Matrix();
    fild->set_Matrix(ma);
}

void vidoplayer::on_pushButton_3_clicked()
{
    QString qs=QFileDialog::getOpenFileName(this,"Выбирите");
    play(qs.toAscii().operator const char *());
}

void vidoplayer::on_pushButton_clicked()
{
    if(step==0)
    {
        step=0;
    }
    else
    {
        ma->zeon->set(move[step].x,move[step].y,0);
        step--;
        ma->zeon->set(move[step].x,move[step].y,(2-(step%2)));
    }
    ui->graphicsView->updateGeometry();
    ui->graphicsView->update();
    QList<QRectF> list;
    list.append(fild->wnd->boundingRect());
    ui->graphicsView->setSceneRect(list[0]);
    ui->graphicsView->viewport()->repaint();
    qApp->processEvents();
}

void vidoplayer::on_pushButton_2_clicked()
{
    if(step==move.size()-1)
    {
        step=move.size()-1;
    }
    else
    {
        ma->zeon->set(move[step].x,move[step].y,(2-(step%2)));
        step++;
    }
    ui->graphicsView->updateGeometry();
    ui->graphicsView->update();
    QList<QRectF> list;
    list.append(fild->wnd->boundingRect());
    ui->graphicsView->setSceneRect(list[0]);
    ui->graphicsView->viewport()->repaint();
    qApp->processEvents();
}
