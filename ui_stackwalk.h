/********************************************************************************
** Form generated from reading UI file 'stackwalk.ui'
**
** Created: Sat Jun 8 20:36:34 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STACKWALK_H
#define UI_STACKWALK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *mapfileBox;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *fileLineEdit;
    QPushButton *openButton;
    QHBoxLayout *horizontalLayout_1;
    QGroupBox *editorBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *clearButton;
    QPushButton *searchButton;
    QGroupBox *previewerBox;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(911, 688);
        Form->setMinimumSize(QSize(0, 0));
        horizontalLayout_4 = new QHBoxLayout(Form);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        mapfileBox = new QGroupBox(Form);
        mapfileBox->setObjectName(QString::fromUtf8("mapfileBox"));
        horizontalLayout_6 = new QHBoxLayout(mapfileBox);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        fileLineEdit = new QLineEdit(mapfileBox);
        fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));

        horizontalLayout_6->addWidget(fileLineEdit);

        openButton = new QPushButton(mapfileBox);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        horizontalLayout_6->addWidget(openButton);


        verticalLayout_2->addWidget(mapfileBox);

        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName(QString::fromUtf8("horizontalLayout_1"));
        editorBox = new QGroupBox(Form);
        editorBox->setObjectName(QString::fromUtf8("editorBox"));
        editorBox->setMaximumSize(QSize(200, 16777215));
        horizontalLayout_2 = new QHBoxLayout(editorBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(editorBox);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setEnabled(true);

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        clearButton = new QPushButton(editorBox);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout_5->addWidget(clearButton);

        searchButton = new QPushButton(editorBox);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        horizontalLayout_5->addWidget(searchButton);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_1->addWidget(editorBox);

        previewerBox = new QGroupBox(Form);
        previewerBox->setObjectName(QString::fromUtf8("previewerBox"));
        horizontalLayout_3 = new QHBoxLayout(previewerBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tableWidget = new QTableWidget(previewerBox);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setColumnCount(5);
        tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_3->addWidget(tableWidget);


        horizontalLayout_1->addWidget(previewerBox);


        verticalLayout_2->addLayout(horizontalLayout_1);


        horizontalLayout_4->addLayout(verticalLayout_2);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        mapfileBox->setTitle(QApplication::translate("Form", "Map File", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("Form", "Open", 0, QApplication::UnicodeUTF8));
        editorBox->setTitle(QApplication::translate("Form", "Adress Stack", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("Form", "Clear", 0, QApplication::UnicodeUTF8));
        searchButton->setText(QApplication::translate("Form", "Walk", 0, QApplication::UnicodeUTF8));
        previewerBox->setTitle(QApplication::translate("Form", "Symbol Stack", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACKWALK_H
