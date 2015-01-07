#include "graphicfield.h"
using namespace std;
GraphicField::GraphicField()
{
    mix=-1;
    miy=-1;
    max=1;
    may=1;
    vector<Cell*> input;
    input.push_back(new Cell(-1,-1,0,false));
    input.push_back(new Cell(0,-1,0,false));
    input.push_back(new Cell(+1,-1,0,false));
    fild.push_back(input);
    vector<Cell*> input1;
    input1.push_back(new Cell(-1,0,0,false));
    input1.push_back(new Cell(0, 0,0,false));
    input1.push_back(new Cell(+1,0,0,false));
    fild.push_back(input1);
    vector<Cell*> input2;
    input2.push_back(new Cell(-1,1,0,false));
    input2.push_back(new Cell(0,1,0,false));
    input2.push_back(new Cell(+1,1,0,false));
    fild.push_back(input2);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            this->addItem(fild[i][j]);
}

void GraphicField::add_right_colmn()
{
    max++;
    for(int i=0;i<fild.size();i++){
        Cell *t=new Cell(max,miy+i,0,false);
        fild[i].push_back(t);
        this->addItem(t);
    }
}
void GraphicField::add_bottom_row()
{
    may++;
    vector<Cell*> add;
    for(int i=mix;i<=max;i++)
    {
        Cell *t=new Cell(i,may,0,false);
        add.push_back(t);
        this->addItem(t);
    }
    fild.push_back(add);
}
void GraphicField::add_top_row()
{
    miy--;
    vector<Cell*> add;
    for(int i=mix;i<=max;i++)
    {
        Cell *t=new Cell(i,miy,0,false);
        add.push_back(t);
        this->addItem(t);
    }
    fild.insert(fild.begin(),add);
}
void GraphicField::add_left_colmn()
{
    mix--;
    /*for(int i=0;i<fild.size();i++)
        fild[i].insert(fild[i].begin(),0);*/

    for(int i=0;i<fild.size();i++){
        Cell *t=new Cell(mix,miy+i,0,false);
        fild[i].insert(fild[i].begin(),t);
        this->addItem(t);
    }
}
void GraphicField::set(int x, int y, int type){
    int rx=x-mix;
    int ry=y-miy;
    fild[ry][rx]->type=type;
}

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
void GraphicField::set_Matrix(Matrix *world)
{
    this->clear();
    this->wnd=new WindoToMatrix();
    this->wnd->world=world;
    this->addItem(wnd);
}
