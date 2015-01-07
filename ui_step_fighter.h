/********************************************************************************
** Form generated from reading UI file 'step_fighter.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEP_FIGHTER_H
#define UI_STEP_FIGHTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Step_fighter
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QLabel *labe;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Step_fighter)
    {
        if (Step_fighter->objectName().isEmpty())
            Step_fighter->setObjectName(QString::fromUtf8("Step_fighter"));
        Step_fighter->resize(800, 600);
        centralwidget = new QWidget(Step_fighter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        sizePolicy.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy);
        comboBox_2->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        labe = new QLabel(centralwidget);
        labe->setObjectName(QString::fromUtf8("labe"));

        gridLayout->addWidget(labe, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 4, 0, 1, 2);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 1, 1, 1);

        Step_fighter->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Step_fighter);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        Step_fighter->setMenuBar(menubar);
        statusbar = new QStatusBar(Step_fighter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Step_fighter->setStatusBar(statusbar);

        retranslateUi(Step_fighter);

        QMetaObject::connectSlotsByName(Step_fighter);
    } // setupUi

    void retranslateUi(QMainWindow *Step_fighter)
    {
        Step_fighter->setWindowTitle(QApplication::translate("Step_fighter", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Step_fighter", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\202\320\265\321\201\321\202", 0, QApplication::UnicodeUTF8));
        labe->setText(QApplication::translate("Step_fighter", "\320\230\320\263\321\200\320\276\320\2721 (X)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Step_fighter", "\320\230\320\263\321\200\320\276\320\272 2 (O)", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Step_fighter", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271 \321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Step_fighter: public Ui_Step_fighter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEP_FIGHTER_H
