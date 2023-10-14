#ifndef QWPARAINPUT_H
#define QWPARAINPUT_H

#include<iostream>
#include <QDialog>
#include <QString>
#include <QList>

namespace Ui {
class QWParaInput;
}

class QWParaInput : public QDialog
{
    Q_OBJECT

public:
    explicit QWParaInput(QWidget *parent = nullptr);
    ~QWParaInput();

    QList<float> paraList;
    QString filename;

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::QWParaInput *ui;
};

#endif // QWPARAINPUT_H
