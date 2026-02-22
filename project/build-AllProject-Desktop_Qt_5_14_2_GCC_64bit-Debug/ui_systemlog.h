/********************************************************************************
** Form generated from reading UI file 'systemlog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMLOG_H
#define UI_SYSTEMLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemLog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;

    void setupUi(QWidget *SystemLog)
    {
        if (SystemLog->objectName().isEmpty())
            SystemLog->setObjectName(QString::fromUtf8("SystemLog"));
        SystemLog->resize(614, 485);
        horizontalLayout = new QHBoxLayout(SystemLog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(SystemLog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(SystemLog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(SystemLog);

        QMetaObject::connectSlotsByName(SystemLog);
    } // setupUi

    void retranslateUi(QWidget *SystemLog)
    {
        SystemLog->setWindowTitle(QCoreApplication::translate("SystemLog", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SystemLog: public Ui_SystemLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMLOG_H
