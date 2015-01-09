#ifndef STEP_FIGHTER_H
#define STEP_FIGHTER_H

#include <QMainWindow>
#include "Xox_console/base_player.h"
#include "Xox_console/alex_palyer.h"
#include "Xox_console/random_palyer.h"
#include "Xox_console/dima_palyer.h"
#include "Xox_console/matrix.h"
#include "graphicfield.h"
namespace Ui {
class Step_fighter;
}

class Step_fighter : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Step_fighter(QWidget *parent = 0);
    ~Step_fighter();
    Matrix *ma;
    int st;
    std::vector<base_player*> candidats;
    std::vector<base_player*> candidats_1;
    GraphicField *fild;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_gm_lbl_linkActivated(const QString &link);

    void on_pushButton_3_clicked();

private:
    Ui::Step_fighter *ui;
};

#endif // STEP_FIGHTER_H
