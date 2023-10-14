#ifndef QWPARAINPUT2_H
#define QWPARAINPUT2_H

#include <iostream>
#include <QDialog>

namespace Ui {
class QWParaInput2;
}

class QWParaInput2 : public QDialog
{
    Q_OBJECT

public:
    explicit QWParaInput2(QWidget *parent = nullptr);
    ~QWParaInput2();

    QList<float> paraList;
    QString filename;

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::QWParaInput2 *ui;
};

#endif // QWPARAINPUT2_H
