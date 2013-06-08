/********************************************************************************
** Form generated from reading UI file 'tablebox.ui'
**
** Created: Sat Jun 8 20:23:47 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEBOX_H
#define UI_TABLEBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableBox
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *stackWalkTab;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *stackWalkLayout;
    QWidget *nameMangleTab;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *nameMangleLayout;

    void setupUi(QWidget *TableBox)
    {
        if (TableBox->objectName().isEmpty())
            TableBox->setObjectName(QString::fromUtf8("TableBox"));
        TableBox->resize(800, 600);
        TableBox->setMinimumSize(QSize(800, 600));
        horizontalLayout_2 = new QHBoxLayout(TableBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        tabWidget = new QTabWidget(TableBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        stackWalkTab = new QWidget();
        stackWalkTab->setObjectName(QString::fromUtf8("stackWalkTab"));
        horizontalLayout_4 = new QHBoxLayout(stackWalkTab);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        stackWalkLayout = new QHBoxLayout();
        stackWalkLayout->setObjectName(QString::fromUtf8("stackWalkLayout"));

        horizontalLayout_4->addLayout(stackWalkLayout);

        tabWidget->addTab(stackWalkTab, QString());
        nameMangleTab = new QWidget();
        nameMangleTab->setObjectName(QString::fromUtf8("nameMangleTab"));
        horizontalLayout_5 = new QHBoxLayout(nameMangleTab);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        nameMangleLayout = new QHBoxLayout();
        nameMangleLayout->setObjectName(QString::fromUtf8("nameMangleLayout"));

        horizontalLayout_5->addLayout(nameMangleLayout);

        tabWidget->addTab(nameMangleTab, QString());

        horizontalLayout->addWidget(tabWidget);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(TableBox);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TableBox);
    } // setupUi

    void retranslateUi(QWidget *TableBox)
    {
        TableBox->setWindowTitle(QApplication::translate("TableBox", "Form", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(stackWalkTab), QApplication::translate("TableBox", "Stack Walk", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(nameMangleTab), QApplication::translate("TableBox", "Name Mangling", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TableBox: public Ui_TableBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEBOX_H
