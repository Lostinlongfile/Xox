#ifndef THINKING_H
#define THINKING_H

#include <QMainWindow>
#include "graphicfield.h"
#include "Xox_console/alex_palyer.h"
#include "Xox_console/dima_palyer.h"
#include "Xox_console/random_palyer.h"
namespace Ui {
class Thinking;
}

class Thinking : public QMainWindow
{
    Q_OBJECT
    
public:
    GraphicField *fild;
    Matrix *ma;
    std::vector<base_player*> candidats;
    explicit Thinking(QWidget *parent = 0);
    ~Thinking();

private slots:
    void mousePressEvent(QMouseEvent *);

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::Thinking *ui;
};

#endif // THINKING_H
