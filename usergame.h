#ifndef USERGAME_H
#define USERGAME_H

#include <QMainWindow>

#include "Xox_console/alex_palyer.h"
#include "Xox_console/random_palyer.h"
#include "Xox_console/dima_palyer.h"
#include "Xox_console/base_player.h"
#include "Xox_console/matrix.h"
#include "graphicfield.h"
namespace Ui {
class UserGame;
}

class UserGame : public QMainWindow
{
    Q_OBJECT
    
public:

    std::vector<base_player*> candidats;
    explicit UserGame(QWidget *parent = 0);
    GraphicField *fild;
    ~UserGame();

    Matrix *ma;
private slots:
    void mousePressEvent(QMouseEvent *);
    void on_pushButton_clicked();


    void on_checkBox_clicked(bool checked);

private:
    Ui::UserGame *ui;
};

#endif // USERGAME_H
