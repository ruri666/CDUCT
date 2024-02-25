#ifndef QWCALSOFTWARE_H
#define QWCALSOFTWARE_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QProgressDialog> //进度条
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
#include <QMouseEvent>




const double pi =  3.141592653589793;
const double g = 9.80665;

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class QWCalSoftware; }
QT_END_NAMESPACE

#define PADDING 2
enum Direction { UP=0, DOWN=1, LEFT, RIGHT, LEFTTOP, LEFTBOTTOM, RIGHTBOTTOM, RIGHTTOP, NONE };//鼠标拖动窗口方向

class QWCalSoftware : public QMainWindow
{
    Q_OBJECT


public:
    QWCalSoftware(QWidget *parent = nullptr);
    ~QWCalSoftware();
    friend class information;

private:
    QString borderColor;
    QString normalBgColor;
    QString darkBgColor;
    QString normalTextColor;
    QString darkTextColor;

    void getQssColor(const QString &qss, const QString &flag, QString &color);
    void getQssColor(const QString &qss, QString &textColor,
                     QString &panelColor, QString &borderColor,
                     QString &normalColorStart, QString &normalColorEnd,
                     QString &darkColorStart, QString &darkColorEnd,
                     QString &highColor);

private:
    int foot;
    QString filePath;

    QImage img1,img2,img3;
    QList<float> paras;

    QList<int> iconsCons;
    QList<QAbstractButton *> btnsCons;

    QList<int> iconsCal;
    QList<QAbstractButton *> btnsCal;

    QList<int> iconsShow;
    QList<QAbstractButton *> btnsShow;


private slots:
    void initForm();
    void initStyle();
    void buttonClick();

    void initLeftCons();
    void initLeftCal();
    void initLeftShow();
    void leftConsClick();
    void leftRoadClick();
    void leftCalClick();
    void leftShowClick();

private slots:
    void on_btnLoad1_clicked();
    void on_btnLoad2_clicked();
    void on_btnLoad3_clicked();
    void on_btnLoad4_clicked();
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
    void on_Slider_valueChanged(int value);

    void on_tbtnShow4_clicked();

private:
    Ui::QWCalSoftware *ui;

    int num;
    int proIndex; //区分不同的算例的
    double w,l; //物质点间距
    bool IfPathChoose = false;//判断有没有先选择文件路径

  private:
    void calGMPPD();
    void calEdgeDmg();
    void calCtDmg();
    void calLBoard();
    void paintScatter(int n);
    void EndForCal();

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint m_dragPosition;

};
#endif // QWCALSOFTWARE_H
