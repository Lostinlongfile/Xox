#ifndef STEP_FIGHTER_H
#define STEP_FIGHTER_H

#include <QMainWindow>

namespace Ui {
class Step_fighter;
}

class Step_fighter : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Step_fighter(QWidget *parent = 0);
    ~Step_fighter();
    
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Step_fighter *ui;
};

#endif // STEP_FIGHTER_H
