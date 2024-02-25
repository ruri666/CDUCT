#include "information.h"
#include "ui_information.h"


information::information(QWCalSoftware * w, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);
    ui->stackedWidgetIn->setCurrentIndex(w->proIndex);
    QString str = str.number(w->paras[0]);
    switch (w->proIndex)
    {
    case 0:
        ui->data1_1->setText(str);
        str = str.number(w->paras[1]);
        ui->data1_2->setText(str);
        str = str.number(w->paras[2]);
        ui->data1_3->setText(str);
        str = str.number(w->paras[3]);
        ui->data1_4->setText(str);
        str = str.number(w->paras[4]);
        ui->data1_5->setText(str);
        str = str.number(w->paras[5]);
        ui->data1_6->setText(str);
        str = str.number(w->paras[6]);
        ui->data1_7->setText(str);
        str = str.number(w->foot);
        ui->data1_8->setText(str);
        str = str.number(w->paras[7]);
        ui->data1_9->setText(str);
        str = str.number(w->paras[8]);
        ui->data1_10->setText(str);
        str = str.number(w->paras[9]);
        ui->data1_11->setText(str);
        break;
    case 1:
        ui->data2_1->setText(str);
        str = str.number(w->paras[1]);
        ui->data2_2->setText(str);
        str = str.number(w->paras[2]);
        ui->data2_3->setText(str);
        str = str.number(w->paras[3]);
        ui->data2_4->setText(str);
        str = str.number(w->paras[4]);
        ui->data2_5->setText(str);
        str = str.number(w->paras[5]);
        ui->data2_6->setText(str);
        str = str.number(w->paras[6]);
        ui->data2_7->setText(str);
        str = str.number(w->foot);
        ui->data2_8->setText(str);
        str = str.number(w->paras[7]);
        ui->data2_9->setText(str);
        str = str.number(w->paras[8]);
        ui->data2_10->setText(str);
        str = str.number(w->paras[9]);
        ui->data2_11->setText(str);
        break;
    case 2:
        ui->data3_1->setText(str);
        str = str.number(w->paras[1]);
        ui->data3_2->setText(str);
        str = str.number(w->paras[2]);
        ui->data3_3->setText(str);
        str = str.number(w->paras[3]);
        ui->data3_4->setText(str);
        str = str.number(w->paras[4]);
        ui->data3_5->setText(str);
        str = str.number(w->paras[5]);
        ui->data3_6->setText(str);
        str = str.number(w->paras[6]);
        ui->data3_7->setText(str);
        str = str.number(w->foot);
        ui->data3_8->setText(str);
        str = str.number(w->paras[7]);
        ui->data3_9->setText(str);
        str = str.number(w->paras[8]);
        ui->data3_10->setText(str);
        str = str.number(w->paras[9]);
        ui->data3_11->setText(str);
        break;
    case 3:
        ui->data4_1->setText(str);
        str = str.number(w->paras[1]);
        ui->data4_2->setText(str);
        str = str.number(w->paras[2]);
        ui->data4_3->setText(str);
        str = str.number(w->paras[3]);
        ui->data4_4->setText(str);
        str = str.number(w->paras[4]);
        ui->data4_5->setText(str);
        str = str.number(w->paras[5]);
        ui->data4_6->setText(str);
        str = str.number(w->foot);
        ui->data4_7->setText(str);
        str = str.number(w->paras[6]);
        ui->data4_8->setText(str);
        str = str.number(w->paras[7]);
        ui->data4_9->setText(str);
        str = str.number(w->paras[8]);
        ui->data4_10->setText(str);
        break;
    }

}

information::~information()
{
    delete ui;
}




