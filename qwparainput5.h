#ifndef QWPARAINPUT5_H
#define QWPARAINPUT5_H

#include <QDialog>

namespace Ui {
class QWParaInput5;
}

class QWParaInput5 : public QDialog
{
    Q_OBJECT

public:
    explicit QWParaInput5(QWidget *parent = nullptr);
    ~QWParaInput5();

    QList<float> paraList;
    QString filename;

private:
    Ui::QWParaInput5 *ui;
};

#endif // QWPARAINPUT5_H
