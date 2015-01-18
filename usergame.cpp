#include "usergame.h"
#include "ui_usergame.h"

UserGame::UserGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserGame)
{
    ui->setupUi(this);
    candidats.push_back(new alex_palyer());
    candidats.push_back(new dima_palyer());
    candidats.push_back(new random_palyer());
    for(int i=0;i<candidats.size();i++){
        ui->comboBox_2->addItem(QString(candidats[i]->get_name()));
    }
    ui->comboBox->addItem(QString::fromUtf8("Крестик"));
    ui->comboBox->addItem(QString::fromUtf8("Нолик"));
    fild=new GraphicField(true);
    ui->graphicsView->setScene(fild);
    ui->dockWidget_3->setVisible(false);
   // connect(ui->graphicsView,SIGNAL(),
}

UserGame::~UserGame()
{
    delete ui;
}

void UserGame::on_pushButton_clicked()
{
    ma=new Matrix();
    fild->set_Matrix(ma);
    if(ui->comboBox->currentIndex()==1){
        ma->set_X(candidats[ui->comboBox_2->currentIndex()]);
        ma->do_step_1();
        fild->pl_is_X=false;
    }else
    {
        ma->set_O(candidats[ui->comboBox_2->currentIndex()]);
        fild->pl_is_X=true;
        ma->zeon->set(0,0,2);
        ma->do_step_2();
    }
    ui->graphicsView->viewport()->repaint();
}
void UserGame::mousePressEvent(QMouseEvent *e)
{

    QPoint remapped = ui->graphicsView->mapFromParent( e->pos() );
    if ( ui->graphicsView->rect().contains( remapped ) )
    {
         QPointF mousePoint = ui->graphicsView->mapToScene( remapped );
         fild->mousePress(mousePoint);
         ui->textBrowser_4->setText(QString::fromUtf8((fild->wnd->world->Ostr.str()+fild->wnd->world->Xstr.str()).c_str()));
    }

}

void UserGame::on_checkBox_clicked(bool checked)
{
    ui->dockWidget_3->setVisible(checked);
}
