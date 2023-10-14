#ifndef QWPARAINPUT4_H
#define QWPARAINPUT4_H

#include <QDialog>

namespace Ui {
class QWParaInput4;
}

class QWParaInput4 : public QDialog
{
    Q_OBJECT

public:
    explicit QWParaInput4(QWidget *parent = nullptr);
    ~QWParaInput4();

    QList<float> paraList;
    QString filename;

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::QWParaInput4 *ui;
};

#endif // QWPARAINPUT4_H
