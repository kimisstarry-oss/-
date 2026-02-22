/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_title;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_nowsee;
    QHBoxLayout *horizontalLayout_show;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_devicecontroller;
    QVBoxLayout *verticalLayout_systemlog;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1401, 1066);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_title = new QHBoxLayout();
        horizontalLayout_title->setSpacing(0);
        horizontalLayout_title->setObjectName(QString::fromUtf8("horizontalLayout_title"));

        verticalLayout_6->addLayout(horizontalLayout_title);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_nowsee = new QVBoxLayout();
        verticalLayout_nowsee->setObjectName(QString::fromUtf8("verticalLayout_nowsee"));

        verticalLayout_4->addLayout(verticalLayout_nowsee);

        horizontalLayout_show = new QHBoxLayout();
        horizontalLayout_show->setObjectName(QString::fromUtf8("horizontalLayout_show"));

        verticalLayout_4->addLayout(horizontalLayout_show);

        verticalLayout_4->setStretch(0, 5);
        verticalLayout_4->setStretch(1, 2);

        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_devicecontroller = new QVBoxLayout();
        verticalLayout_devicecontroller->setObjectName(QString::fromUtf8("verticalLayout_devicecontroller"));

        verticalLayout_5->addLayout(verticalLayout_devicecontroller);

        verticalLayout_systemlog = new QVBoxLayout();
        verticalLayout_systemlog->setObjectName(QString::fromUtf8("verticalLayout_systemlog"));

        verticalLayout_5->addLayout(verticalLayout_systemlog);

        verticalLayout_5->setStretch(0, 3);
        verticalLayout_5->setStretch(1, 2);

        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 2);

        verticalLayout_6->addLayout(horizontalLayout_2);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 7);

        verticalLayout->addLayout(verticalLayout_6);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
