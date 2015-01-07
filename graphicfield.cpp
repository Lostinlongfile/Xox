#include "graphicfield.h"
#include <iostream>
#include <QGraphicsView>
#include <QMessageBox>
using namespace std;
GraphicField::GraphicField(bool inter):inter_act(inter)
{
}


void GraphicField::refresh_fild(InfiniteFild *zeon){

    this->setSceneRect(wnd->boundingRect());

}

void GraphicField::mousePress(QPointF  e)
{
    QPointF pt = e;//mapToScene(e->pos());
    int x=int(pt.x())-wnd->world->zeon->get_mix()*wnd->size;
    x=(x-x%wnd->size)/wnd->size;
    x=x+wnd->world->zeon->get_mix();
    int y=int(pt.y())-wnd->world->zeon->get_miy()*wnd->size;
    y=(y-y%wnd->size)/wnd->size;
    y=y+wnd->world->zeon->get_miy();
    //std::cout<<x<<" "<<y<<" "<<e.x()<<" "<<e.y()<<" "<<int(e.x())%25<<endl;
    if(inter_act)
    {

            if(pl_is_X)
            {
                if(wnd->world->zeon->isAnyNear(x,y)){
                    wnd->world->zeon->set(x,y,2);
                    if(wnd->world->win()){
                        QMessageBox *t=new QMessageBox();
                        t->setText(QString::fromUtf8("Человек (X) ")+QString::fromUtf8(" победил!!!!!!"));
                        t->show();
                        return;
                    }
                    wnd->world->do_step_2();
                    if(wnd->world->win()){
                    QMessageBox *t=new QMessageBox();
                        t->setText(QString::fromUtf8("Игрок (O) ")+ QString(wnd->world->get_O()->get_name())+QString::fromUtf8(" победил!!!!!!"));
                        t->show();
                        return;
                    }
                }
            }
            else
            {

                if(wnd->world->zeon->isAnyNear(x,y)){
                    wnd->world->zeon->set(x,y,1);
                    if(wnd->world->win()){
                        QMessageBox *t=new QMessageBox();
                        t->setText(QString::fromUtf8("Человек (O) ")+QString::fromUtf8(" победил!!!!!!"));
                        t->show();
                        return;
                    }
                    wnd->world->do_step_1();
                    if(wnd->world->win()){
                        QMessageBox *t=new QMessageBox();
                        t->setText(QString::fromUtf8("Игрок (X) ")+ QString(wnd->world->get_X()->get_name())+QString::fromUtf8(" победил!!!!!!"));
                        t->show();
                        return;
                    }
                }
            }
        this->setSceneRect(wnd->boundingRect());
        this->views().at(0)->viewport()->repaint();
        //qApp->processEvents();
    }
}

<<<<<<< HEAD
=======
void GraphicField::refresh_fild(InfiniteFild *zeon){
  /*  while(may<zeon->get_may())
        add_bottom_row();
    while(max<zeon->get_max())
        add_right_colmn();
    while(miy>zeon->get_miy())
        add_top_row();
    while(mix>zeon->get_mix())
        add_left_colmn();
    for(int i=zeon->get_miy();i<=zeon->get_may();i++){
        for(int j=zeon->get_mix();j<=zeon->get_max();j++)
        {
            this->set(j,i,zeon->get(j,i));
        }
    }*/
    this->setSceneRect(zeon->get_mix()*25,zeon->get_miy()*25,(zeon->get_max()-zeon->get_mix())*25,(zeon->get_may()-zeon->get_miy())*25);

    this->update(wnd->boundingRect());

}
>>>>>>> parent of df44b4b... Пошаговый графический режим доделан
void GraphicField::set_Matrix(Matrix *world)
{
    this->clear();
    this->wnd=new WindoToMatrix();
    this->wnd->world=world;
    this->addItem(wnd);
    first=true;
}
