#ifndef GRAPHICFIELD_H
#define GRAPHICFIELD_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

class Cell:public QGraphicsItem
{
public:
    int x;
    int y;
    int type;
    bool hi;
    Cell(int _x,int _y,int _type,bool _hi):
        x(_x),y(_y),type(_type),hi(_hi)
    {

    }
    QRectF boundingRect() const
    {
             return QRectF(0,0,25, 25);
    }

     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
     {
             painter->drawRoundedRect(0,0,25, 25, 5, 5);
     }


};

class GraphicField : public QGraphicsScene
{
public:
    GraphicField();
};

#endif // GRAPHICFIELD_H
