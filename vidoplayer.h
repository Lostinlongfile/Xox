#ifndef VIDOPLAYER_H
#define VIDOPLAYER_H

#include <QMainWindow>
#include "Xox_console/infinitefild.h"
#include "Xox_console/matrix.h"
#include "graphicfield.h"
#include <vector>

namespace Ui {
class vidoplayer;
}

class vidoplayer : public QMainWindow
{
    Q_OBJECT
    
public:
    int step;
    explicit vidoplayer(QWidget *parent = 0);

    std::vector<base_player*> candidats;
    GraphicField *fild;
    std::vector<point> move;
    void play(const char *fn);
    ~vidoplayer();

    Matrix *ma;
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::vidoplayer *ui;
};

#endif // VIDOPLAYER_H
