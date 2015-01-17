#include "vidoplayer.h"
#include "ui_vidoplayer.h"
#include "Xox_console/alex_palyer.h"
#include "Xox_console/dima_palyer.h"
#include "Xox_console/random_palyer.h"
#include <fstream>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
vidoplayer::vidoplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vidoplayer),step(0)
{
    ui->setupUi(this);
    fild=new GraphicField(false);
    ui->graphicsView->setScene(fild);

    candidats.push_back(new alex_palyer());
    candidats.push_back(new dima_palyer());
    candidats.push_back(new random_palyer());
    for(int i=0;i<candidats.size();i++){
        ui->comboBox->addItem(QString(candidats[i]->get_name()));
    }
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
    }
    while(!in.eof());
    ma=new Matrix();
    fild->set_Matrix(ma);
}

void vidoplayer::on_pushButton_3_clicked()
{
    QString qs=QFileDialog::getOpenFileName(this,"Выбирите");
    if(qs!="")
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

void vidoplayer::on_pushButton_4_clicked()
{
    std::stringstream out;
    QString m="";
    base_player *tmp=candidats[ui->comboBox->currentIndex()];
    tmp->refresh();
    tmp->set_type(2);
    point t=tmp->do_move(fild->wnd->world->zeon,out);
    m=m.sprintf("As X I will set (%i,%i)\n because:\n ",t.x,t.y)+QString::fromUtf8(out.str().c_str());
    out.str("");
    tmp->set_type(1);
    tmp->refresh();
    t=tmp->do_move(fild->wnd->world->zeon,out);
    QString m2="";
    m=m+m2.sprintf("\nAs O I will set (%i,%i) because:\n ",t.x,t.y)+QString::fromUtf8(out.str().c_str());
    QMessageBox *msb=new QMessageBox(this);
    msb->setText(m);
    msb->show();
}

void vidoplayer::on_pushButton_5_clicked()
{
    while(true)
    {
        if(step==move.size()-1)
        {
            step=move.size()-1;
            break;
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
}
