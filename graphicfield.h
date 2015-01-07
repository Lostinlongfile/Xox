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

        if(world==NULL)
             return QRectF(0,0,25, 25);
        else
            return QRectF(world->zeon->get_mix()*size,world->zeon->get_miy()*size,(world->zeon->get_mix()-world->zeon->get_max())*25, (world->zeon->get_miy()-world->zeon->get_may())*25);

    }

     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
     {
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
    bool inter_act,pl_is_X;
    GraphicField(bool inter);
    void refresh_fild(InfiniteFild *inf);
    WindoToMatrix *wnd;
    void set_Matrix(Matrix *world);
    void mousePress(QPointF  e);
};

#endif // GRAPHICFIELD_H