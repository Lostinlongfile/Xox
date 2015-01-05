#ifndef FORCE_TEST_H
#define FORCE_TEST_H

#include <QMainWindow>

#include "Xox_console/alex_palyer.h"
#include "Xox_console/random_palyer.h"
#include "Xox_console/dima_palyer.h"
#include "Xox_console/base_player.h"
#include <vector>
#include "threadfighter.h"
namespace Ui {
class force_test;
}

class force_test : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit force_test(QWidget *parent = 0);
    ~force_test();
    std::vector<base_player*> candidats;
    ThreadFighter *tf;
    int p1_w,p2_w,all;
private slots:
    void on_pushButton_clicked();
    void P1_win();
    void P2_win();
    void upd();
private:
    Ui::force_test *ui;
};

#endif // FORCE_TEST_H
