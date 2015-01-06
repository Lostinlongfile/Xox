#include "step_fighter.h"
#include "ui_step_fighter.h"
#include "graphicfield.h"
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

    fild=new GraphicField();
    ui->graphicsView->setScene(fild);
}

Step_fighter::~Step_fighter()
{
    delete ui;
}

void Step_fighter::on_pushButton_2_clicked()
{
    if(ma!=NULL){
        st=(st+1)%2;
        if(st==1)
        {
            ma->do_step_1();
        }
        else
        {
            ma->do_step_2();
        }

        fild->refresh_fild(ma->zeon);
        QList<QRectF> st;
        st.append((fild->sceneRect()));
        ui->graphicsView->updateScene(st);
    }
}

void Step_fighter::on_pushButton_clicked()
{
    ma=new Matrix();
    ma->set_X(candidats[ui->comboBox->currentIndex()]);
    ma->set_O(candidats_1[ui->comboBox_2->currentIndex()]);
    st=0;
}
