#include "force_test.h"
#include "ui_force_test.h"
force_test::force_test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::force_test)
{
    ui->setupUi(this);
    candidats.push_back(new alex_palyer());
    candidats.push_back(new dima_palyer());
    candidats.push_back(new random_palyer());
    candidats_1.push_back(new alex_palyer());
    candidats_1.push_back(new dima_palyer());
    candidats_1.push_back(new random_palyer());
    tf=new ThreadFighter();
    for(int i=0;i<candidats.size();i++){
        ui->comboBox->addItem(QString(candidats[i]->get_name()));
        ui->comboBox_2->addItem(QString(candidats_1[i]->get_name()));
    }
    connect(tf,SIGNAL(P1_win()),this,SLOT(P1_win()));
    connect(tf,SIGNAL(P2_win()),this,SLOT(P2_win()));
}

force_test::~force_test()
{
    delete ui;
}

void force_test::on_pushButton_clicked()
{
    p1_w=0;
    p2_w=0;
    all=ui->lineEdit->text().toInt();
    ui->progressBar->setMaximum(2*all);
    ui->progressBar->setValue(0);
    tf->init(candidats[ui->comboBox->currentIndex()],candidats_1[ui->comboBox_2->currentIndex()],all);
    tf->start();
}
void force_test::P1_win()
{
    p1_w++;
    upd();
}
void force_test::P2_win()
{
    p2_w++;
    upd();
}

void force_test::upd()
{
    ui->progressBar->setValue(p1_w+p2_w);
    ui->p1_num->setText(QString::number(p1_w));
    ui->p2_num->setText(QString::number(p2_w));

}
