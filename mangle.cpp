#include <QtCore>
#include <QtGui>
#include "mangle.h"
#include <Windows.h>
#include "imagehlp.h"

Mangle::Mangle(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
}

void Mangle::on_inputLineEdit_textChanged(const QString &text)
{
    if (!text.isEmpty())
    {
        char unDecorateName[512] = {0};
        if (UnDecorateSymbolName(text.toStdString().c_str(),
                                 unDecorateName,
                                 sizeof(unDecorateName),
                                 UNDNAME_COMPLETE))
        {
            outputLineEdit->setText(QString(unDecorateName));
        }
    }
    else
    {
        outputLineEdit->clear();
    }
}
