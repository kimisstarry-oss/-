#include "deviceshow.h"
#include "ui_deviceshow.h"
#include <QDebug>

DeviceShow::DeviceShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceShow),
    m_isConnected(false),
    m_temperature(0),
    m_humidity(0),
    m_light(0),
    m_irDetected(false)
{
    ui->setupUi(this);

    // 设置样式
    setupStyles();

    // 初始化定时器
    m_readTimer = new QTimer(this);
    connect(m_readTimer, &QTimer::timeout, this, &DeviceShow::processSerialData);

    // 初始显示
    updateTemperature(0);
    updateHumidity(0);
    updateLight(0);
    updateIR(false);
}

DeviceShow::~DeviceShow()
{
    delete ui;
}

void DeviceShow::setupStyles()
{
    // 整体背景
    this->setStyleSheet("background-color: #f5f5f5;");

    // 数据卡片样式
    QString frameStyle =
            "QFrame {"
            "    background-color: white;"
            "    border: 2px solid #3498db;"
            "    border-radius: 10px;"
            "    padding: 15px;"
            "}";

    ui->frame_temp->setStyleSheet(frameStyle);
    ui->frame_humi->setStyleSheet(frameStyle);
    ui->frame_light->setStyleSheet(frameStyle);
    ui->frame_ir->setStyleSheet(frameStyle);

    // 标题文字样式
    QString titleStyle = "font-size: 18px; font-weight: bold; color: #2c3e50;";
    ui->label->setStyleSheet(titleStyle);
    ui->label_2->setStyleSheet(titleStyle);
    ui->label_3->setStyleSheet(titleStyle);
    ui->label_4->setStyleSheet(titleStyle);

    // 数值样式
    QString valueStyle = "font-size: 24px; font-weight: bold; color: #3498db;";
    ui->label_temp->setStyleSheet(valueStyle);
    ui->label_humi->setStyleSheet(valueStyle);
    ui->label_light->setStyleSheet(valueStyle);
    ui->label_ir->setStyleSheet(valueStyle);

    // 单位样式
    QString unitStyle = "font-size: 16px; color: #7f8c8d;";
    ui->label_6->setStyleSheet(unitStyle);
    ui->label_8->setStyleSheet(unitStyle);
    ui->label_10->setStyleSheet(unitStyle);
}

void DeviceShow::setSerialPort(QSerialPort *serial)
{
    m_serialPort = serial;
    m_isConnected = (serial && serial->isOpen());

    if (m_isConnected) {
        m_readTimer->start(100);  // 每100ms读取一次数据
    } else {
        m_readTimer->stop();
    }
}

void DeviceShow::onDeviceConnected(bool connected)
{
    m_isConnected = connected;

    if (connected && m_serialPort) {
        m_readTimer->start(100);
    } else {
        m_readTimer->stop();
        // 显示断开状态
        updateTemperature(0);
        updateHumidity(0);
        updateLight(0);
        updateIR(false);
    }
}

void DeviceShow::processSerialData()
{
    if (!m_serialPort || !m_serialPort->isOpen()) {
        return;
    }

    // 读取串口数据
    QByteArray data = m_serialPort->readAll();
    if (!data.isEmpty()) {
        parseData(QString::fromUtf8(data));
    }
}

void DeviceShow::parseData(const QString &data)
{
    // 假设数据格式: "T:25.5 H:60 L:850 IR:1"
    // 根据实际STM32发送的数据格式解析

    QStringList parts = data.split(' ');
    foreach (QString part, parts) {
        if (part.startsWith("T:")) {
            float temp = part.mid(2).toFloat();
            updateTemperature(temp);
        }
        else if (part.startsWith("H:")) {
            float humi = part.mid(2).toFloat();
            updateHumidity(humi);
        }
        else if (part.startsWith("L:")) {
            int light = part.mid(2).toInt();
            updateLight(light);
        }
        else if (part.startsWith("IR:")) {
            bool detected = (part.mid(3).toInt() == 1);
            updateIR(detected);
        }
    }
}

void DeviceShow::updateTemperature(float value)
{
    m_temperature = value;
    ui->label_temp->setText(QString::number(value, 'f', 1));
}

void DeviceShow::updateHumidity(float value)
{
    m_humidity = value;
    ui->label_humi->setText(QString::number(value, 'f', 1));
}

void DeviceShow::updateLight(int value)
{
    m_light = value;
    ui->label_light->setText(QString::number(value));
}

void DeviceShow::updateIR(bool detected)
{
    m_irDetected = detected;

    if (detected) {
        ui->label_ir->setText("检测到");
        ui->label_ir->setStyleSheet("font-size: 24px; font-weight: bold; color: #e74c3c;");
    } else {
        ui->label_ir->setText("未检测");
        ui->label_ir->setStyleSheet("font-size: 24px; font-weight: bold; color: #7f8c8d;");
    }
}







