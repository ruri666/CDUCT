/********************************************************************************
** Form generated from reading UI file 'qwparainput5.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWPARAINPUT5_H
#define UI_QWPARAINPUT5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWParaInput5
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *label_11;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *layoutWidget_3;
    QFormLayout *formLayout_4;
    QLabel *label_16;
    QLineEdit *lineEdit_4;
    QLabel *label_17;
    QLineEdit *lineEdit_5;
    QSpacerItem *verticalSpacer_9;
    QLabel *label_18;
    QLabel *label_19;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer_11;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget_4;
    QFormLayout *formLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_10;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_9;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLineEdit *lineEdit_13;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_5;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *QWParaInput5)
    {
        if (QWParaInput5->objectName().isEmpty())
            QWParaInput5->setObjectName(QString::fromUtf8("QWParaInput5"));
        QWParaInput5->resize(675, 360);
        horizontalLayoutWidget = new QWidget(QWParaInput5);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(410, 290, 231, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        label_11 = new QLabel(QWParaInput5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(433, 143, 40, 12));
        layoutWidget = new QWidget(QWParaInput5);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 361, 321));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        layoutWidget_3 = new QWidget(groupBox);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 20, 151, 131));
        formLayout_4 = new QFormLayout(layoutWidget_3);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QFont font;
        font.setPointSize(7);
        label_16->setFont(font);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_16);

        lineEdit_4 = new QLineEdit(layoutWidget_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEdit_4);

        label_17 = new QLabel(layoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font);

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_17);

        lineEdit_5 = new QLineEdit(layoutWidget_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, lineEdit_5);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_4->setItem(1, QFormLayout::FieldRole, verticalSpacer_9);

        label_18 = new QLabel(layoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font);

        formLayout_4->setWidget(4, QFormLayout::LabelRole, label_18);

        label_19 = new QLabel(layoutWidget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);

        formLayout_4->setWidget(6, QFormLayout::LabelRole, label_19);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_4->setItem(3, QFormLayout::FieldRole, verticalSpacer_10);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_4->setItem(5, QFormLayout::FieldRole, verticalSpacer_11);

        lineEdit_6 = new QLineEdit(layoutWidget_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        formLayout_4->setWidget(4, QFormLayout::FieldRole, lineEdit_6);

        lineEdit_7 = new QLineEdit(layoutWidget_3);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        formLayout_4->setWidget(6, QFormLayout::FieldRole, lineEdit_7);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        layoutWidget_4 = new QWidget(groupBox_3);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(20, 20, 144, 136));
        formLayout_3 = new QFormLayout(layoutWidget_4);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(layoutWidget_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(layoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_9);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(1, QFormLayout::FieldRole, verticalSpacer_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(3, QFormLayout::FieldRole, verticalSpacer_5);

        lineEdit_8 = new QLineEdit(layoutWidget_4);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEdit_8);

        lineEdit_10 = new QLineEdit(layoutWidget_4);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, lineEdit_10);

        label_14 = new QLabel(layoutWidget_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(layoutWidget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_15);

        lineEdit_11 = new QLineEdit(layoutWidget_4);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, lineEdit_11);

        lineEdit_12 = new QLineEdit(layoutWidget_4);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        formLayout_3->setWidget(6, QFormLayout::FieldRole, lineEdit_12);

        lineEdit_9 = new QLineEdit(layoutWidget_4);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lineEdit_9);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        layoutWidget_2 = new QWidget(groupBox_4);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(21, 31, 118, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        horizontalLayout->addWidget(label_10);

        lineEdit_13 = new QLineEdit(layoutWidget_2);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        horizontalLayout->addWidget(lineEdit_13);


        gridLayout->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        layoutWidget_5 = new QWidget(groupBox_2);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(20, 30, 149, 111));
        formLayout = new QFormLayout(layoutWidget_5);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(layoutWidget_5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(layoutWidget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::FieldRole, verticalSpacer_3);

        label_6 = new QLabel(layoutWidget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        lineEdit_2 = new QLineEdit(layoutWidget_5);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::FieldRole, verticalSpacer_6);

        lineEdit_3 = new QLineEdit(layoutWidget_5);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_3);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label_16->setBuddy(lineEdit);
        label_17->setBuddy(lineEdit);
        label_18->setBuddy(lineEdit);
        label_19->setBuddy(lineEdit);
        label_7->setBuddy(lineEdit);
        label_8->setBuddy(lineEdit);
        label_9->setBuddy(lineEdit);
        label_14->setBuddy(lineEdit);
        label_15->setBuddy(lineEdit);
        label->setBuddy(lineEdit);
        label_2->setBuddy(lineEdit);
        label_6->setBuddy(lineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(QWParaInput5);
        QObject::connect(pushButton_2, SIGNAL(clicked()), QWParaInput5, SLOT(accept()));
        QObject::connect(pushButton, SIGNAL(clicked()), QWParaInput5, SLOT(reject()));

        QMetaObject::connectSlotsByName(QWParaInput5);
    } // setupUi

    void retranslateUi(QDialog *QWParaInput5)
    {
        QWParaInput5->setWindowTitle(QCoreApplication::translate("QWParaInput5", "\346\232\202\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QWParaInput5", "\347\241\256\345\256\232", nullptr));
        pushButton->setText(QCoreApplication::translate("QWParaInput5", "\345\217\226\346\266\210", nullptr));
        label_11->setText(QCoreApplication::translate("QWParaInput5", "TextLabel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QWParaInput5", "\345\207\240\344\275\225\345\217\202\346\225\260", nullptr));
        label_16->setText(QCoreApplication::translate("QWParaInput5", "\345\215\212\345\276\204R(m)", nullptr));
        label_17->setText(QCoreApplication::translate("QWParaInput5", "\351\242\204\350\243\202\347\272\271\350\247\222\345\272\246\316\270", nullptr));
        label_18->setText(QCoreApplication::translate("QWParaInput5", "\351\242\204\350\243\202\347\272\271\351\225\277\345\272\246a(m)", nullptr));
        label_19->setText(QCoreApplication::translate("QWParaInput5", "\350\257\225\344\273\266\345\216\232\345\272\246t(m)", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("QWParaInput5", "\350\256\241\347\256\227\345\217\202\346\225\260", nullptr));
        label_7->setText(QCoreApplication::translate("QWParaInput5", "\346\250\241\345\236\213\346\227\266\351\225\277T(s)", nullptr));
        label_8->setText(QCoreApplication::translate("QWParaInput5", "\346\227\266\351\227\264\346\255\245\351\225\277Dt(s)", nullptr));
        label_9->setText(QCoreApplication::translate("QWParaInput5", "\351\235\236\345\261\200\351\203\250\345\215\212\345\276\204d(m)", nullptr));
        label_14->setText(QCoreApplication::translate("QWParaInput5", "x\346\226\271\345\220\221\347\211\251\350\264\250\347\202\271\346\225\260\347\233\256", nullptr));
        label_15->setText(QCoreApplication::translate("QWParaInput5", "y\346\226\271\345\220\221\347\211\251\350\264\250\347\202\271\346\225\260\347\233\256", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("QWParaInput5", "\350\276\271\347\225\214\346\235\241\344\273\266", nullptr));
        label_10->setText(QCoreApplication::translate("QWParaInput5", "Uy(m)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QWParaInput5", "\347\211\251\347\220\206\345\217\202\346\225\260", nullptr));
        label->setText(QCoreApplication::translate("QWParaInput5", "\345\274\271\346\200\247\346\250\241\345\236\213\351\207\217E(Pa)", nullptr));
        label_2->setText(QCoreApplication::translate("QWParaInput5", "\346\263\212\346\235\276\346\257\224", nullptr));
        label_6->setText(QCoreApplication::translate("QWParaInput5", "\345\257\206\345\272\246(Kg/m3)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWParaInput5: public Ui_QWParaInput5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWPARAINPUT5_H
