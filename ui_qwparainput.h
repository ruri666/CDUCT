/********************************************************************************
** Form generated from reading UI file 'qwparainput.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWPARAINPUT_H
#define UI_QWPARAINPUT_H

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

class Ui_QWParaInput
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLineEdit *lineEdit_11;
    QGroupBox *groupBox;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLineEdit *lineEdit_5;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_12;
    QLabel *label_13;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout_3;
    QLabel *label_8;
    QLineEdit *lineEdit_8;
    QSpacerItem *verticalSpacer;
    QLabel *label_14;
    QLineEdit *lineEdit_9;
    QSpacerItem *verticalSpacer_9;
    QLabel *label_15;
    QLineEdit *lineEdit_10;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget3;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_2;
    QLabel *label_11;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *label_5;

    void setupUi(QDialog *QWParaInput)
    {
        if (QWParaInput->objectName().isEmpty())
            QWParaInput->setObjectName(QString::fromUtf8("QWParaInput"));
        QWParaInput->resize(675, 359);
        layoutWidget = new QWidget(QWParaInput);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 361, 331));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(21, 31, 118, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font;
        font.setPointSize(7);
        label_10->setFont(font);

        horizontalLayout->addWidget(label_10);

        lineEdit_11 = new QLineEdit(layoutWidget1);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        horizontalLayout->addWidget(lineEdit_11);


        gridLayout->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 30, 151, 119));
        formLayout_2 = new QFormLayout(layoutWidget2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEdit_4 = new QLineEdit(layoutWidget2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_4);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_4);

        lineEdit_5 = new QLineEdit(layoutWidget2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEdit_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(1, QFormLayout::FieldRole, verticalSpacer_2);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_12);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_13);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(3, QFormLayout::FieldRole, verticalSpacer_7);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(5, QFormLayout::FieldRole, verticalSpacer_8);

        lineEdit_6 = new QLineEdit(layoutWidget2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, lineEdit_6);

        lineEdit_7 = new QLineEdit(layoutWidget2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, lineEdit_7);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 170));
        layoutWidget_2 = new QWidget(groupBox_3);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 30, 144, 121));
        formLayout_3 = new QFormLayout(layoutWidget_2);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_8);

        lineEdit_8 = new QLineEdit(layoutWidget_2);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEdit_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(1, QFormLayout::FieldRole, verticalSpacer);

        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_14);

        lineEdit_9 = new QLineEdit(layoutWidget_2);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lineEdit_9);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(3, QFormLayout::FieldRole, verticalSpacer_9);

        label_15 = new QLabel(layoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_15);

        lineEdit_10 = new QLineEdit(layoutWidget_2);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, lineEdit_10);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 30, 149, 111));
        formLayout = new QFormLayout(layoutWidget3);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(layoutWidget3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::FieldRole, verticalSpacer_3);

        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        lineEdit_3 = new QLineEdit(layoutWidget3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_3);

        lineEdit_2 = new QLineEdit(layoutWidget3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::FieldRole, verticalSpacer_6);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        label_11 = new QLabel(QWParaInput);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(430, 140, 40, 12));
        horizontalLayoutWidget = new QWidget(QWParaInput);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(400, 280, 231, 80));
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

        label_5 = new QLabel(QWParaInput);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(580, 20, 61, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\273\277\345\256\213"));
        font1.setPointSize(8);
        label_5->setFont(font1);
#if QT_CONFIG(shortcut)
        label_10->setBuddy(lineEdit);
        label_3->setBuddy(lineEdit);
        label_4->setBuddy(lineEdit);
        label_12->setBuddy(lineEdit);
        label_13->setBuddy(lineEdit);
        label_8->setBuddy(lineEdit);
        label_14->setBuddy(lineEdit);
        label_15->setBuddy(lineEdit);
        label->setBuddy(lineEdit);
        label_6->setBuddy(lineEdit);
        label_2->setBuddy(lineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(QWParaInput);
        QObject::connect(pushButton_2, SIGNAL(clicked()), QWParaInput, SLOT(accept()));
        QObject::connect(pushButton, SIGNAL(clicked()), QWParaInput, SLOT(reject()));

        QMetaObject::connectSlotsByName(QWParaInput);
    } // setupUi

    void retranslateUi(QDialog *QWParaInput)
    {
        QWParaInput->setWindowTitle(QCoreApplication::translate("QWParaInput", "\346\250\241\345\236\2131\357\274\232\345\267\264\350\245\277\345\212\210\350\243\202\350\257\225\351\252\214", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("QWParaInput", "\350\276\271\347\225\214\346\235\241\344\273\266", nullptr));
        label_10->setText(QCoreApplication::translate("QWParaInput", "Vy(m/s)", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("QWParaInput", "30", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QWParaInput", "\345\207\240\344\275\225\345\217\202\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("QWParaInput", "\345\215\212\345\276\204R(m)", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("QWParaInput", "1", nullptr));
        label_4->setText(QCoreApplication::translate("QWParaInput", "\351\242\204\350\243\202\347\272\271\350\247\222\345\272\246\316\270", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("QWParaInput", "45", nullptr));
        label_12->setText(QCoreApplication::translate("QWParaInput", "\351\242\204\350\243\202\347\272\271\351\225\277\345\272\246a(m)", nullptr));
        label_13->setText(QCoreApplication::translate("QWParaInput", "\350\257\225\344\273\266\345\216\232\345\272\246t(m)", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("QWParaInput", "0.25", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("QWParaInput", "0.01", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("QWParaInput", "\350\256\241\347\256\227\345\217\202\346\225\260", nullptr));
        label_8->setText(QCoreApplication::translate("QWParaInput", "\346\227\266\351\227\264\346\255\245\346\225\260", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("QWParaInput", "100", nullptr));
        label_14->setText(QCoreApplication::translate("QWParaInput", "x\346\226\271\345\220\221\347\211\251\350\264\250\347\202\271\346\225\260\347\233\256", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("QWParaInput", "40", nullptr));
        label_15->setText(QCoreApplication::translate("QWParaInput", "y\346\226\271\345\220\221\347\211\251\350\264\250\347\202\271\346\225\260\347\233\256", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("QWParaInput", "40", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QWParaInput", "\347\211\251\347\220\206\345\217\202\346\225\260", nullptr));
        label->setText(QCoreApplication::translate("QWParaInput", "\345\274\271\346\200\247\346\250\241\345\236\213\351\207\217E(Pa)", nullptr));
        lineEdit->setText(QCoreApplication::translate("QWParaInput", "192.0e9", nullptr));
        label_6->setText(QCoreApplication::translate("QWParaInput", "\345\257\206\345\272\246(Kg/m3)", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("QWParaInput", "8000", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("QWParaInput", "0.3", nullptr));
        label_2->setText(QCoreApplication::translate("QWParaInput", "\346\263\212\346\235\276\346\257\224n", nullptr));
        label_11->setText(QCoreApplication::translate("QWParaInput", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QWParaInput", "\347\241\256\345\256\232", nullptr));
        pushButton->setText(QCoreApplication::translate("QWParaInput", "\345\217\226\346\266\210", nullptr));
        label_5->setText(QCoreApplication::translate("QWParaInput", "\345\217\202\350\200\203\347\244\272\346\204\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWParaInput: public Ui_QWParaInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWPARAINPUT_H
