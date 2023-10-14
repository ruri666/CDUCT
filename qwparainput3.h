#ifndef QWPARAINPUT3_H
#define QWPARAINPUT3_H

#include <QDialog>

namespace Ui {
class QWParaInput3;
}

class QWParaInput3 : public QDialog
{
    Q_OBJECT

public:
    explicit QWParaInput3(QWidget *parent = nullptr);
    ~QWParaInput3();

    QList<float> paraList;
    QString filename;

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::QWParaInput3 *ui;
};

#endif // QWPARAINPUT3_H
