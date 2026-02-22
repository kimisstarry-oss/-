/********************************************************************************
** Form generated from reading UI file 'nowsee.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOWSEE_H
#define UI_NOWSEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Nowsee
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QFrame *frame_video;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_start;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_stop;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_capture;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_record;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_status;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_recordTime;

    void setupUi(QWidget *Nowsee)
    {
        if (Nowsee->objectName().isEmpty())
            Nowsee->setObjectName(QString::fromUtf8("Nowsee"));
        Nowsee->resize(1091, 917);
        verticalLayout_2 = new QVBoxLayout(Nowsee);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Nowsee);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        frame_video = new QFrame(Nowsee);
        frame_video->setObjectName(QString::fromUtf8("frame_video"));
        frame_video->setMinimumSize(QSize(640, 480));
        frame_video->setMaximumSize(QSize(640, 480));
        frame_video->setFrameShape(QFrame::StyledPanel);
        frame_video->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_video);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_start = new QPushButton(Nowsee);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));

        horizontalLayout_2->addWidget(pushButton_start);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_stop = new QPushButton(Nowsee);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        horizontalLayout_2->addWidget(pushButton_stop);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_capture = new QPushButton(Nowsee);
        pushButton_capture->setObjectName(QString::fromUtf8("pushButton_capture"));

        horizontalLayout_2->addWidget(pushButton_capture);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_record = new QPushButton(Nowsee);
        pushButton_record->setObjectName(QString::fromUtf8("pushButton_record"));

        horizontalLayout_2->addWidget(pushButton_record);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_status = new QLabel(Nowsee);
        label_status->setObjectName(QString::fromUtf8("label_status"));

        horizontalLayout_3->addWidget(label_status);

        horizontalSpacer_4 = new QSpacerItem(98, 56, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_recordTime = new QLabel(Nowsee);
        label_recordTime->setObjectName(QString::fromUtf8("label_recordTime"));

        horizontalLayout_3->addWidget(label_recordTime);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Nowsee);

        QMetaObject::connectSlotsByName(Nowsee);
    } // setupUi

    void retranslateUi(QWidget *Nowsee)
    {
        Nowsee->setWindowTitle(QCoreApplication::translate("Nowsee", "Form", nullptr));
        label->setText(QString());
        pushButton_start->setText(QCoreApplication::translate("Nowsee", "\345\274\200\345\247\213\346\216\250\346\265\201", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("Nowsee", "\345\201\234\346\255\242\346\216\250\346\265\201", nullptr));
        pushButton_capture->setText(QCoreApplication::translate("Nowsee", "\346\212\223\346\213\215\347\205\247\347\211\207", nullptr));
        pushButton_record->setText(QCoreApplication::translate("Nowsee", "\350\247\206\351\242\221\345\275\225\345\210\266", nullptr));
        label_status->setText(QCoreApplication::translate("Nowsee", "\346\221\204\345\203\217\345\244\264\346\234\252\345\220\257\345\212\250", nullptr));
        label_recordTime->setText(QCoreApplication::translate("Nowsee", "---------------------", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Nowsee: public Ui_Nowsee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOWSEE_H
