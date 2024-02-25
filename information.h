#ifndef INFORMATION_H
#define INFORMATION_H

#include <QWidget>
#include "qwcalsoftware.h"

namespace Ui {
class information;
}

class information : public QDialog
{
    Q_OBJECT

public:
    explicit information(QWCalSoftware *w, QWidget *parent = nullptr);
    ~information();

private:
    Ui::information *ui;
};

#endif // INFORMATION_H
