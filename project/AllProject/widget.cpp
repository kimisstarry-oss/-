#include "widget.h"
#include "ui_widget.h"
#include "serialmanager.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    title = new Title;
    ui->horizontalLayout_title->addWidget(title);

    nowsee = new Nowsee;
    ui->verticalLayout_nowsee->addWidget(nowsee);

    devicecontroller = new DeviceController;
    ui->verticalLayout_devicecontroller->addWidget(devicecontroller);

    deviceshow = new DeviceShow;
    ui->horizontalLayout_show->addWidget(deviceshow);

    SerialManager *serialManager = new SerialManager(this);

    // 连接状态信号
    connect(serialManager, &SerialManager::connectionStatusChanged,
               deviceshow, &DeviceShow::onDeviceConnected);

    systemlog = new SystemLog;
    ui->verticalLayout_systemlog->addWidget(systemlog);
}

Widget::~Widget()
{
    delete ui;
}

