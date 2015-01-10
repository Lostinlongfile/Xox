#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "force_test.h"
#include "step_fighter.h"
#include "usergame.h"
#include "vidoplayer.h"
#include "thinking.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    force_test *FT;
    Step_fighter *SF;
    vidoplayer *VP;
    UserGame *UG;
    Thinking *TH;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
