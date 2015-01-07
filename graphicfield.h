#ifndef GRAPHICFIELD_H
#define GRAPHICFIELD_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <vector>
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

class Cell:public QGraphicsItem
{
public:
    int x;
    int y;
    int type;
    bool hi;
    int size;
    Cell(int _x,int _y,int _type,bool _hi):
        x(_x),y(_y),type(_type),hi(_hi),size(25)
    {

    }
    QRectF boundingRect() const
    {
             return QRectF(0,0,25, 25);
    }

     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
     {

    }

};

class GraphicField : public QGraphicsScene
{
public:
    int mix,miy,max,may;
    std::vector<std::vector<Cell*> > fild;
    GraphicField();
    void add_right_colmn();
    void add_bottom_row();
    void add_top_row();
    void add_left_colmn();
    void set(int x,int y,int type);
    void refresh_fild(InfiniteFild *inf);
    WindoToMatrix *wnd;
    void set_Matrix(Matrix *world);
};

#endif // GRAPHICFIELD_H
