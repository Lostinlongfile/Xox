#ifndef GRAPHICFIELD_H
#define GRAPHICFIELD_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <vector>
#include <QMouseEvent>
#include "Xox_console/infinitefild.h"
#include "Xox_console/matrix.h"
class WindoToMatrix:public QGraphicsItem
{
public:
    Matrix *world;
    int size;
    WindoToMatrix():size(25),world(NULL){}
    void ch()
    {
        //this->;
    }

    QRectF boundingRect() const
    {

        return QRectF(world->zeon->get_mix()*size,world->zeon->get_miy()*size,(world->zeon->get_max()-world->zeon->get_mix())*25, (world->zeon->get_may()-world->zeon->get_miy())*25);

    }

     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
     {
         {
             painter->setPen(QPen(Qt::red));
            int x=0;
            int y=0;
            painter->drawRect(x*size+3,y*size+3,size-6, size-6);
            painter->setPen(QPen(Qt::black));
         }
         if(world!=NULL)
         {

             for(int i=world->zeon->get_miy();i<=world->zeon->get_may();i++){
                 for(int j=world->zeon->get_mix();j<=world->zeon->get_max();j++)
                 {
                     int type=world->zeon->get(j,i);
                     int x=j;
                     int y=i;
                     painter->drawRect(x*size,y*size,size, size);
                     if(type==2){
                         painter->drawLine((x)*size+2,(y)*size+2,(x+1)*size-2,(y+1)*size-2);
                         painter->drawLine((x)*size+2,(y+1)*size-2,(x+1)*size-2,(y)*size+2);
                     }
                     else if(type==1){
                         painter->drawEllipse(x*size+2,y*size+2,size-4, size-4);
                     }

                 }
             }
         }
     }
};

class GraphicField : public QGraphicsScene
{
public:
    bool first;
    bool inter_act,pl_is_X,free_fild;
    GraphicField(bool inter);
    void refresh_fild(InfiniteFild *inf);
    WindoToMatrix *wnd;
    void set_Matrix(Matrix *world);
    void mousePress(QPointF  e,bool left=true);
};

#endif // GRAPHICFIELD_H
