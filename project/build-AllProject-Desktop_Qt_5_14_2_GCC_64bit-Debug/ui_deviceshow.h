/********************************************************************************
** Form generated from reading UI file 'deviceshow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICESHOW_H
#define UI_DEVICESHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceShow
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_temp;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_temp;
    QLabel *label_6;
    QFrame *frame_humi;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_humi;
    QLabel *label_8;
    QFrame *frame_light;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *label_light;
    QLabel *label_10;
    QFrame *frame_ir;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLabel *label_ir;
    QLabel *label_12;

    void setupUi(QWidget *DeviceShow)
    {
        if (DeviceShow->objectName().isEmpty())
            DeviceShow->setObjectName(QString::fromUtf8("DeviceShow"));
        DeviceShow->resize(1401, 310);
        horizontalLayout_2 = new QHBoxLayout(DeviceShow);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_temp = new QFrame(DeviceShow);
        frame_temp->setObjectName(QString::fromUtf8("frame_temp"));
        frame_temp->setFrameShape(QFrame::StyledPanel);
        frame_temp->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_temp);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(frame_temp);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_temp = new QLabel(frame_temp);
        label_temp->setObjectName(QString::fromUtf8("label_temp"));
        label_temp->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 41, 41);"));

        verticalLayout->addWidget(label_temp);

        label_6 = new QLabel(frame_temp);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addWidget(frame_temp);

        frame_humi = new QFrame(DeviceShow);
        frame_humi->setObjectName(QString::fromUtf8("frame_humi"));
        frame_humi->setFrameShape(QFrame::StyledPanel);
        frame_humi->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_humi);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(frame_humi);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_humi = new QLabel(frame_humi);
        label_humi->setObjectName(QString::fromUtf8("label_humi"));
        label_humi->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 41, 41);"));

        verticalLayout_3->addWidget(label_humi);

        label_8 = new QLabel(frame_humi);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);


        verticalLayout_6->addLayout(verticalLayout_3);


        horizontalLayout->addWidget(frame_humi);

        frame_light = new QFrame(DeviceShow);
        frame_light->setObjectName(QString::fromUtf8("frame_light"));
        frame_light->setFrameShape(QFrame::StyledPanel);
        frame_light->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_light);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(frame_light);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        label_light = new QLabel(frame_light);
        label_light->setObjectName(QString::fromUtf8("label_light"));
        label_light->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 41, 41);"));

        verticalLayout_4->addWidget(label_light);

        label_10 = new QLabel(frame_light);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);


        verticalLayout_7->addLayout(verticalLayout_4);


        horizontalLayout->addWidget(frame_light);

        frame_ir = new QFrame(DeviceShow);
        frame_ir->setObjectName(QString::fromUtf8("frame_ir"));
        frame_ir->setFrameShape(QFrame::StyledPanel);
        frame_ir->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_ir);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_4 = new QLabel(frame_ir);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_5->addWidget(label_4);

        label_ir = new QLabel(frame_ir);
        label_ir->setObjectName(QString::fromUtf8("label_ir"));
        label_ir->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 41, 41);"));

        verticalLayout_5->addWidget(label_ir);

        label_12 = new QLabel(frame_ir);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_5->addWidget(label_12);


        verticalLayout_8->addLayout(verticalLayout_5);


        horizontalLayout->addWidget(frame_ir);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(DeviceShow);

        QMetaObject::connectSlotsByName(DeviceShow);
    } // setupUi

    void retranslateUi(QWidget *DeviceShow)
    {
        DeviceShow->setWindowTitle(QCoreApplication::translate("DeviceShow", "Form", nullptr));
        label->setText(QCoreApplication::translate("DeviceShow", "\346\270\251\345\272\246", nullptr));
        label_temp->setText(QString());
        label_6->setText(QCoreApplication::translate("DeviceShow", "\302\260C ", nullptr));
        label_2->setText(QCoreApplication::translate("DeviceShow", "\346\271\277\345\272\246", nullptr));
        label_humi->setText(QString());
        label_8->setText(QCoreApplication::translate("DeviceShow", "%RH", nullptr));
        label_3->setText(QCoreApplication::translate("DeviceShow", "\345\205\211\347\205\247\345\274\272\345\272\246", nullptr));
        label_light->setText(QString());
        label_10->setText(QCoreApplication::translate("DeviceShow", "Lux", nullptr));
        label_4->setText(QCoreApplication::translate("DeviceShow", "\347\272\242\345\244\226\346\243\200\346\265\213", nullptr));
        label_ir->setText(QString());
        label_12->setText(QCoreApplication::translate("DeviceShow", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceShow: public Ui_DeviceShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICESHOW_H
