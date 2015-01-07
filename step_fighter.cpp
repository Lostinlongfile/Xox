#include "step_fighter.h"
#include "ui_step_fighter.h"
#include "graphicfield.h"
#include <QMessageBox>
Step_fighter::Step_fighter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Step_fighter)
{
    ui->setupUi(this);
    candidats.push_back(new alex_palyer());
    candidats.push_back(new dima_palyer());
    candidats.push_back(new random_palyer());
    candidats_1.push_back(new alex_palyer());
    candidats_1.push_back(new dima_palyer());
    candidats_1.push_back(new random_palyer());
    for(int i=0;i<candidats.size();i++){
        ui->comboBox->addItem(QString(candidats[i]->get_name()));
        ui->comboBox_2->addItem(QString(candidats_1[i]->get_name()));
    }
    ma=NULL;

    fild=new GraphicField(false);
    ui->graphicsView->setScene(fild);
}

Step_fighter::~Step_fighter()
{
    delete ui;
}

void Step_fighter::on_pushButton_2_clicked()
{
    ui->label->setText(QString::fromUtf8("Идёт игра. Нажмите \"следующий ход\""));
    if(ma!=NULL){
        st=(st+1)%2;
        if(st==1)
        {
            ma->do_step_1();
            if(ma->win()){
                QMessageBox *t=new QMessageBox();
                t->setText(QString::fromUtf8("Игрок (X) ")+ QString(ma->get_X()->get_name())+QString::fromUtf8(" победил!!!!!!"));
                ui->label->setText(QString::fromUtf8("Игрок (X) ")+ QString(ma->get_X()->get_name())+QString::fromUtf8(" победил!!!!!!"));

                t->show();
            }
        }
        else
        {
            ma->do_step_2();
            if(ma->win()){

                QMessageBox *t=new QMessageBox();
                t->setText(QString::fromUtf8("Игрок (O) ")+ QString(ma->get_O()->get_name())+QString::fromUtf8(" победил!!!!!!"));
                ui->label->setText(QString::fromUtf8("Игрок (O) ")+ QString(ma->get_O()->get_name())+QString::fromUtf8(" победил!!!!!!"));

                t->show();
            }
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

void Step_fighter::on_pushButton_clicked()
{
    fild->clear();
    ui->graphicsView->viewport()->repaint();
    ma=new Matrix();
    ma->set_X(candidats[ui->comboBox->currentIndex()]);
    ma->set_O(candidats_1[ui->comboBox_2->currentIndex()]);
    st=0;
    fild->set_Matrix(ma);
    //ui->gm_lbl;
    ui->label->setText(QString::fromUtf8("Начата новая игра. Нажмите \"следующий ход\""));

}

void Step_fighter::on_gm_lbl_linkActivated(const QString &link)
{

}
