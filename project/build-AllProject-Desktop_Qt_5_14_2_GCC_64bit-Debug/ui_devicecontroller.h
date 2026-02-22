/********************************************************************************
** Form generated from reading UI file 'devicecontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICECONTROLLER_H
#define UI_DEVICECONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceController
{
public:
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_led;
    QSlider *horizontalSlider;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox_motor;
    QSlider *horizontalSlider_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_forward;
    QPushButton *pushButton_reverse;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBox_buzzer;

    void setupUi(QWidget *DeviceController)
    {
        if (DeviceController->objectName().isEmpty())
            DeviceController->setObjectName(QString::fromUtf8("DeviceController"));
        DeviceController->resize(984, 936);
        horizontalLayout_6 = new QHBoxLayout(DeviceController);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DeviceController);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 60));
        label->setMaximumSize(QSize(16777215, 60));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));

        horizontalLayout->addWidget(label);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DeviceController);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        checkBox_led = new QCheckBox(DeviceController);
        checkBox_led->setObjectName(QString::fromUtf8("checkBox_led"));
        checkBox_led->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 41, 41);"));

        horizontalLayout_2->addWidget(checkBox_led);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalSlider = new QSlider(DeviceController);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(0, 60));
        horizontalSlider->setMaximumSize(QSize(16777215, 60));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(DeviceController);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        checkBox_motor = new QCheckBox(DeviceController);
        checkBox_motor->setObjectName(QString::fromUtf8("checkBox_motor"));

        horizontalLayout_3->addWidget(checkBox_motor);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalSlider_2 = new QSlider(DeviceController);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setStyleSheet(QString::fromUtf8("color: rgb(52, 101, 164);"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_forward = new QPushButton(DeviceController);
        pushButton_forward->setObjectName(QString::fromUtf8("pushButton_forward"));
        pushButton_forward->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(pushButton_forward);

        pushButton_reverse = new QPushButton(DeviceController);
        pushButton_reverse->setObjectName(QString::fromUtf8("pushButton_reverse"));
        pushButton_reverse->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(pushButton_reverse);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(DeviceController);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        checkBox_buzzer = new QCheckBox(DeviceController);
        checkBox_buzzer->setObjectName(QString::fromUtf8("checkBox_buzzer"));

        horizontalLayout_5->addWidget(checkBox_buzzer);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 1);
        verticalLayout_3->setStretch(3, 1);

        horizontalLayout_6->addLayout(verticalLayout_3);


        retranslateUi(DeviceController);

        QMetaObject::connectSlotsByName(DeviceController);
    } // setupUi

    void retranslateUi(QWidget *DeviceController)
    {
        DeviceController->setWindowTitle(QCoreApplication::translate("DeviceController", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("DeviceController", "LED\347\205\247\346\230\216\347\201\257", nullptr));
        checkBox_led->setText(QString());
        label_3->setText(QCoreApplication::translate("DeviceController", "\347\233\264\346\265\201\347\224\265\346\234\272\346\216\247\345\210\266", nullptr));
        checkBox_motor->setText(QString());
        pushButton_forward->setText(QCoreApplication::translate("DeviceController", "\346\255\243\345\220\221\346\227\213\350\275\254", nullptr));
        pushButton_reverse->setText(QCoreApplication::translate("DeviceController", "\345\217\215\345\220\221\346\227\213\350\275\254", nullptr));
        label_4->setText(QCoreApplication::translate("DeviceController", "\347\264\247\346\200\245\350\234\202\351\270\243\345\231\250\346\212\245\350\255\246", nullptr));
        checkBox_buzzer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DeviceController: public Ui_DeviceController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICECONTROLLER_H
