#include "qwparainput2.h"
#include "ui_qwparainput2.h"

QWParaInput2::QWParaInput2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWParaInput2)
{
    ui->setupUi(this);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QString filename("F:\\Qt Widgets\\QWCalSoftware\\imgs\\模型2.png");
    QImage* img=new QImage;
    img->load(filename);
    ui->label_11->setPixmap(QPixmap::fromImage(*img));
    ui->label_11->setGeometry(400,10,250,280);
    ui->label_11->setScaledContents(true);
}

QWParaInput2::~QWParaInput2()
{
    delete ui;
}

void QWParaInput2::on_pushButton_2_clicked()
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

    str = ui->lineEdit_8->text();
    list.append(str.toFloat());

    str = ui->lineEdit_9->text();
    list.append(str.toFloat());

    str = ui->lineEdit_10->text();
    list.append(str.toFloat());

    str = ui->lineEdit_11->text();
    list.append(str.toFloat());

    std::cout<<list[0]<<list[1]<<list[2]<<list[3]<<list[4]<<list[5]<<list[6]<<list[7]<<list[8]<<list[9]<<list[10]<<list[11]<<list[12]<<std::endl;
    paraList = list;
}

