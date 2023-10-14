#include "qwparainput5.h"
#include "ui_qwparainput5.h"

QWParaInput5::QWParaInput5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWParaInput5)
{
    ui->setupUi(this);

    QString filename("F:\\Qt Widgets\\QWCalSoftware\\imgs\\模型5.png");
    QImage* img=new QImage;
    img->load(filename);
    ui->label_11->setPixmap(QPixmap::fromImage(*img));
    ui->label_11->setGeometry(400,25,250,290);
}

QWParaInput5::~QWParaInput5()
{
    delete ui;
}
