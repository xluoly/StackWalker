/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/
#include <QtCore>
#include <QtGui>
#include "stackwalk.h"
#include "mapfile.h"
#include "imagehlp.h"

StackWalk::StackWalk(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    tableWidget->setHorizontalHeaderLabels(QStringList()
                                           << tr("Address")
                                           << tr("Base")
                                           << tr("Offset")
                                           << tr("Symbol")
                                           << tr("Module"));
    QHeaderView *header = tableWidget->horizontalHeader();
    header->setResizeMode(QHeaderView::ResizeToContents);

    fileLineEdit->setText(tr("Select a MAP file."));
}

void StackWalk::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    m_dir,
                                                    tr("Map File (*.map)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }
        loadMapFile(fileName);
    }
}

void StackWalk::loadMapFile(const QString &filePath)
{
    if (m_mapfile.load(filePath))
    {
        fileLineEdit->setText(filePath);
        QFileInfo info(filePath);
        m_dir = info.absolutePath();

        while (tableWidget->rowCount() > 0)
        {
            tableWidget->removeRow(0);
        }
    }
    else
    {
        fileLineEdit->setText(tr("Select a MAP file."));
    }
}

void StackWalk::on_clearButton_clicked()
{
    plainTextEdit->clear();
}

void StackWalk::on_searchButton_clicked()
{
    char unDecorateName[512] = {0};
    QString text = plainTextEdit->toPlainText();
    QStringList list = text.split("\n");
    if (list.isEmpty())
        return;

    if (m_mapfile.isValid())
    {
        tableWidget->clearContents();
        tableWidget->insertRow(list.count());
        int row = 0;
        foreach(const QString &address, list)
        {
            const int addr = address.toInt(NULL, 16);
            PMAPSYMBOL symbol = m_mapfile.lookupSymbol(addr);
            //qDebug()<<address<<symbol;
            if (symbol && UnDecorateSymbolName(symbol->name,
                                     unDecorateName,
                                     sizeof(unDecorateName),
                                     UNDNAME_COMPLETE))
            {
                if (row >= tableWidget->rowCount())
                {
                    tableWidget->insertRow(row);
                }
                tableWidget->setItem(row, 0, new QTableWidgetItem(address));
                tableWidget->setItem(row, 1, new QTableWidgetItem(QString().sprintf("%08x", symbol->address)));
                tableWidget->setItem(row, 2, new QTableWidgetItem(QString().sprintf("%08x", addr - symbol->address)));
                tableWidget->setItem(row, 3, new QTableWidgetItem(unDecorateName));
                tableWidget->setItem(row, 4, new QTableWidgetItem(symbol->module));
                ++row;
            }
        }

        while (tableWidget->rowCount() > row)
        {
            tableWidget->removeRow(row);
        }
    }
}

void StackWalk::on_fileLineEdit_returnPressed()
{
    loadMapFile(fileLineEdit->text());
}
