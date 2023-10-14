/********************************************************************************
** Form generated from reading UI file 'qwcalsoftware.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWCALSOFTWARE_H
#define UI_QWCALSOFTWARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWCalSoftware
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QGraphicsView *graphicsView;
    QSlider *horizontalSlider;
    QGraphicsView *graphicsView_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QWCalSoftware)
    {
        if (QWCalSoftware->objectName().isEmpty())
            QWCalSoftware->setObjectName(QString::fromUtf8("QWCalSoftware"));
        QWCalSoftware->resize(530, 300);
        action = new QAction(QWCalSoftware);
        action->setObjectName(QString::fromUtf8("action"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/imgs/+.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        action_2 = new QAction(QWCalSoftware);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/imgs/arrow2.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon1);
        action_3 = new QAction(QWCalSoftware);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/imgs/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_3->setIcon(icon2);
        action_4 = new QAction(QWCalSoftware);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imgs/imgs/breack.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_4->setIcon(icon3);
        action_5 = new QAction(QWCalSoftware);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imgs/imgs/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_5->setIcon(icon4);
        centralwidget = new QWidget(QWCalSoftware);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout->addWidget(radioButton, 3, 1, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 4, 0, 1, 1);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 3, 0, 1, 1);

        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));

        gridLayout->addWidget(graphicsView_2, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);

        QWCalSoftware->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QWCalSoftware);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 530, 17));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        menu_6 = new QMenu(menubar);
        menu_6->setObjectName(QString::fromUtf8("menu_6"));
        QWCalSoftware->setMenuBar(menubar);
        toolBar = new QToolBar(QWCalSoftware);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QWCalSoftware->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(QWCalSoftware);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QWCalSoftware->setStatusBar(statusBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_6->menuAction());
        toolBar->addAction(action);
        toolBar->addAction(action_2);
        toolBar->addAction(action_3);
        toolBar->addAction(action_4);
        toolBar->addAction(action_5);
        toolBar->addSeparator();

        retranslateUi(QWCalSoftware);

        QMetaObject::connectSlotsByName(QWCalSoftware);
    } // setupUi

    void retranslateUi(QMainWindow *QWCalSoftware)
    {
        QWCalSoftware->setWindowTitle(QCoreApplication::translate("QWCalSoftware", "\345\233\272\344\275\223\350\277\236\347\273\255-\351\235\236\350\277\236\347\273\255\345\217\230\345\275\242\347\273\237\344\270\200\346\250\241\346\213\237\350\275\257\344\273\266", nullptr));
        action->setText(QCoreApplication::translate("QWCalSoftware", "\346\211\223\345\274\200", nullptr));
        action_2->setText(QCoreApplication::translate("QWCalSoftware", "\344\270\213\344\270\200\346\255\245", nullptr));
        action_3->setText(QCoreApplication::translate("QWCalSoftware", "\350\277\220\350\241\214", nullptr));
        action_4->setText(QCoreApplication::translate("QWCalSoftware", "\346\232\202\345\201\234", nullptr));
        action_5->setText(QCoreApplication::translate("QWCalSoftware", "\345\270\256\345\212\251", nullptr));
        radioButton->setText(QCoreApplication::translate("QWCalSoftware", "\346\230\257\345\220\246\346\230\276\347\244\272y\346\226\271\345\220\221\344\275\215\347\247\273\357\274\210\351\273\230\350\256\244\344\270\272x\346\226\271\345\220\221)", nullptr));
        pushButton->setText(QCoreApplication::translate("QWCalSoftware", "\345\273\272\346\250\241", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QWCalSoftware", "\350\256\241\347\256\227", nullptr));
        pushButton_3->setText(QCoreApplication::translate("QWCalSoftware", "\345\220\216\345\244\204\347\220\206", nullptr));
        menu->setTitle(QCoreApplication::translate("QWCalSoftware", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("QWCalSoftware", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("QWCalSoftware", "\345\273\272\346\250\241", nullptr));
        menu_4->setTitle(QCoreApplication::translate("QWCalSoftware", "\350\277\220\350\241\214", nullptr));
        menu_5->setTitle(QCoreApplication::translate("QWCalSoftware", "\345\267\245\345\205\267", nullptr));
        menu_6->setTitle(QCoreApplication::translate("QWCalSoftware", "\345\270\256\345\212\251", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("QWCalSoftware", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWCalSoftware: public Ui_QWCalSoftware {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWCALSOFTWARE_H
