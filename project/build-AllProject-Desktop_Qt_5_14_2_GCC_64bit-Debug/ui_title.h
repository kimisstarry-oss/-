/********************************************************************************
** Form generated from reading UI file 'title.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLE_H
#define UI_TITLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Title
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_title;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_statusIcon;
    QLabel *label_status;

    void setupUi(QWidget *Title)
    {
        if (Title->objectName().isEmpty())
            Title->setObjectName(QString::fromUtf8("Title"));
        Title->resize(1122, 113);
        horizontalLayout_3 = new QHBoxLayout(Title);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_title = new QLabel(Title);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label_title);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_statusIcon = new QLabel(Title);
        label_statusIcon->setObjectName(QString::fromUtf8("label_statusIcon"));
        label_statusIcon->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));

        horizontalLayout->addWidget(label_statusIcon);

        label_status = new QLabel(Title);
        label_status->setObjectName(QString::fromUtf8("label_status"));

        horizontalLayout->addWidget(label_status);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 3);

        horizontalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(Title);

        QMetaObject::connectSlotsByName(Title);
    } // setupUi

    void retranslateUi(QWidget *Title)
    {
        Title->setWindowTitle(QCoreApplication::translate("Title", "Form", nullptr));
        label_title->setText(QCoreApplication::translate("Title", "RK3568  \346\231\272\350\203\275\347\275\221\345\205\263\346\216\247\345\210\266\347\263\273\347\273\237", nullptr));
        label_statusIcon->setText(QString());
        label_status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Title: public Ui_Title {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLE_H
