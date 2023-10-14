#include "qwparainput4.h"
#include "ui_qwparainput4.h"

QWParaInput4::QWParaInput4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWParaInput4)
{
    ui->setupUi(this);

    QString filename("F:\\Qt Widgets\\QWCalSoftware\\imgs\\模型4.png");
    QImage* img=new QImage;
    img->load(filename);
    ui->label_11->setPixmap(QPixmap::fromImage(*img));
    ui->label_11->setGeometry(400,20,250,280);
    ui->label_11->setScaledContents(true);
}

QWParaInput4::~QWParaInput4()
{
    delete ui;
}

void QWParaInput4::on_pushButton_2_clicked()
{
    QList<float> list;
    QString str = ui->lineEdit->text();
    list.append(str.toFloat());

    str = ui->lineEdit_2->text();
    list.append(str.toFloat());

    str = ui->lineEdit_3->text();
    list.append(str.toFloat());

    str = ui->lineEdit_4->text();
    list.append(str.toFloat());

    str = ui->lineEdit_5->text();
    list.append(str.toFloat());

    str = ui->lineEdit_6->text();
    list.append(str.toFloat());

    str = ui->lineEdit_7->text();
    list.append(str.toFloat());

    str = ui->lineEdit_7->text();
    list.append(str.toFloat());

    str = ui->lineEdit_8->text();
    list.append(str.toFloat());

    str = ui->lineEdit_8->text();
    list.append(str.toFloat());

    str = ui->lineEdit_9->text();
    list.append(str.toFloat());

    str = ui->lineEdit_10->text();
    list.append(str.toFloat());

    //    std::cout<<list[0]<<list[4]<<list[8]<<std::endl;
    paraList = list;
}

