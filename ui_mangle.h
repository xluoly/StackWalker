/********************************************************************************
** Form generated from reading UI file 'mangle.ui'
**
** Created: Sat Jun 8 20:23:47 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANGLE_H
#define UI_MANGLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MangleForm
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputLineEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *outputLineEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MangleForm)
    {
        if (MangleForm->objectName().isEmpty())
            MangleForm->setObjectName(QString::fromUtf8("MangleForm"));
        MangleForm->resize(644, 545);
        horizontalLayout_2 = new QHBoxLayout(MangleForm);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(MangleForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        inputLineEdit = new QLineEdit(groupBox);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));
        inputLineEdit->setMinimumSize(QSize(0, 50));

        horizontalLayout->addWidget(inputLineEdit);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(MangleForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        outputLineEdit = new QLineEdit(groupBox_2);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));
        outputLineEdit->setMinimumSize(QSize(0, 50));
        outputLineEdit->setReadOnly(true);

        verticalLayout_3->addWidget(outputLineEdit);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(MangleForm);

        QMetaObject::connectSlotsByName(MangleForm);
    } // setupUi

    void retranslateUi(QWidget *MangleForm)
    {
        MangleForm->setWindowTitle(QApplication::translate("MangleForm", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MangleForm", "Decorated Name", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MangleForm", "Undecorated Name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MangleForm: public Ui_MangleForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANGLE_H
