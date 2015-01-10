#include "thinking.h"
#include "ui_thinking.h"
#include <QMessageBox>

Thinking::Thinking(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Thinking)
{
    ui->setupUi(this);
    fild=new GraphicField(false);
    fild->free_fild=true;
    ui->graphicsView->setScene(fild);

    candidats.push_back(new alex_palyer());
    candidats.push_back(new dima_palyer());
    candidats.push_back(new random_palyer());
    for(int i=0;i<candidats.size();i++){
        ui->comboBox->addItem(QString(candidats[i]->get_name()));
    }
    ma=new Matrix();
    fild->set_Matrix(ma);
}

Thinking::~Thinking()
{
    delete ui;
}
void Thinking::mousePressEvent(QMouseEvent *e)
{

    QPoint remapped = ui->graphicsView->mapFromParent( e->pos() );
    if ( ui->graphicsView->rect().contains( remapped ) )
    {
         QPointF mousePoint = ui->graphicsView->mapToScene( remapped );
         fild->mousePress(mousePoint,e->button()==Qt::LeftButton);
    }
    ui->graphicsView->viewport()->repaint();


}

void Thinking::on_pushButton_4_clicked()
{
    QString m="";
    base_player *tmp=candidats[ui->comboBox->currentIndex()];
    tmp->refresh();
    tmp->set_type(2);
    point t=tmp->do_move(fild->wnd->world->zeon);
    m=m.sprintf("As X I will set (%i,%i)\n",t.x,t.y);
   tmp->refresh();
    tmp=new alex_palyer();
    tmp->set_type(1);
    t=tmp->do_move(fild->wnd->world->zeon);
    QString m2="";
    m=m+m2.sprintf("As O I will set (%i,%i)",t.x,t.y);
    QMessageBox *msb=new QMessageBox(this);
    msb->setText(m);
    msb->show();
}

void Thinking::on_pushButton_clicked()
{
    ma=new Matrix();
    fild->set_Matrix(ma);
    ui->graphicsView->viewport()->repaint();

}
