#ifndef MANGLE_H
#define MANGLE_H

#include <QWidget>
#include "ui_mangle.h"

class Mangle : public QWidget, public Ui::MangleForm
{
    Q_OBJECT
public:
    Mangle(QWidget *parent = 0);

protected slots:
    void on_inputLineEdit_textChanged(const QString &text);
};

#endif // MANGLE_H
