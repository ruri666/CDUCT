#ifndef QWCALSOFTWARE_H
#define QWCALSOFTWARE_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QComboBox>
#include <QFile>
#include <QTextStream>
#include <QImage>
#include<QScreen>

#include <iostream>
#include <fstream>
#include <Eigen/Eigen>
#include <Eigen/Sparse>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <omp.h>
#include <windows.h>

#define pi 3.141592653589793
#define g 9.80665

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class QWCalSoftware; }
QT_END_NAMESPACE

class QWCalSoftware : public QMainWindow
{
    Q_OBJECT

public:
    QWCalSoftware(QWidget *parent = nullptr);
    ~QWCalSoftware();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_2_clicked();

    void on_radioButton_clicked(bool checked);

private:
    Ui::QWCalSoftware *ui;

    QLabel *fLabCurFile;
    QComboBox *sortComboBox;
    QList<float> paraL;
    QLabel *label,*label1;
    QImage imageA,imageB,imageC;
    int num;
    int tag1=0,tag2=0; //tag1表示tag2表示
    int proIndex;
    double w,l; //物质点间距
    int screenW,screenH;
    void iniUI();
    void calGMPPD();
    void calEdgeDmg();
    void calCtDmg();
    void calLBoard();
    void paintScatter(int n,QImage &image1,QImage &image2,QImage &image3);

};
#endif // QWCALSOFTWARE_H
